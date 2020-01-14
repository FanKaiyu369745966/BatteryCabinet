#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initWindow()
{
    // 窗口背景
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, QColor("#2D3035"));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    // 窗口初始尺寸
    this->resize(QSize(1600, 900));
    this->setFixedSize(this->width(),this->height());

    // 窗口标题栏
    setWindowIcon(QIcon("./res/icon/sys.png"));
    setWindowTitle(QString::fromLocal8Bit("电池管理系统"));
    setWindowFlags(Qt::CustomizeWindowHint | Qt::Window | Qt::FramelessWindowHint);
    TitleBarEx *pTitleBar = new TitleBarEx(this);
    pTitleBar->setIcon("./res/icon/main.png");
    pTitleBar->setButtonType(MINI_MAX_BUTTON);
    pTitleBar->setTitle(QString::fromLocal8Bit("  电池管理系统"));
    connect(pTitleBar, SIGNAL(windowClose()), this, SLOT(onWindowClose()));


    // 主页
    ui->tabWidget->setTabPosition(QTabWidget::West);
    ui->tabWidget->tabBar()->setStyle(new CustomTabStyle);
    BatteryLogForm *batteryLogForm = new BatteryLogForm();
    ui->tabWidget->addTab(batteryLogForm, QString::fromLocal8Bit("电池日志"));
    BatteryCabinetForm *batteryCabinetForm = new BatteryCabinetForm();
    ui->tabWidget->addTab(batteryCabinetForm, QString::fromLocal8Bit("电池柜  "));
    BatteryBoxForm *batteryBoxForm = new BatteryBoxForm();
    ui->tabWidget->addTab(batteryBoxForm, QString::fromLocal8Bit("电池盒  "));
    ui->tabWidget->setCurrentIndex(0);


//    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");
//    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
//                               "SERVER=%1;"
//                               "DATABASE=%2;"
//                               "UID=%3;"
//                               "PWD=%4;").arg("192.168.1.179").arg("BatteryDB").arg("sa").arg("admin"));

    linkdb();
}

void MainWindow::onWindowClose()
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    connect(msgBox, SIGNAL(btnOkClicked()), this, SLOT(onBtnOkClicked()));
    connect(msgBox, SIGNAL(btnCancelClicked()), this, SLOT(onBtnCancelClicked()));
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("确定要退出系统吗？"), "", MsgBoxBtnType::MsgBoxBtnType_OkCancle);
    delete msgBox;
}

void MainWindow::onBtnOkClicked()
{
    qApp->quit();
}

void MainWindow::onBtnCancelClicked(){}

bool MainWindow::linkdb()
{
    Config config("./res/set/config.ini");
    QString serverName = config.get("DataBase", "ServerName").toString();
    QString databaseName = config.get("DataBase", "DataBaseName").toString();
    QString loginName = config.get("DataBase", "LoginName").toString();
    QString passwd = config.get("DataBase", "Passwd").toString();

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC3");
    db.setDatabaseName(QString("DRIVER={SQL SERVER};"
                               "SERVER=%1;"
                               "DATABASE=%2;"
                               "UID=%3;"
                               "PWD=%4;").arg(serverName).arg(databaseName).arg(loginName).arg(passwd));
    if (!db.open())
    {
        return false;
    }
    return true;
}
