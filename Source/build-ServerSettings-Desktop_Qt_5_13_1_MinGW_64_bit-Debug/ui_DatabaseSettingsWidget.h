/********************************************************************************
** Form generated from reading UI file 'DatabaseSettingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATABASESETTINGSWIDGET_H
#define UI_DATABASESETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DatabaseSettingsWidget
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_4;
    QToolButton *toolButton;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *DatabaseSettingsWidget)
    {
        if (DatabaseSettingsWidget->objectName().isEmpty())
            DatabaseSettingsWidget->setObjectName(QString::fromUtf8("DatabaseSettingsWidget"));
        DatabaseSettingsWidget->resize(608, 450);
        gridLayout = new QGridLayout(DatabaseSettingsWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(DatabaseSettingsWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(DatabaseSettingsWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        lineEdit_2 = new QLineEdit(DatabaseSettingsWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);

        lineEdit_3 = new QLineEdit(DatabaseSettingsWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        verticalLayout_2->addWidget(lineEdit_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineEdit_4 = new QLineEdit(DatabaseSettingsWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout->addWidget(lineEdit_4);

        toolButton = new QToolButton(DatabaseSettingsWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout->addWidget(toolButton);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 2);

        pushButton_2 = new QPushButton(DatabaseSettingsWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DatabaseSettingsWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(DatabaseSettingsWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(DatabaseSettingsWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_3);

        label_4 = new QLabel(DatabaseSettingsWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setTextFormat(Qt::AutoText);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(label_4);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(DatabaseSettingsWidget);

        QMetaObject::connectSlotsByName(DatabaseSettingsWidget);
    } // setupUi

    void retranslateUi(QWidget *DatabaseSettingsWidget)
    {
        DatabaseSettingsWidget->setWindowTitle(QCoreApplication::translate("DatabaseSettingsWidget", "DatabaseSettingsWidget", nullptr));
        pushButton->setText(QCoreApplication::translate("DatabaseSettingsWidget", "\350\256\276\347\275\256", nullptr));
        toolButton->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("DatabaseSettingsWidget", "\346\265\213\350\257\225\350\277\236\346\216\245", nullptr));
        label->setText(QCoreApplication::translate("DatabaseSettingsWidget", "\346\225\260\346\215\256\345\272\223\344\270\273\346\234\272\345\220\215:", nullptr));
        label_2->setText(QCoreApplication::translate("DatabaseSettingsWidget", "\346\225\260\346\215\256\345\272\223\345\220\215:", nullptr));
        label_3->setText(QCoreApplication::translate("DatabaseSettingsWidget", "\347\224\250\346\210\267\345\220\215:", nullptr));
        label_4->setText(QCoreApplication::translate("DatabaseSettingsWidget", "\345\257\206\347\240\201:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DatabaseSettingsWidget: public Ui_DatabaseSettingsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATABASESETTINGSWIDGET_H
