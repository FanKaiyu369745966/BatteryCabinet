#include "SettingsWidget.h"
#include <QLayout>
#include <QMessageBox>
#include <QtNetwork/QHostAddress>
#include <QSharedMemory>
//#include "tlhelp32.h"

SettingsWidget::SettingsWidget(QWidget* parent)
	: QWidget(parent)
	, m_dbSettings(nullptr)
	, m_netSettings(nullptr)
{
	//ui.setupUi(this);
	Initialize();
}

void SettingsWidget::Initialize()
{
	setWindowTitle(QString::fromLocal8Bit("电池柜服务端配置"));

	QVBoxLayout* _vlayout = new QVBoxLayout();

	QTabWidget* _tab = new QTabWidget(this);
	m_dbSettings = new DatabaseSettingsWidget(this);
	m_netSettings = new NetSettingsWidget(this);

	QPushButton* _butSubmit = new QPushButton(QString::fromLocal8Bit("提交修改"), this);
	QPushButton* _butRestart = new QPushButton(QString::fromLocal8Bit("重启服务端"), this);

	QObject::connect(_butSubmit, &QPushButton::clicked, this, &SettingsWidget::onClickButtonSumbit);
	QObject::connect(_butRestart, &QPushButton::clicked, this, &SettingsWidget::onClickButtonRestart);

	QVBoxLayout* _vlayoutNet = new QVBoxLayout();
	_vlayoutNet->addStretch();
	_vlayoutNet->addWidget(_butSubmit);
	_vlayoutNet->addStretch();
	_vlayoutNet->addWidget(_butRestart);
	_vlayoutNet->addStretch();

	QWidget* w = new QWidget(this);
	w->setLayout(_vlayoutNet);

	_tab->addTab(m_dbSettings, QString::fromLocal8Bit("数据库"));
	_tab->addTab(m_netSettings, QString::fromLocal8Bit("网络"));
	_tab->addTab(w, QString::fromLocal8Bit("系统"));

	_tab->setTabPosition(QTabWidget::West);

	_vlayout->addWidget(_tab);
	setLayout(_vlayout);

	Load();

	return;
}

void SettingsWidget::Load()
{
	QFile file("Config/config.xml");
	if (!file.open(QFile::ReadOnly))
	{
		return;
	}

	QDomDocument doc;
	QString strError;
	if (!doc.setContent(&file, &strError))
	{
		qDebug() << strError << endl;
		file.close();
		return;
	}

	file.close();

	QDomElement root = doc.documentElement(); //返回根节点

	QDomNode node = root.firstChild(); //获得第一个子节点

	while (!node.isNull())  //如果节点不空
	{
		if (node.isElement()) //如果节点是元素
		{
			QDomElement e = node.toElement(); //转换为元素，注意元素和节点是两个数据结构，其实差不多

			QString name = e.tagName();

			if (name == "Database")
			{
				QString serverName = e.attribute("Host");
				QString databaseName = e.attribute("Name");
				QString loginName = e.attribute("User");
				QString passwd = e.attribute("Password");

				m_dbSettings->SetDefaultHost(serverName);
				m_dbSettings->SetDefaultName(databaseName);
				m_dbSettings->SetDefaultUser(loginName);
				m_dbSettings->SetDefaultPassword(passwd);
			}
			else if (name == "Server")
			{
				QString ip = e.attribute("IP");
				QString port = e.attribute("Port");

				m_netSettings->SetIp(ip);
				m_netSettings->SetPort(port.toInt());
			}
		}

		node = node.nextSibling(); //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
	}

	return;
}

void SettingsWidget::onClickButtonRestart(bool bClicked)
{
	// TODO 重启服务端程序

	//Qt开源库， 通过QProcess启动系统命令“tasklist.exe”, 获取正在运行的进程
	QProcess process;
	// notepad.exe 为需要关闭的进程名
	QString c = "taskkill /im BatteryCabinetServer.exe /f";
	process.execute(c);
	process.close();

	QProcess::startDetached("BatteryCabinetServer.exe", QStringList());

	return;
}

void SettingsWidget::onClickButtonSumbit(bool bClicked)
{
	if (m_dbSettings->IsTested() == false)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提交修改"), QString::fromLocal8Bit("提交失败。原因:数据库连接未经过测试。"));

		return;
	}

	QHostAddress addr(m_netSettings->ip());

	if (addr.toIPv4Address() == 0)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提交修改"), QString::fromLocal8Bit("提交失败。原因:网络IP地址不是一个有效的IPV4地址。"));

		return;
	}

	// TODO 生成配置文件
	QDomDocument doc;
	//写入xml头部
	QDomProcessingInstruction instruction; //添加处理命令
	instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
	doc.appendChild(instruction);
	//添加根节点
	QDomElement root = doc.createElement("config");
	doc.appendChild(root);
	//添加第一个子节点及其子元素
	QDomElement db = doc.createElement("Database");
	db.setAttribute("Host", m_dbSettings->host());
	db.setAttribute("Name", m_dbSettings->name());
	db.setAttribute("User", m_dbSettings->user());
	db.setAttribute("Password", m_dbSettings->password());

	QDomElement server = doc.createElement("Server");
	server.setAttribute("IP", m_netSettings->ip());
	server.setAttribute("Port", m_netSettings->port());

	root.appendChild(db);
	root.appendChild(server);

	//打开或创建文件
	QString path = "Config";
	QDir dir; //相对路径、绝对路径、资源路径都可以
	if (dir.exists(path) == false && dir.mkpath(path) == false)
	{
		return;
	}

	path = "Config/config.xml";

	QFile file(path);

	if (!file.open(QFile::WriteOnly | QFile::Truncate)) //可以用QIODevice，Truncate表示清空原来的内容
	{
		return;
	}

	//输出到文件
	QTextStream out_stream(&file);
	doc.save(out_stream, 4); //缩进4格
	file.close();

	QMessageBox::information(this, QString::fromLocal8Bit("提交修改"), QString::fromLocal8Bit("修改已经提交，重启服务端后生效。"));

	return;
}
