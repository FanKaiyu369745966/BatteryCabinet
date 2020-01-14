/********************************************************************************
** Form generated from reading UI file 'WaitingForm.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITINGFORM_H
#define UI_WAITINGFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WaitingForm
{
public:
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *WaitingForm)
    {
        if (WaitingForm->objectName().isEmpty())
            WaitingForm->setObjectName(QString::fromUtf8("WaitingForm"));
        WaitingForm->resize(80, 80);
        gridLayout = new QGridLayout(WaitingForm);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(WaitingForm);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        retranslateUi(WaitingForm);

        QMetaObject::connectSlotsByName(WaitingForm);
    } // setupUi

    void retranslateUi(QWidget *WaitingForm)
    {
        WaitingForm->setWindowTitle(QCoreApplication::translate("WaitingForm", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WaitingForm: public Ui_WaitingForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITINGFORM_H
