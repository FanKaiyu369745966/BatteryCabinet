#ifndef BATTERYLOGFORM_H
#define BATTERYLOGFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDate>
#include <QRegExp>
#include "ctrls/MsgBoxEx.h"
#include "WaitingForm.h"

namespace Ui {
class BatteryLogForm;
}

class BatteryLogForm : public QWidget
{
    Q_OBJECT

public:
    explicit BatteryLogForm(QWidget *parent = nullptr);
    ~BatteryLogForm();

private slots:
    void on_pushButtonReset_clicked();

    void on_pushButtonQuery_clicked();

private:
    Ui::BatteryLogForm *ui;
    QStandardItemModel *m_model;

private:
    /**
     * @brief initTableView 初始化列表
     */
    void initTableView();


    /**
     * @brief updateTableView 更新列表
     * @param sql 查询语句
     */
    void updateTableView(QString sql);
};

#endif // BATTERYLOGFORM_H
