/********************************************************************************
** Form generated from reading UI file 'SettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWIDGET_H
#define UI_SETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWidgetClass
{
public:

    void setupUi(QWidget *SettingsWidgetClass)
    {
        if (SettingsWidgetClass->objectName().isEmpty())
            SettingsWidgetClass->setObjectName(QString::fromUtf8("SettingsWidgetClass"));
        SettingsWidgetClass->resize(600, 400);

        retranslateUi(SettingsWidgetClass);

        QMetaObject::connectSlotsByName(SettingsWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *SettingsWidgetClass)
    {
        SettingsWidgetClass->setWindowTitle(QCoreApplication::translate("SettingsWidgetClass", "SettingsWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsWidgetClass: public Ui_SettingsWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWIDGET_H
