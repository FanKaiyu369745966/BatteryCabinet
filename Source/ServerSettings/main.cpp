#include "SettingsWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SettingsWidget w;
	w.show();
	return a.exec();
}
