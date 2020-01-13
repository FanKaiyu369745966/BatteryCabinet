#ifndef BATTERYCABINETFORM_H
#define BATTERYCABINETFORM_H

#include <QWidget>
#include <QStandardItemModel>
#include <QSqlQuery>
#include <QDate>
#include <QRegExp>
#include "ctrls/MsgBoxEx.h"

namespace Ui {
class BatteryCabinetForm;
}

class BatteryCabinetForm : public QWidget
{
    Q_OBJECT

public:
    explicit BatteryCabinetForm(QWidget *parent = nullptr);
    ~BatteryCabinetForm();

private slots:
    void on_pushButtonReset_clicked();
    void on_pushButtonQuery_clicked();

    void on_pushButtonSet_clicked();

private:
    Ui::BatteryCabinetForm *ui;
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

#endif // BATTERYCABINETFORM_H
