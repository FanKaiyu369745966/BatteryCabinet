#include "BatteryCabinetForm.h"
#include "ui_BatteryCabinetForm.h"

BatteryCabinetForm::BatteryCabinetForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatteryCabinetForm)
{
    ui->setupUi(this);

    // 背景
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, QColor("#2D3035"));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    ui->groupBoxCtrl->setTitle(QString::fromLocal8Bit("电池柜状态设置"));
    ui->groupBoxView->setTitle(QString::fromLocal8Bit("电池柜信息"));

    ui->comboBoxState_Ctrl->addItem(QString::fromLocal8Bit(""));
    ui->comboBoxState_Ctrl->addItem(QString::fromLocal8Bit("使用中"));
    ui->comboBoxState_Ctrl->addItem(QString::fromLocal8Bit("已拆除"));
    ui->comboBoxState_Ctrl->setCurrentIndex(-1);

    ui->comboBoxState->addItem(QString::fromLocal8Bit(""));
    ui->comboBoxState->addItem(QString::fromLocal8Bit("使用中"));
    ui->comboBoxState->addItem(QString::fromLocal8Bit("已拆除"));
    ui->comboBoxState->setCurrentIndex(-1);

    ui->comboBoxConnect->addItem(QString::fromLocal8Bit(""));
    ui->comboBoxConnect->addItem(QString::fromLocal8Bit("已连接"));
    ui->comboBoxConnect->addItem(QString::fromLocal8Bit("未连接"));
    ui->comboBoxConnect->setCurrentIndex(-1);


    initTableView();

}

BatteryCabinetForm::~BatteryCabinetForm()
{
    delete ui;
}


/**
 * @brief initTableView 初始化列表
 */
void BatteryCabinetForm::initTableView()
{
    m_model = new QStandardItemModel(this);
    m_model->setColumnCount(6);
    m_model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("编号"));
    m_model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("状态"));
    m_model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("地理位置"));
    m_model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("连接状态"));
    m_model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("通信地址"));
    m_model->setHeaderData(5, Qt::Horizontal, QString::fromLocal8Bit("SIM卡号码"));
    ui->tableView->setModel(m_model);
}

/**
 * @brief updateTableView 更新列表
 * @param sql 查询语句
 */
void BatteryCabinetForm::updateTableView(QString sql)
{
    m_model->removeRows(0, m_model->rowCount());

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        QString id = query.value(0).toString();
        QString state = query.value(1).toString();
        QString local = query.value(2).toString();
        QString conn = query.value(3).toString();
        QString address = query.value(4).toString();
        QString sim = query.value(5).toString();

        int rowCount = m_model->rowCount();
        m_model->setItem(rowCount, 0, new QStandardItem(id));
        m_model->setItem(rowCount, 1, new QStandardItem(state));
        m_model->setItem(rowCount, 2, new QStandardItem(local));
        m_model->setItem(rowCount, 3, new QStandardItem(conn));
        m_model->setItem(rowCount, 4, new QStandardItem(address));
        m_model->setItem(rowCount, 5, new QStandardItem(sim));
    }
}

void BatteryCabinetForm::on_pushButtonReset_clicked()
{
    ui->lineEditID->setText("");
    ui->comboBoxState->setCurrentIndex(-1);
    ui->lineEditLocation->setText("");
    ui->comboBoxConnect->setCurrentIndex(-1);
    ui->lineEditAddress->setText("");
    ui->lineEditSIM->setText("");
}

void BatteryCabinetForm::on_pushButtonQuery_clicked()
{
    QString id = ui->lineEditID->text();
    QString state = ui->comboBoxState->currentText();
    QString location = ui->lineEditAddress->text();
    QString connect = ui->comboBoxConnect->currentText();
    QString address = ui->lineEditAddress->text();
    QString sim = ui->lineEditSIM->text();

    if(id.isEmpty() && state.isEmpty() && location.isEmpty() && connect.isEmpty() && address.isEmpty() && sim.isEmpty())
    {
        updateTableView("SELECT cabinet_code, cabinet_status, cabinet_address, cabinet_connection, cabinet_host, cabinet_tel FROM BATTERYDB_INFO_CABINET");
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("查询完成！"));
        delete msgBox;
        return;
    }

    QString queryConditions;
    if(!id.isEmpty())
    {
        queryConditions += QString("cabinet_code='%1'").arg(id);
    }
    if(!state.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("cabinet_status='%1'").arg(state);
    }
    if(!location.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("cabinet_address='%1'").arg(location);
    }
    if(!connect.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("cabinet_connection='%1'").arg(connect);
    }
    if(!address.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("cabinet_host='%1'").arg(address);
    }
    if(!sim.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("cabinet_tel='%1'").arg(sim);
    }

    QString sql = "SELECT cabinet_code, cabinet_status, cabinet_address, cabinet_connection, cabinet_host, cabinet_tel FROM BATTERYDB_INFO_CABINET WHERE " + queryConditions;
    updateTableView(sql);
    MsgBoxEx *msgBox = new MsgBoxEx();
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("查询完成！"));
    delete msgBox;
    return;
}

void BatteryCabinetForm::on_pushButtonSet_clicked()
{
    QString id = ui->lineEditID_Ctrl->text();
    QString state = ui->comboBoxState_Ctrl->currentText();

    if(id.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("请输入充电柜编号！"));
        delete msgBox;
        return;
    }
    if(state.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("请选择充电柜状态！"));
        delete msgBox;
        return;
    }

    QSqlQuery query;
    query.exec(QString("SELECT * FROM BATTERYDB_INFO_CABINET WHERE cabinet_code='%1'").arg(id));
    if(!query.next())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("不存在此充电柜！"));
        delete msgBox;
        return;
    }

    if (!query.exec(QString("UPDATE BATTERYDB_INFO_CABINET SET cabinet_status='%1' WHERE cabinet_code='%2'").arg(state).arg(id)))
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("设置充电柜状态失败！"));
        delete msgBox;
        return;
    }

    MsgBoxEx *msgBox = new MsgBoxEx();
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("设置充电柜状态 【%1】 成功！").arg(state));
    delete msgBox;
    return;
}
