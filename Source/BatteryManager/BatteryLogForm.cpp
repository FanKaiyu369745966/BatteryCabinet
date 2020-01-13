#include "BatteryLogForm.h"
#include "ui_BatteryLogForm.h"

BatteryLogForm::BatteryLogForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatteryLogForm)
{
    ui->setupUi(this);

    // 背景
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, QColor("#2D3035"));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    ui->groupBox->setTitle(QString::fromLocal8Bit("电池日志信息"));

    // 日志类型
    ui->comboBoxLogType->addItem(QString::fromLocal8Bit(""));
    ui->comboBoxLogType->addItem(QString::fromLocal8Bit("异常"));
    ui->comboBoxLogType->addItem(QString::fromLocal8Bit("发送"));
    ui->comboBoxLogType->addItem(QString::fromLocal8Bit("接收"));
    ui->comboBoxLogType->addItem(QString::fromLocal8Bit("日志"));
    ui->comboBoxLogType->setCurrentIndex(-1);


    // 日期格式提示
    QDate date = QDate::currentDate();
    QString currentDate = QString("%1-%2-%3").arg(date.year(), 4, 10, QChar('0')).arg(date.month(), 2, 10, QChar('0')).arg(date.day(), 2, 10, QChar('0'));
    ui->lineEditDate->setPlaceholderText(currentDate);
    QRegExp rx("^((?!0000)[0-9]{4}-((0[1-9]|1[0-2])-(0[1-9]|1[0-9]|2[0-8])|(0[13-9]|1[0-2])-(29|30)|(0[13578]|1[02])-31)|\
               ([0-9]{2}(0[48]|[2468][048]|[13579][26])|(0[48]|[2468][048]|[13579][26])00)-02-29)$");
            ui->lineEditDate->setValidator(new QRegExpValidator(rx, this));

    // 列表
    initTableView();
}

BatteryLogForm::~BatteryLogForm()
{
    delete ui;
}

/**
 * @brief initTableView 初始化列表
 */
void BatteryLogForm::initTableView()
{
    m_model = new QStandardItemModel(this);
    m_model->setColumnCount(7);
    m_model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("发布时间"));
    m_model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("类型"));
    m_model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("通信地址"));
    m_model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("电池柜编号"));
    m_model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("电池盒编号"));
    m_model->setHeaderData(6, Qt::Horizontal, QString::fromLocal8Bit("详细信息"));
    ui->tableView->setModel(m_model);
}

/**
 * @brief updateTableView 更新列表
 * @param sql 查询语句
 */
void BatteryLogForm::updateTableView(QString sql)
{
    MsgBoxEx *msgBox = new MsgBoxEx();
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("开始查询，查询结束后会给您提示，请耐心等待..."), 2000);
    delete msgBox;

//    WaitingForm *pQwait = new WaitingForm(this);
//    pQwait->show();

    m_model->removeRows(0, m_model->rowCount());

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        QString id = query.value(0).toString();
        QString date = query.value(1).toString();
        QString type = query.value(2).toString();
        QString address = query.value(3).toString();
        QString cabinet = query.value(4).toString();
        QString box = query.value(5).toString();
        QString info = query.value(6).toString();

        if(type=="1")      { type = QString::fromLocal8Bit("异常"); }
        else if(type=="2") { type = QString::fromLocal8Bit("发送"); }
        else if(type=="3") { type = QString::fromLocal8Bit("接收"); }
        else if(type=="4") { type = QString::fromLocal8Bit("日志"); }

        int rowCount = m_model->rowCount();
        m_model->setItem(rowCount, 0, new QStandardItem(id));
        m_model->setItem(rowCount, 1, new QStandardItem(date));
        m_model->setItem(rowCount, 2, new QStandardItem(type));
        m_model->setItem(rowCount, 3, new QStandardItem(address));
        m_model->setItem(rowCount, 4, new QStandardItem(cabinet));
        m_model->setItem(rowCount, 5, new QStandardItem(box));
        m_model->setItem(rowCount, 6, new QStandardItem(info));

       // QCoreApplication::processEvents();
    }

    //pQwait->close();
}

void BatteryLogForm::on_pushButtonReset_clicked()
{
    ui->lineEditDate->setText("");
    ui->comboBoxLogType->setCurrentIndex(-1);
    ui->lineEditAddress->setText("");
    ui->lineEditCabinet->setText("");
    ui->lineEditBox->setText("");
}

void BatteryLogForm::on_pushButtonQuery_clicked()
{
    QString date = ui->lineEditDate->text();
    QString type = ui->comboBoxLogType->currentText();
    QString address = ui->lineEditAddress->text();
    QString cabinet = ui->lineEditCabinet->text();
    QString box = ui->lineEditBox->text();

    if(date.isEmpty() && type.isEmpty() && address.isEmpty() && cabinet.isEmpty() && box.isEmpty())
    {
        updateTableView("SELECT log_id, log_date, log_type, log_address, log_cabinet, log_box, log_info FROM BATTERYDB_INFO_LOG");
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("查询完成！"));
        delete msgBox;
        return;
    }

    QString queryConditions;
    if(!date.isEmpty())
    {
        queryConditions += QString("datediff(day, log_date, '%1')=0").arg(date);
    }
    if(!type.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("log_type='%1'").arg(type);
    }
    if(!address.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("log_address='%1'").arg(address);
    }
    if(!cabinet.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("log_cabinet='%1'").arg(cabinet);
    }
    if(!box.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("log_box='%1'").arg(box);
    }

    QString sql = "SELECT log_id, log_date, log_type, log_address, log_cabinet, log_box, log_info FROM BATTERYDB_INFO_LOG WHERE " + queryConditions;
    updateTableView(sql);
    MsgBoxEx *msgBox = new MsgBoxEx();
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("查询完成！"));
    delete msgBox;
    return;
}
