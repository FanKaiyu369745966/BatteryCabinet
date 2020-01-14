/********************************************************************************
** Form generated from reading UI file 'BatteryCabinetForm.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BATTERYCABINETFORM_H
#define UI_BATTERYCABINETFORM_H

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

class Ui_BatteryCabinetForm
{
public:
    QGridLayout *gridLayout_3;
    GroupBoxEx *groupBoxCtrl;
    QGridLayout *gridLayout;
    LabelEx *label_2;
    LineEditEx *lineEditID_Ctrl;
    QSpacerItem *horizontalSpacer_5;
    LabelEx *label_12;
    ComboBoxEx *comboBoxState_Ctrl;
    QSpacerItem *horizontalSpacer_7;
    PushButtonEx *pushButtonSet;
    GroupBoxEx *groupBoxView;
    QGridLayout *gridLayout_2;
    LabelEx *label;
    LineEditEx *lineEditID;
    QSpacerItem *horizontalSpacer_2;
    LabelEx *label_3;
    ComboBoxEx *comboBoxState;
    QSpacerItem *horizontalSpacer_3;
    LabelEx *label_4;
    LineEditEx *lineEditLocation;
    QSpacerItem *horizontalSpacer;
    PushButtonEx *pushButtonReset;
    LabelEx *label_5;
    ComboBoxEx *comboBoxConnect;
    LabelEx *label_6;
    LineEditEx *lineEditAddress;
    QSpacerItem *horizontalSpacer_4;
    LabelEx *label_7;
    LineEditEx *lineEditSIM;
    PushButtonEx *pushButtonQuery;
    TableViewEx *tableView;

    void setupUi(QWidget *BatteryCabinetForm)
    {
        if (BatteryCabinetForm->objectName().isEmpty())
            BatteryCabinetForm->setObjectName(QString::fromUtf8("BatteryCabinetForm"));
        BatteryCabinetForm->resize(888, 569);
        gridLayout_3 = new QGridLayout(BatteryCabinetForm);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBoxCtrl = new GroupBoxEx(BatteryCabinetForm);
        groupBoxCtrl->setObjectName(QString::fromUtf8("groupBoxCtrl"));
        gridLayout = new QGridLayout(groupBoxCtrl);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 70, -1, -1);
        label_2 = new LabelEx(groupBoxCtrl);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEditID_Ctrl = new LineEditEx(groupBoxCtrl);
        lineEditID_Ctrl->setObjectName(QString::fromUtf8("lineEditID_Ctrl"));
        lineEditID_Ctrl->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(lineEditID_Ctrl, 0, 1, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 2, 1, 1);

        label_12 = new LabelEx(groupBoxCtrl);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 0, 3, 1, 1);

        comboBoxState_Ctrl = new ComboBoxEx(groupBoxCtrl);
        comboBoxState_Ctrl->setObjectName(QString::fromUtf8("comboBoxState_Ctrl"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxState_Ctrl->sizePolicy().hasHeightForWidth());
        comboBoxState_Ctrl->setSizePolicy(sizePolicy);
        comboBoxState_Ctrl->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(comboBoxState_Ctrl, 0, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_7, 0, 5, 1, 1);

        pushButtonSet = new PushButtonEx(groupBoxCtrl);
        pushButtonSet->setObjectName(QString::fromUtf8("pushButtonSet"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonSet->sizePolicy().hasHeightForWidth());
        pushButtonSet->setSizePolicy(sizePolicy1);
        pushButtonSet->setMinimumSize(QSize(120, 30));

        gridLayout->addWidget(pushButtonSet, 0, 6, 1, 1);


        gridLayout_3->addWidget(groupBoxCtrl, 0, 0, 1, 1);

        groupBoxView = new GroupBoxEx(BatteryCabinetForm);
        groupBoxView->setObjectName(QString::fromUtf8("groupBoxView"));
        gridLayout_2 = new QGridLayout(groupBoxView);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(-1, 70, -1, -1);
        label = new LabelEx(groupBoxView);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEditID = new LineEditEx(groupBoxView);
        lineEditID->setObjectName(QString::fromUtf8("lineEditID"));
        lineEditID->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(lineEditID, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        label_3 = new LabelEx(groupBoxView);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 3, 1, 1);

        comboBoxState = new ComboBoxEx(groupBoxView);
        comboBoxState->setObjectName(QString::fromUtf8("comboBoxState"));
        sizePolicy.setHeightForWidth(comboBoxState->sizePolicy().hasHeightForWidth());
        comboBoxState->setSizePolicy(sizePolicy);
        comboBoxState->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(comboBoxState, 0, 4, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 5, 1, 1);

        label_4 = new LabelEx(groupBoxView);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 6, 1, 1);

        lineEditLocation = new LineEditEx(groupBoxView);
        lineEditLocation->setObjectName(QString::fromUtf8("lineEditLocation"));
        lineEditLocation->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(lineEditLocation, 0, 7, 1, 1);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 8, 1, 1);

        pushButtonReset = new PushButtonEx(groupBoxView);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));
        sizePolicy1.setHeightForWidth(pushButtonReset->sizePolicy().hasHeightForWidth());
        pushButtonReset->setSizePolicy(sizePolicy1);
        pushButtonReset->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(pushButtonReset, 0, 9, 1, 1);

        label_5 = new LabelEx(groupBoxView);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        comboBoxConnect = new ComboBoxEx(groupBoxView);
        comboBoxConnect->setObjectName(QString::fromUtf8("comboBoxConnect"));
        sizePolicy.setHeightForWidth(comboBoxConnect->sizePolicy().hasHeightForWidth());
        comboBoxConnect->setSizePolicy(sizePolicy);
        comboBoxConnect->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(comboBoxConnect, 1, 1, 1, 1);

        label_6 = new LabelEx(groupBoxView);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 3, 1, 1);

        lineEditAddress = new LineEditEx(groupBoxView);
        lineEditAddress->setObjectName(QString::fromUtf8("lineEditAddress"));
        lineEditAddress->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(lineEditAddress, 1, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 1, 5, 1, 1);

        label_7 = new LabelEx(groupBoxView);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 1, 6, 1, 1);

        lineEditSIM = new LineEditEx(groupBoxView);
        lineEditSIM->setObjectName(QString::fromUtf8("lineEditSIM"));
        lineEditSIM->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(lineEditSIM, 1, 7, 1, 1);

        pushButtonQuery = new PushButtonEx(groupBoxView);
        pushButtonQuery->setObjectName(QString::fromUtf8("pushButtonQuery"));
        sizePolicy1.setHeightForWidth(pushButtonQuery->sizePolicy().hasHeightForWidth());
        pushButtonQuery->setSizePolicy(sizePolicy1);
        pushButtonQuery->setMinimumSize(QSize(120, 30));

        gridLayout_2->addWidget(pushButtonQuery, 1, 9, 1, 1);

        tableView = new TableViewEx(groupBoxView);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        gridLayout_2->addWidget(tableView, 2, 0, 1, 10);


        gridLayout_3->addWidget(groupBoxView, 1, 0, 1, 1);


        retranslateUi(BatteryCabinetForm);

        QMetaObject::connectSlotsByName(BatteryCabinetForm);
    } // setupUi

    void retranslateUi(QWidget *BatteryCabinetForm)
    {
        BatteryCabinetForm->setWindowTitle(QCoreApplication::translate("BatteryCabinetForm", "Form", nullptr));
        groupBoxCtrl->setTitle(QCoreApplication::translate("BatteryCabinetForm", "GroupBox", nullptr));
        label_2->setText(QCoreApplication::translate("BatteryCabinetForm", "\347\224\265\346\261\240\346\237\234\347\274\226\345\217\267\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("BatteryCabinetForm", "\347\224\265\346\261\240\346\237\234\347\212\266\346\200\201\357\274\232", nullptr));
        pushButtonSet->setText(QCoreApplication::translate("BatteryCabinetForm", "\350\256\276  \347\275\256", nullptr));
        groupBoxView->setTitle(QCoreApplication::translate("BatteryCabinetForm", "GroupBox", nullptr));
        label->setText(QCoreApplication::translate("BatteryCabinetForm", "\347\224\265\346\261\240\346\237\234\347\274\226\345\217\267\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("BatteryCabinetForm", "\347\224\265\346\261\240\346\237\234\347\212\266\346\200\201\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("BatteryCabinetForm", "\345\234\260\347\220\206\344\275\215\347\275\256\357\274\232", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("BatteryCabinetForm", "\351\207\215  \347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("BatteryCabinetForm", "\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("BatteryCabinetForm", "\351\200\232\344\277\241\345\234\260\345\235\200\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("BatteryCabinetForm", "SIM\345\215\241\345\217\267\347\240\201\357\274\232", nullptr));
        pushButtonQuery->setText(QCoreApplication::translate("BatteryCabinetForm", "\346\237\245  \350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BatteryCabinetForm: public Ui_BatteryCabinetForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BATTERYCABINETFORM_H
