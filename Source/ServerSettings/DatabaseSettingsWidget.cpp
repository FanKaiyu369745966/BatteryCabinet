#include "DatabaseSettingsWidget.h"
#include <QtSql/QSqlError>
#include <QMessageBox>	
#include <QIcon>
#include <QLayout>

DatabaseSettingsWidget::DatabaseSettingsWidget(QWidget* parent)
	: QWidget(parent)
	, m_db(QSqlDatabase::addDatabase("QODBC3"))
	, m_editHost(nullptr)
	, m_editName(nullptr)
	, m_editUser(nullptr)
	, m_editPassword(nullptr)
	, m_bTested(false)
{
	//ui.setupUi(this);
	Initialize();
}

DatabaseSettingsWidget::~DatabaseSettingsWidget()
{
}

void DatabaseSettingsWidget::Initialize()
{
	QPushButton* _butTest = new QPushButton(QString::fromLocal8Bit("测试连接"), this);
	//QPushButton* _butSubmit = new QPushButton(QString::fromLocal8Bit("设置"), this);

	_butTest->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
	//_butSubmit->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);

	//m_labConn = new QLabel(this);
	QLabel* _labDBHost = new QLabel(QString::fromLocal8Bit("数据库主机名:"), this);
	QLabel* _labDBName = new QLabel(QString::fromLocal8Bit("数据库名:"), this);
	QLabel* _labDBUser = new QLabel(QString::fromLocal8Bit("用户名:"), this);
	QLabel* _labDBPassword = new QLabel(QString::fromLocal8Bit("密码:"), this);

	_labDBHost->setAlignment(Qt::AlignRight | Qt::AlignHCenter | Qt::AlignVCenter);
	_labDBName->setAlignment(Qt::AlignRight | Qt::AlignHCenter | Qt::AlignVCenter);
	_labDBUser->setAlignment(Qt::AlignRight | Qt::AlignHCenter | Qt::AlignVCenter);
	_labDBPassword->setAlignment(Qt::AlignRight | Qt::AlignHCenter | Qt::AlignVCenter);

	m_editHost = new QLineEdit(this);
	m_editName = new QLineEdit(this);
	m_editUser = new QLineEdit(this);
	m_editPassword = new QLineEdit(this);
	// 当你处于输入状态的时候，是正常显示字符。 输入完毕之后使用Password形式隐藏字符
	m_editPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);

	m_editHost->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	m_editName->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	m_editUser->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	m_editPassword->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	QToolButton* _checkPassword = new QToolButton(this);
	_checkPassword->setCheckable(true);
	_checkPassword->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);

	QObject::connect(_butTest, &QPushButton::clicked, this, &DatabaseSettingsWidget::onClickButtonTest);
	//QObject::connect(_butSubmit, &QPushButton::clicked, this, &DatabaseSettingsWidget::onClickButtonSumbit);
	QObject::connect(_checkPassword, &QToolButton::clicked, this, &DatabaseSettingsWidget::onClickCheckPassword);
	QObject::connect(m_editHost, &QLineEdit::textChanged, this, &DatabaseSettingsWidget::onEditTextChanged);
	QObject::connect(m_editName, &QLineEdit::textChanged, this, &DatabaseSettingsWidget::onEditTextChanged);
	QObject::connect(m_editUser, &QLineEdit::textChanged, this, &DatabaseSettingsWidget::onEditTextChanged);
	QObject::connect(m_editPassword, &QLineEdit::textChanged, this, &DatabaseSettingsWidget::onEditTextChanged);

	// 控件排列
	QHBoxLayout* _hlayoutBut = new QHBoxLayout();
	_hlayoutBut->addWidget(_butTest);
	//_hlayoutBut->addWidget(_butSubmit);

	QHBoxLayout* _hlayoutPswd = new QHBoxLayout();
	_hlayoutPswd->addWidget(m_editPassword);
	_hlayoutPswd->addWidget(_checkPassword);

	QVBoxLayout* _vlayoutLabel = new QVBoxLayout();
	_vlayoutLabel->addWidget(_labDBHost);
	_vlayoutLabel->addWidget(_labDBName);
	_vlayoutLabel->addWidget(_labDBUser);
	_vlayoutLabel->addWidget(_labDBPassword);

	QVBoxLayout* _vlayoutEdit = new QVBoxLayout();
	_vlayoutEdit->addWidget(m_editHost);
	_vlayoutEdit->addWidget(m_editName);
	_vlayoutEdit->addWidget(m_editUser);
	_vlayoutEdit->addLayout(_hlayoutPswd);

	QGridLayout* _glayout = new QGridLayout();
	_glayout->addLayout(_vlayoutLabel, 0, 0, 2, 1);
	_glayout->addLayout(_vlayoutEdit, 0, 1, 2, 1);
	_glayout->addLayout(_hlayoutBut, 2, 0, 1, 2);

	setLayout(_glayout);

	//setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	return;
}

void DatabaseSettingsWidget::SetDefaultHost(const QString& host)
{
	m_strHost = host;

	if (m_editHost == nullptr)
	{
		return;
	}

	m_editHost->setText(m_strHost);

	return;
}

void DatabaseSettingsWidget::SetDefaultName(const QString& name)
{
	m_strName = name;

	if (m_editName == nullptr)
	{
		return;
	}

	m_editName->setText(m_strName);

	return;
}

void DatabaseSettingsWidget::SetDefaultUser(const QString& user)
{
	m_strUser = user;

	if (m_editUser == nullptr)
	{
		return;
	}

	m_editUser->setText(m_strUser);

	return;
}

void DatabaseSettingsWidget::SetDefaultPassword(const QString& password)
{
	m_strPassword = password;

	if (m_editPassword == nullptr)
	{
		return;
	}

	m_editPassword->setText(m_strPassword);

	return;
}

void DatabaseSettingsWidget::onClickButtonTest(bool bClicked)
{
	QString host = "", name = "", user = "", password = "";

	// TODO 获取输入框中的信息
	host = m_editHost->text();
	name = m_editName->text();
	user = m_editUser->text();
	password = m_editPassword->text();

	if (host.isNull() || host.isEmpty()
		)
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请填写数据库主机名"));
		return;
	}

	if (name.isNull() || name.isEmpty())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请填写数据库名称"));
		return;
	}

	if (user.isNull() || user.isEmpty())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请填写用户名"));
		return;
	}

	if (password.isNull() || password.isEmpty())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请填写密码"));
		return;
	}

	m_db.setDatabaseName(QString("DRIVER={SQL SERVER};"
		"SERVER=%1;"
		"DATABASE=%2;"
		"UID=%3;"
		"PWD=%4;").arg(host).arg(name).arg(user).arg(password));

	if (m_db.open())
	{
		//m_labConn->setText(QString::fromLocal8Bit("连接成功"));
		QMessageBox::information(this, QString::fromLocal8Bit("测试连接"), QString::fromLocal8Bit("连接成功"));

		m_strHost = host;
		m_strName = name;
		m_strUser = user;
		m_strPassword = password;

		m_bTested = true;
	}
	else
	{
		//m_labConn->setText(QString::fromLocal8Bit("连接失败。原因:%1").arg(m_db.lastError().text()));
		QMessageBox::critical(this, QString::fromLocal8Bit("测试连接"), QString::fromLocal8Bit("连接失败。原因:%1").arg(m_db.lastError().text()));

		m_bTested = false;
	}

	m_db.close();

	return;
}

void DatabaseSettingsWidget::onClickCheckPassword(bool bClicked)
{
	if (m_editPassword == nullptr)
	{
		return;
	}

	if (bClicked)
	{
		m_editPassword->setEchoMode(QLineEdit::Normal);
	}
	else
	{
		m_editPassword->setEchoMode(QLineEdit::PasswordEchoOnEdit);
	}

	return;
}

void DatabaseSettingsWidget::onClickButtonSumbit(bool bClicked)
{
	if (m_strHost.isNull() || m_strHost.isEmpty()
		)
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置数据库主机名"));
		return;
	}

	if (m_strName.isNull() || m_strName.isEmpty())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置数据库名称"));
		return;
	}

	if (m_strUser.isNull() || m_strUser.isEmpty())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置用户名"));
		return;
	}

	if (m_strPassword.isNull() || m_strPassword.isEmpty())
	{
		QMessageBox::critical(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未设置密码"));
		return;
	}

	if (m_bTested == false)
	{
		onClickButtonTest();
	}

	if (m_bTested)
	{
		//emit Submited();
	}

	return;
}

void DatabaseSettingsWidget::onEditTextChanged(const QString& text)
{
	m_bTested = false;

	return;
}
