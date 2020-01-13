#ifndef BATTERYBOXFORM_H
#define BATTERYBOXFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDate>
#include <QRegExp>
#include "ctrls/MsgBoxEx.h"

namespace Ui {
class BatteryBoxForm;
}

class BatteryBoxForm : public QWidget
{
    Q_OBJECT

public:
    explicit BatteryBoxForm(QWidget *parent = nullptr);
    ~BatteryBoxForm();

private slots:
    void on_pushButtonReset_clicked();

    void on_pushButtonQuery_clicked();

    void on_pushButtonOpen_clicked();

private:
    Ui::BatteryBoxForm *ui;
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

#endif // BATTERYBOXFORM_H
