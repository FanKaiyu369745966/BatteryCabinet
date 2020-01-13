/********************************************************************************
** Form generated from reading UI file 'NetSettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETSETTINGSWIDGET_H
#define UI_NETSETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NetSettingsWidget
{
public:

    void setupUi(QWidget *NetSettingsWidget)
    {
        if (NetSettingsWidget->objectName().isEmpty())
            NetSettingsWidget->setObjectName(QString::fromUtf8("NetSettingsWidget"));
        NetSettingsWidget->resize(400, 300);

        retranslateUi(NetSettingsWidget);

        QMetaObject::connectSlotsByName(NetSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *NetSettingsWidget)
    {
        NetSettingsWidget->setWindowTitle(QCoreApplication::translate("NetSettingsWidget", "NetSettingsWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NetSettingsWidget: public Ui_NetSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETSETTINGSWIDGET_H
