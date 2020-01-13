#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlError>
#include "ctrls/TitleBarEx.h"
#include "ctrls/CustomTabStyle.h"
#include "ctrls/MsgBoxEx.h"
#include "BatteryLogForm.h"
#include "BatteryCabinetForm.h"
#include "BatteryBoxForm.h"
#include "Config.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;


    void initWindow();

private slots:
    void onWindowClose();
    void onBtnOkClicked();
    void onBtnCancelClicked();

private:
    bool linkdb();
};

#endif // MAINWINDOW_H
