#include <QtCore/QCoreApplication>
#include <QSharedMemory>
#include <QProcess>
#include <QDebug>
#include "QService.h"

//#pragma comment( linker, "/subsystem:"windows" /entry:"mainCRTStartup"" )

int main(int argc, char* argv[])
{
	QCoreApplication a(argc, argv);

	QSharedMemory shared("BatteryCabinetServer");
	if (shared.attach())
	{
		qDebug() << QString::fromLocal8Bit("程序已经启动") << endl;
		return 0;
	}

	shared.create(1);

	QService service;
	if (service.Start() == false)
	{
		shared.detach();
		return 0;
	}

	int e = a.exec();

	if (e == 1)
	{
		shared.detach();
		QProcess::startDetached(qApp->applicationFilePath(), QStringList());
		return 0;
	}

	return 0;
}
