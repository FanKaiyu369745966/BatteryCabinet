#include "QService.h"
#include <QSqlQuery>
#include <QtXml>
#include <QSqlError>

QService::QService(QObject* parent)
	: QObject(parent)
	, m_server(this)
	, m_db(QSqlDatabase::addDatabase("QODBC3"))
{
	QObject::connect(&m_server, &QTcpServer::acceptError, this, &QService::slotAcceptError);
	QObject::connect(&m_server, &QTcpServer::newConnection, this, &QService::slotNewConnection);
}

QService::~QService()
{
	m_server.close();
}

bool QService::Start()
{
	QFile file("Config/config.xml");
	if (!file.open(QFile::ReadOnly))
	{
		return false;
	}

	QDomDocument doc;
	QString strError;
	if (!doc.setContent(&file, &strError))
	{
		qDebug() << strError << endl;
		file.close();
		return false;
	}

	file.close();

	QDomElement root = doc.documentElement(); //返回根节点

	QDomNode node = root.firstChild(); //获得第一个子节点

	while (!node.isNull())  //如果节点不空
	{
		if (node.isElement()) //如果节点是元素
		{
			QDomElement e = node.toElement(); //转换为元素，注意元素和节点是两个数据结构，其实差不多

			QString name = e.tagName();

			if (name == "Database")
			{
				QString serverName = e.attribute("Source");
				QString databaseName = e.attribute("Name");
				QString loginName = e.attribute("User");
				QString passwd = e.attribute("Password");

				m_db.setDatabaseName(QString("DRIVER={SQL SERVER};"
					"SERVER=%1;"
					"DATABASE=%2;"
					"UID=%3;"
					"PWD=%4;").arg(serverName).arg(databaseName).arg(loginName).arg(passwd));

				if (!m_db.open())
				{
					qDebug() << "Open datebase failed," << m_db.lastError().text() << endl;

					return false;
				}
			}
			else if (name == "Server")
			{
				QString ip = e.attribute("IP");
				QString port = e.attribute("Port");

				if (port.isNull() || port.isEmpty())
				{
					return false;
				}

				if (ip.isNull() || ip.isEmpty())
				{
					if (m_server.listen(QHostAddress::Any, port.toInt()) == false)
					{
						qDebug() << QString::fromLocal8Bit("服务端启动失败,请检查地址[%1:%2是]否被占用")
							.arg(m_server.serverAddress().toString())
							.arg(m_server.serverPort())
							<< endl;
						return false;
					}
				}
				else
				{
					if (m_server.listen(QHostAddress(ip), port.toInt()) == false)
					{
						qDebug() << QString::fromLocal8Bit("服务端启动失败,请检查地址[%1:%2是]否被占用")
							.arg(m_server.serverAddress().toString())
							.arg(m_server.serverPort())
							<< endl;

						return false;
					}
				}
			}
		}

		node = node.nextSibling(); //下一个兄弟节点,nextSiblingElement()是下一个兄弟元素，都差不多
	}

	WriteToLogDataBase(QString::fromLocal8Bit("日志")
		, QString::fromLocal8Bit("程序启动"));

	return true;
}

void QService::WriteToLogDataBase(const QString& _type, const QString& _info)
{
	// 在数据库中增加记录
	QString sql = QString::fromLocal8Bit(
		"insert into BATTERYDB_INFO_LOG([log_cabinet],[log_box],[log_type],[log_info],[log_address]) values('%1','%2','%3','%4','%5')"
	)
		.arg("")
		.arg("")
		.arg(_type)
		.arg(_info)
		.arg(QString("%1:%2")
			.arg(m_server.serverAddress().toString())
			.arg(m_server.serverPort()));

	// 写入数据库
	QSqlQuery query(m_db);

	std::lock_guard<QMutex> lock(m_mutex);

	if (query.exec(sql))
	{
		return;
	}

	qDebug() << QString::fromLocal8Bit("写入数据库失败:%1").arg(query.lastError().text()) << endl;

	return;
}

void QService::slotNewConnection()
{
	while (m_server.hasPendingConnections())
	{
		QTcpSocket* socket = m_server.nextPendingConnection();

		WriteToLogDataBase(QString::fromLocal8Bit("日志")
			, QString::fromLocal8Bit("接入客户端[%1:%2]")
			.arg(socket->peerAddress().toString())
			.arg(socket->peerPort()));

		QBatteryCabinet* ptr = new QBatteryCabinet(m_db, m_mutex, socket);

		QObject::connect(socket, &QTcpSocket::disconnected, ptr, &QBatteryCabinet::deleteLater);
	}

	return;
}

void QService::slotAcceptError(QAbstractSocket::SocketError error)
{
	WriteToLogDataBase(QString::fromLocal8Bit("异常")
		, QString::fromLocal8Bit("监听异常,程序重启.Error:%1").arg(m_server.errorString()));

	qApp->exit(1);

	return;
}
