/********************************************************************************
** Form generated from reading UI file 'BatteryBoxForm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTERYBOXFORM_H
#define UI_BATTERYBOXFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>
#include "ctrls/ComboBoxEx.h"
#include "ctrls/GroupBoxEx.h"
#include "ctrls/LabelEx.h"
#include "ctrls/LineEditEx.h"
#include "ctrls/PushButtonEx.h"
#include "ctrls/TableViewEx.h"

QT_BEGIN_NAMESPACE

class Ui_BatteryBoxForm
{
public:
    QGridLayout *gridLayout_3;
    GroupBoxEx *groupBoxCtrl;
    QGridLayout *gridLayout;
    PushButtonEx *pushButtonOpen;
    QSpacerItem *horizontalSpacer_6;
    LineEditEx *lineEditBoxID_Ctrl;
    QSpacerItem *horizontalSpacer_5;
    LabelEx *label_2;
    LabelEx *label_6;
    LineEditEx *lineEditCabinetID_Ctrl;
    GroupBoxEx *groupBoxView;
    QGridLayout *gridLayout_2;
    PushButtonEx *pushButtonQuery;
    PushButtonEx *pushButtonReset;
    TableViewEx *tableView;
    QSpacerItem *horizontalSpacer_4;
    LineEditEx *lineEditCabinetID;
    LabelEx *label_4;
    ComboBoxEx *comboBoxDoorState;
    QSpacerItem *horizontalSpacer_2;
    LabelEx *label;
    LabelEx *label_3;
    LabelEx *label_5;
    QSpacerItem *horizontalSpacer_3;
    ComboBoxEx *comboBoxBatteryState;
    QSpacerItem *horizontalSpacer_7;
    LineEditEx *lineEditBoxID;

    void setupUi(QWidget *BatteryBoxForm)
    {
        if (BatteryBoxForm->objectName().isEmpty())
            BatteryBoxForm->setObjectName(QString::fromUtf8("BatteryBoxForm"));
        BatteryBoxForm->resize(1206, 537);
        gridLayout_3 = new QGridLayout(BatteryBoxForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBoxCtrl = new GroupBoxEx(BatteryBoxForm);
        groupBoxCtrl->setObjectName(QString::fromUtf8("groupBoxCtrl"));
        gridLayout = new QGridLayout(groupBoxCtrl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 70, -1, -1);
        pushButtonOpen = new PushButtonEx(groupBoxCtrl);
        pushButtonOpen->setObjectName(QString::fromUtf8("pushButtonOpen"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButtonOpen->sizePolicy().hasHeightForWidth());
        pushButtonOpen->setSizePolicy(sizePolicy);
        pushButtonOpen->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(pushButtonOpen, 0, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 0, 5, 1, 1);

        lineEditBoxID_Ctrl = new LineEditEx(groupBoxCtrl);
        lineEditBoxID_Ctrl->setObjectName(QString::fromUtf8("lineEditBoxID_Ctrl"));
        lineEditBoxID_Ctrl->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEditBoxID_Ctrl, 0, 4, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        label_2 = new LabelEx(groupBoxCtrl);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        label_6 = new LabelEx(groupBoxCtrl);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        lineEditCabinetID_Ctrl = new LineEditEx(groupBoxCtrl);
        lineEditCabinetID_Ctrl->setObjectName(QString::fromUtf8("lineEditCabinetID_Ctrl"));
        lineEditCabinetID_Ctrl->setMinimumSize(QSize(0, 30));

        gridLayout->addWidget(lineEditCabinetID_Ctrl, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBoxCtrl, 0, 0, 1, 1);

        groupBoxView = new GroupBoxEx(BatteryBoxForm);
        groupBoxView->setObjectName(QString::fromUtf8("groupBoxView"));
        gridLayout_2 = new QGridLayout(groupBoxView);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 70, -1, -1);
        pushButtonQuery = new PushButtonEx(groupBoxView);
        pushButtonQuery->setObjectName(QString::fromUtf8("pushButtonQuery"));
        sizePolicy.setHeightForWidth(pushButtonQuery->sizePolicy().hasHeightForWidth());
        pushButtonQuery->setSizePolicy(sizePolicy);
        pushButtonQuery->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(pushButtonQuery, 0, 13, 1, 1);

        pushButtonReset = new PushButtonEx(groupBoxView);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));
        sizePolicy.setHeightForWidth(pushButtonReset->sizePolicy().hasHeightForWidth());
        pushButtonReset->setSizePolicy(sizePolicy);
        pushButtonReset->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(pushButtonReset, 0, 12, 1, 1);

        tableView = new TableViewEx(groupBoxView);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 1, 0, 1, 14);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 0, 8, 1, 1);

        lineEditCabinetID = new LineEditEx(groupBoxView);
        lineEditCabinetID->setObjectName(QString::fromUtf8("lineEditCabinetID"));
        lineEditCabinetID->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(lineEditCabinetID, 0, 4, 1, 1);

        label_4 = new LabelEx(groupBoxView);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 6, 1, 1);

        comboBoxDoorState = new ComboBoxEx(groupBoxView);
        comboBoxDoorState->setObjectName(QString::fromUtf8("comboBoxDoorState"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBoxDoorState->sizePolicy().hasHeightForWidth());
        comboBoxDoorState->setSizePolicy(sizePolicy1);
        comboBoxDoorState->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(comboBoxDoorState, 0, 7, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label = new LabelEx(groupBoxView);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_3 = new LabelEx(groupBoxView);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 3, 1, 1);

        label_5 = new LabelEx(groupBoxView);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 9, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        comboBoxBatteryState = new ComboBoxEx(groupBoxView);
        comboBoxBatteryState->setObjectName(QString::fromUtf8("comboBoxBatteryState"));
        sizePolicy1.setHeightForWidth(comboBoxBatteryState->sizePolicy().hasHeightForWidth());
        comboBoxBatteryState->setSizePolicy(sizePolicy1);
        comboBoxBatteryState->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(comboBoxBatteryState, 0, 10, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 11, 1, 1);

        lineEditBoxID = new LineEditEx(groupBoxView);
        lineEditBoxID->setObjectName(QString::fromUtf8("lineEditBoxID"));
        lineEditBoxID->setMinimumSize(QSize(0, 30));

        gridLayout_2->addWidget(lineEditBoxID, 0, 1, 1, 1);


        gridLayout_3->addWidget(groupBoxView, 1, 0, 1, 1);


        retranslateUi(BatteryBoxForm);

        QMetaObject::connectSlotsByName(BatteryBoxForm);
    } // setupUi

    void retranslateUi(QWidget *BatteryBoxForm)
    {
        BatteryBoxForm->setWindowTitle(QApplication::translate("BatteryBoxForm", "Form", nullptr));
        groupBoxCtrl->setTitle(QApplication::translate("BatteryBoxForm", "GroupBox", nullptr));
        pushButtonOpen->setText(QApplication::translate("BatteryBoxForm", "\345\274\200  \351\227\250", nullptr));
        label_2->setText(QApplication::translate("BatteryBoxForm", "\347\224\265\346\261\240\347\233\222\347\274\226\345\217\267\357\274\232", nullptr));
        label_6->setText(QApplication::translate("BatteryBoxForm", "\347\224\265\346\261\240\346\237\234\347\274\226\345\217\267\357\274\232", nullptr));
        groupBoxView->setTitle(QApplication::translate("BatteryBoxForm", "GroupBox", nullptr));
        pushButtonQuery->setText(QApplication::translate("BatteryBoxForm", "\346\237\245  \350\257\242", nullptr));
        pushButtonReset->setText(QApplication::translate("BatteryBoxForm", "\351\207\215  \347\275\256", nullptr));
        label_4->setText(QApplication::translate("BatteryBoxForm", "\347\224\265\346\261\240\347\233\222\346\237\234\351\227\250\347\212\266\346\200\201\357\274\232", nullptr));
        label->setText(QApplication::translate("BatteryBoxForm", "\347\224\265\346\261\240\347\233\222\347\274\226\345\217\267\357\274\232", nullptr));
        label_3->setText(QApplication::translate("BatteryBoxForm", "\347\224\265\346\261\240\346\237\234\347\274\226\345\217\267\357\274\232", nullptr));
        label_5->setText(QApplication::translate("BatteryBoxForm", "\347\224\265\346\261\240\347\233\222\347\224\265\346\261\240\347\212\266\346\200\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BatteryBoxForm: public Ui_BatteryBoxForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERYBOXFORM_H
