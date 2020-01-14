#-------------------------------------------------
#
# Project created by QtCreator 2020-01-09T13:50:29
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BatteryManager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

DESTDIR = ../../Build
LIBS += -L"."
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += .

RC_FILE = logo.rc

SOURCES += \
        main.cpp \
        MainWindow.cpp \
    ctrls/CheckBoxEx.cpp \
    ctrls/ComboBoxEx.cpp \
    ctrls/GroupBoxEx.cpp \
    ctrls/LabelEx.cpp \
    ctrls/LineEditEx.cpp \
    ctrls/MsgBoxEx.cpp \
    ctrls/PushButtonEx.cpp \
    ctrls/TableViewEx.cpp \
    ctrls/TitleBarEx.cpp \
    BatteryLogForm.cpp \
    BatteryCabinetForm.cpp \
    BatteryBoxForm.cpp \
    ctrls/DateEditEx.cpp \
    Config.cpp \
    WaitingForm.cpp

HEADERS += \
        MainWindow.h \
    ctrls/CheckBoxEx.h \
    ctrls/ComboBoxEx.h \
    ctrls/GroupBoxEx.h \
    ctrls/LabelEx.h \
    ctrls/LineEditEx.h \
    ctrls/MsgBoxEx.h \
    ctrls/PushButtonEx.h \
    ctrls/TableViewEx.h \
    ctrls/TitleBarEx.h \
    ctrls/CustomTabStyle.h \
    BatteryLogForm.h \
    BatteryCabinetForm.h \
    BatteryBoxForm.h \
    ctrls/DateEditEx.h \
    logo.rc \
    Config.h \
    WaitingForm.h

FORMS += \
        MainWindow.ui \
    BatteryLogForm.ui \
    BatteryCabinetForm.ui \
    BatteryBoxForm.ui \
    WaitingForm.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
