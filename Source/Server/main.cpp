#include <QtCore/QCoreApplication>
#include <QSharedMemory>
#include <QProcess>
#include "QService.h"

//#pragma comment( linker, "/subsystem:"windows" /entry:"mainCRTStartup"" )

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	QSharedMemory shared("BatteryCabinetServer");
	if (shared.attach())
	{
		return 0;
	}

	shared.create(1);

	QService service;
	if (service.Start() == false)
	{
		return 0;
	}

	int e = a.exec();

	if (e == 1)
	{
		QProcess::startDetached(qApp->applicationFilePath(), QStringList());
		return 0;
	}

	return 0;
}
