#include "BatteryBoxForm.h"
#include "ui_BatteryBoxForm.h"

BatteryBoxForm::BatteryBoxForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BatteryBoxForm)
{
    ui->setupUi(this);

    // 背景
    QPalette pal(this->palette());
    pal.setColor(QPalette::Background, QColor("#2D3035"));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    ui->groupBoxCtrl->setTitle(QString::fromLocal8Bit("电池盒远程开关控制"));
    ui->groupBoxView->setTitle(QString::fromLocal8Bit("电池盒信息"));

    ui->comboBoxDoorState->addItem(QString::fromLocal8Bit(""));
    ui->comboBoxDoorState->addItem(QString::fromLocal8Bit("已打开柜门"));
    ui->comboBoxDoorState->addItem(QString::fromLocal8Bit("柜门打开失败"));
    ui->comboBoxDoorState->addItem(QString::fromLocal8Bit("已关闭柜门"));
    ui->comboBoxDoorState->addItem(QString::fromLocal8Bit("柜门意外开启"));
    ui->comboBoxDoorState->setCurrentIndex(-1);

    ui->comboBoxBatteryState->addItem(QString::fromLocal8Bit(""));
    ui->comboBoxBatteryState->addItem(QString::fromLocal8Bit("充电完成"));
    ui->comboBoxBatteryState->addItem(QString::fromLocal8Bit("充电异常"));
    ui->comboBoxBatteryState->addItem(QString::fromLocal8Bit("空柜"));
    ui->comboBoxBatteryState->addItem(QString::fromLocal8Bit("加入电池"));
    ui->comboBoxBatteryState->setCurrentIndex(-1);


    initTableView();

}

BatteryBoxForm::~BatteryBoxForm()
{
    delete ui;
}

/**
 * @brief initTableView 初始化列表
 */
void BatteryBoxForm::initTableView()
{
    m_model = new QStandardItemModel(this);
    m_model->setColumnCount(5);
    m_model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("电池盒编号"));
    m_model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("电池柜编号"));
    m_model->setHeaderData(2, Qt::Horizontal, QString::fromLocal8Bit("电池盒柜门状态"));
    m_model->setHeaderData(3, Qt::Horizontal, QString::fromLocal8Bit("电池盒电池状态"));
    m_model->setHeaderData(4, Qt::Horizontal, QString::fromLocal8Bit("电池盒开门指令"));

    ui->tableView->setModel(m_model);
}

/**
 * @brief updateTableView 更新列表
 * @param sql 查询语句
 */
void BatteryBoxForm::updateTableView(QString sql)
{
    m_model->removeRows(0, m_model->rowCount());

    QSqlQuery query;
    query.exec(sql);
    while (query.next())
    {
        QString box = query.value(0).toString();
        QString cabinet = query.value(1).toString();
        int door = query.value(2).toInt();
        int battery = query.value(3).toInt();
        int open = query.value(4).toInt();

        QString doorState;
        if(door==12) { doorState = QString::fromLocal8Bit("已打开柜门"); }
        else if(door==13) { doorState = QString::fromLocal8Bit("柜门打开失败"); }
        else if(door==23) { doorState = QString::fromLocal8Bit("已关闭柜门"); }
        else if(door==32) { doorState = QString::fromLocal8Bit("柜门意外开启"); }

        QString batteryState;
        if(battery==21) { batteryState = QString::fromLocal8Bit("充电完成"); }
        else if(battery==31) { batteryState = QString::fromLocal8Bit("充电异常"); }
        else if(battery==24) { batteryState = QString::fromLocal8Bit("空柜"); }
        else if(battery==25) { batteryState = QString::fromLocal8Bit("加入电池"); }

        QString cmdOpen;
        if(open==1) { cmdOpen = QString::fromLocal8Bit("开"); }
        else { cmdOpen = QString::fromLocal8Bit("关"); }

        int rowCount = m_model->rowCount();
        m_model->setItem(rowCount, 0, new QStandardItem(box));
        m_model->setItem(rowCount, 1, new QStandardItem(cabinet));
        m_model->setItem(rowCount, 2, new QStandardItem(doorState));
        m_model->setItem(rowCount, 3, new QStandardItem(batteryState));
        m_model->setItem(rowCount, 4, new QStandardItem(cmdOpen));
    }
}

void BatteryBoxForm::on_pushButtonReset_clicked()
{
    ui->lineEditBoxID->setText("");
    ui->lineEditCabinetID->setText("");
    ui->comboBoxDoorState->setCurrentIndex(-1);
    ui->comboBoxBatteryState->setCurrentIndex(-1);
}

void BatteryBoxForm::on_pushButtonQuery_clicked()
{
    QString box = ui->lineEditBoxID->text();
    QString cabinet = ui->lineEditCabinetID->text();
    QString door = ui->comboBoxDoorState->currentText();
    QString battery = ui->comboBoxBatteryState->currentText();

    if(box.isEmpty() && cabinet.isEmpty() && door.isEmpty() && battery.isEmpty())
    {
        updateTableView("SELECT box_code, box_cabinet, box_door_status, box_battery_status, box_cmd_open FROM BATTERYDB_INFO_BOX");
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("查询完成！"));
        delete msgBox;
        return;
    }

    int doorState = 0;
    if(door==QString::fromLocal8Bit("已打开柜门")) { doorState = 12; }
    else if(door==QString::fromLocal8Bit("柜门打开失败")) { doorState = 13; }
    else if(door==QString::fromLocal8Bit("已关闭柜门")) { doorState = 23; }
    else if(door==QString::fromLocal8Bit("柜门意外开启")) { doorState = 32; }

    int batteryState = 0;
    if(battery==QString::fromLocal8Bit("充电完成")) { batteryState = 21; }
    else if(battery==QString::fromLocal8Bit("充电异常")) { batteryState = 31; }
    else if(battery==QString::fromLocal8Bit("空柜")) { batteryState = 24; }
    else if(battery==QString::fromLocal8Bit("加入电池")) { batteryState = 25; }


    QString queryConditions;
    if(!box.isEmpty())
    {
        queryConditions += QString("box_code='%1'").arg(box);
    }
    if(!cabinet.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("box_cabinet='%1'").arg(cabinet);
    }
    if(!door.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("box_door_status=%1").arg(doorState);
    }
    if(!battery.isEmpty())
    {
        if(!queryConditions.isEmpty())
            queryConditions += " AND ";
        queryConditions += QString("box_battery_status=%1").arg(batteryState);
    }

    QString sql = "SELECT box_code, box_cabinet, box_door_status, box_battery_status, box_cmd_open FROM BATTERYDB_INFO_BOX WHERE " + queryConditions;
    updateTableView(sql);

    MsgBoxEx *msgBox = new MsgBoxEx();
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("查询完成！"));
    delete msgBox;
    return;
}

void BatteryBoxForm::on_pushButtonOpen_clicked()
{
    QString cabinet = ui->lineEditCabinetID_Ctrl->text();
    QString box = ui->lineEditBoxID_Ctrl->text();

    if(cabinet.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("请输入充电柜编号！"));
        delete msgBox;
        return;
    }
    if(box.isEmpty())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("请输入充电盒编号！"));
        delete msgBox;
        return;
    }

    QSqlQuery query;
    query.exec(QString("SELECT box_cmd_open FROM BATTERYDB_INFO_BOX WHERE box_code='%1' AND box_cabinet='%2'").arg(box).arg(cabinet));
    if(!query.next())
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("不存在此充电柜的充电盒！"));
        delete msgBox;
        return;
    }
    else
    {
        int open = query.value(0).toInt();
        if(open == 1) // 如果电池盒门的状态是“1”，即已打开，则不可则设置开门操作
        {
            MsgBoxEx *msgBox = new MsgBoxEx();
            msgBox->setMsgBoxMode(QString::fromLocal8Bit("电池盒门已打开！"));
            delete msgBox;
            return;
        }
    }

    if (!query.exec(QString("UPDATE BATTERYDB_INFO_BOX SET box_cmd_open=1 WHERE box_code='%1' AND box_cabinet='%2'").arg(box).arg(cabinet)))
    {
        MsgBoxEx *msgBox = new MsgBoxEx();
        msgBox->setMsgBoxMode(QString::fromLocal8Bit("设置电池盒开门失败！"));
        delete msgBox;
        return;
    }

    MsgBoxEx *msgBox = new MsgBoxEx();
    msgBox->setMsgBoxMode(QString::fromLocal8Bit("设置电池盒开门状态成功！"));
    delete msgBox;
    return;
}
