#include <QtWidgets/QApplication>
#include "mainwindow.h"
#include "SettingsWidget.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	//mainwindow w;
	SettingsWidget w;
	w.show();
	return a.exec();
}
