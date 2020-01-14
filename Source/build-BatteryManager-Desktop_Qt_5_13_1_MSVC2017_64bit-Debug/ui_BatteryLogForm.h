/********************************************************************************
** Form generated from reading UI file 'BatteryLogForm.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTERYLOGFORM_H
#define UI_BATTERYLOGFORM_H

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

class Ui_BatteryLogForm
{
public:
    QGridLayout *gridLayout_2;
    GroupBoxEx *groupBox;
    QGridLayout *gridLayout;
    LabelEx *label;
    LineEditEx *lineEditDate;
    QSpacerItem *horizontalSpacer_2;
    LabelEx *label_3;
    ComboBoxEx *comboBoxLogType;
    QSpacerItem *horizontalSpacer_3;
    LabelEx *label_4;
    LineEditEx *lineEditAddress;
    QSpacerItem *horizontalSpacer;
    PushButtonEx *pushButtonReset;
    LabelEx *label_5;
    LineEditEx *lineEditCabinet;
    LabelEx *label_6;
    LineEditEx *lineEditBox;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    PushButtonEx *pushButtonQuery;
    TableViewEx *tableView;

    void setupUi(QWidget *BatteryLogForm)
    {
        if (BatteryLogForm->objectName().isEmpty())
            BatteryLogForm->setObjectName(QString::fromUtf8("BatteryLogForm"));
        BatteryLogForm->resize(879, 486);
        gridLayout_2 = new QGridLayout(BatteryLogForm);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new GroupBoxEx(BatteryLogForm);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 70, -1, -1);
        label = new LabelEx(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditDate = new LineEditEx(groupBox);
        lineEditDate->setObjectName(QString::fromUtf8("lineEditDate"));
        lineEditDate->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(lineEditDate, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_3 = new LabelEx(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        comboBoxLogType = new ComboBoxEx(groupBox);
        comboBoxLogType->setObjectName(QString::fromUtf8("comboBoxLogType"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxLogType->sizePolicy().hasHeightForWidth());
        comboBoxLogType->setSizePolicy(sizePolicy);
        comboBoxLogType->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(comboBoxLogType, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        label_4 = new LabelEx(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 6, 1, 1);

        lineEditAddress = new LineEditEx(groupBox);
        lineEditAddress->setObjectName(QString::fromUtf8("lineEditAddress"));
        lineEditAddress->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(lineEditAddress, 0, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 8, 1, 1);

        pushButtonReset = new PushButtonEx(groupBox);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonReset->sizePolicy().hasHeightForWidth());
        pushButtonReset->setSizePolicy(sizePolicy1);
        pushButtonReset->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(pushButtonReset, 0, 9, 1, 1);

        label_5 = new LabelEx(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        lineEditCabinet = new LineEditEx(groupBox);
        lineEditCabinet->setObjectName(QString::fromUtf8("lineEditCabinet"));
        lineEditCabinet->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(lineEditCabinet, 1, 1, 1, 1);

        label_6 = new LabelEx(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 3, 1, 1);

        lineEditBox = new LineEditEx(groupBox);
        lineEditBox->setObjectName(QString::fromUtf8("lineEditBox"));
        lineEditBox->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(lineEditBox, 1, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 5, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 1, 6, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_6, 1, 7, 1, 1);

        pushButtonQuery = new PushButtonEx(groupBox);
        pushButtonQuery->setObjectName(QString::fromUtf8("pushButtonQuery"));
        sizePolicy1.setHeightForWidth(pushButtonQuery->sizePolicy().hasHeightForWidth());
        pushButtonQuery->setSizePolicy(sizePolicy1);
        pushButtonQuery->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(pushButtonQuery, 1, 9, 1, 1);

        tableView = new TableViewEx(groupBox);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout->addWidget(tableView, 2, 0, 1, 10);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(BatteryLogForm);

        QMetaObject::connectSlotsByName(BatteryLogForm);
    } // setupUi

    void retranslateUi(QWidget *BatteryLogForm)
    {
        BatteryLogForm->setWindowTitle(QCoreApplication::translate("BatteryLogForm", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BatteryLogForm", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("BatteryLogForm", "\346\227\245\345\277\227\346\227\245\346\234\237\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("BatteryLogForm", "\346\227\245\345\277\227\347\261\273\345\236\213\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("BatteryLogForm", "\351\200\232\344\277\241\345\234\260\345\235\200\357\274\232", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("BatteryLogForm", "\351\207\215  \347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("BatteryLogForm", "\347\224\265\346\261\240\346\237\234\347\274\226\345\217\267\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("BatteryLogForm", "\347\224\265\346\261\240\347\233\222\347\274\226\345\217\267\357\274\232", nullptr));
        pushButtonQuery->setText(QCoreApplication::translate("BatteryLogForm", "\346\237\245  \350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BatteryLogForm: public Ui_BatteryLogForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERYLOGFORM_H
