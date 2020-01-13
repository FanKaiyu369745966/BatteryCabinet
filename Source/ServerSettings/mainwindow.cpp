#include "mainwindow.h"
#include "SettingsWidget.h"

mainwindow::mainwindow(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setWindowTitle(QString::fromLocal8Bit("电池柜服务端环境配置"));

	setCentralWidget(new SettingsWidget(this));
}

mainwindow::~mainwindow()
{
}
