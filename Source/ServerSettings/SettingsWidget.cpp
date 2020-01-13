#include "SettingsWidget.h"
#include <QLayout>
#include <QMessageBox>

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

	return;
}

void SettingsWidget::onClickButtonRestart(bool bClicked)
{
	// TODO 重启服务端程序 
	return;
}

void SettingsWidget::onClickButtonSumbit(bool bClicked)
{
	if (m_dbSettings->IsTested() == false)
	{
		QMessageBox::information(this, QString::fromLocal8Bit("提交修改"), QString::fromLocal8Bit("提交失败。原因:数据库连接未经过测试。"));

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
	server.setAttribute("IP", );
	server.setAttribute("Port", );

	QMessageBox::information(this, QString::fromLocal8Bit("提交修改"), QString::fromLocal8Bit("修改已经提交，重启服务端后生效。"));

	return;
}
