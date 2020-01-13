#include "QBatteryCabinet.h"
#include <QJsonDocument>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QException>
#include <QHostAddress>
#include <chrono>

QBatteryCabinet::QBatteryCabinet(const QSqlDatabase& _db, QMutex& _mutex, QTcpSocket* socket, QObject* parent)
	: QObject(parent)
	, m_strCode("")
	, m_socket(socket)
	, m_db(_db)
	, m_thread(&QBatteryCabinet::slotThread, this)
	, m_bDestory(false)
	, m_mutex(_mutex)
{
	QObject::connect(m_socket, &QTcpSocket::readyRead, this, &QBatteryCabinet::slotReadyRead);
	QObject::connect(m_socket, &QTcpSocket::disconnected, this, &QBatteryCabinet::slotDisconnected);
}

QBatteryCabinet::~QBatteryCabinet()
{
	if (m_thread.joinable())
	{
		m_bDestory = true;
		m_thread.join();
	}

	return;
}

void QBatteryCabinet::Bind()
{
	if (m_socket == nullptr)
	{
		return;
	}

	if (m_strCode.isNull() == false && m_strCode.isEmpty() == false)
	{
		return;
	}

	QJsonObject obj;
	obj.insert("cmd", QString("%1").arg(Cmd_Request));

	QString tmp = QString(QJsonDocument(obj).toJson()).replace('\n', "").replace(' ', "");

	// 发送数据至充电柜
	quint64 len = m_socket->write(tmp.toLocal8Bit());
	m_socket->flush();

	if (len == tmp.length())
	{
		WriteToLogDataBase(QString::fromLocal8Bit("发送"), tmp);
	}
	else
	{
		WriteToLogDataBase(QString::fromLocal8Bit("异常"),
			QString("Error:%1 cause write data [%2] failed.")
			.arg(m_socket->errorString())
			.arg(tmp));
	}

	return;
}

void QBatteryCabinet::BindSuccess()
{
	if (m_socket == nullptr)
	{
		return;
	}

	QJsonObject obj, data;
	obj.insert("cmd", QString("%1").arg(Cmd_BindSuccess));
	data.insert("cabinetcode", m_strCode);
	obj.insert("data", data);

	QString tmp = QString(QJsonDocument(obj).toJson()).replace('\n', "").replace(' ', "");

	// 发送数据至充电柜
	quint64 len = m_socket->write(tmp.toLocal8Bit());
	m_socket->flush();

	if (len == tmp.length())
	{
		WriteToLogDataBase(QString::fromLocal8Bit("发送"), tmp);
	}
	else
	{
		WriteToLogDataBase(QString::fromLocal8Bit("异常"),
			QString("Error:%1 cause write data [%2] failed.")
			.arg(m_socket->errorString())
			.arg(tmp));
	}

	return;
}

void QBatteryCabinet::AddBox(const QString& _no)
{
	if (m_strCode.isNull() || m_strCode.isEmpty())
	{
		WriteToLogDataBase(QString::fromLocal8Bit("异常"),
			QString::fromLocal8Bit("新增电池%1失败！未绑定充电柜。").arg(_no)
			, _no);

		return;
	}

	if (m_mapBoxs.find(_no) != m_mapBoxs.end())
	{
		return;
	}

	m_mapBoxs[_no] = new QBatteryBox(this, _no);

	QString sql = QString::fromLocal8Bit("insert into BATTERYDB_INFO_BOX([box_code],[box_cabinet]) values('%1','%2')")
		.arg(_no)
		.arg(m_strCode);

	// 写入数据库
	QSqlQuery query(m_db);

	m_mutex.lock();

	if (query.exec(sql))
	{
		m_mutex.unlock();
		return;
	}

	m_mutex.unlock();

	qDebug() << QString::fromLocal8Bit("写入数据库失败:%1").arg(query.lastError().text()) << endl;

	return;
}

void QBatteryCabinet::UpdateBoxStatus(const QString& _code, const int& _cmd)
{
	if (m_mapBoxs.find(_code) == m_mapBoxs.end())
	{
		return;
	}

	QString param = "";
	bool isOpened = true;

	switch (_cmd)
	{
	case Door_Opened:
		param = "box_door_status";
		m_mapBoxs[_code]->m_doorStatus = _cmd;
		break;
	case Door_OpenFailed:
		param = "box_door_status";
		m_mapBoxs[_code]->m_doorStatus = _cmd;
		break;
	case Door_Closed:
		param = "box_door_status";
		m_mapBoxs[_code]->m_doorStatus = _cmd;
		isOpened = false;
		break;
	case Door_Error:
		param = "box_door_status";
		m_mapBoxs[_code]->m_doorStatus = _cmd;
		break;
	case Battery_Ready:
		param = "box_battery_status";
		m_mapBoxs[_code]->m_batteryStatus = _cmd;
		break;
	case Battery_Empty:
		param = "box_battery_status";
		m_mapBoxs[_code]->m_batteryStatus = _cmd;
		break;
	case Battery_New:
		param = "box_battery_status";
		m_mapBoxs[_code]->m_batteryStatus = _cmd;
		break;
	case Battery_Error:
		param = "box_battery_status";
		m_mapBoxs[_code]->m_batteryStatus = _cmd;
		break;
	default:
		return;
	}

	if (isOpened)
	{
		ClearBoxOpenCmd(_code);
	}

	QString sql = QString::fromLocal8Bit("update BATTERYDB_INFO_BOX set [%1]=%2 where [box_code]='%3' and [box_cabinet]='%4'")
		.arg(param)
		.arg(_cmd)
		.arg(_code)
		.arg(m_strCode);

	// 写入数据库
	QSqlQuery query(m_db);

	m_mutex.lock();

	if (query.exec(sql))
	{
		m_mutex.unlock();
		return;
	}

	m_mutex.unlock();

	qDebug() << QString::fromLocal8Bit("写入数据库失败:%1").arg(query.lastError().text()) << endl;

	return;
}

void QBatteryCabinet::OpenBox(const QString& _code)
{
	if (m_socket == nullptr)
	{
		return;
	}

	if (m_mapBoxs.find(_code) == m_mapBoxs.end())
	{
		return;
	}

	if (m_mapBoxs[_code]->m_doorStatus == Door_Opened)
	{
		ClearBoxOpenCmd(_code);

		return;
	}

	QJsonObject obj, data;
	obj.insert("cmd", QString("%1").arg(Cmd_Open));
	data.insert("boxcode", _code);
	obj.insert("data", data);
	obj.insert("requestclient", "");

	QString tmp = QString(QJsonDocument(obj).toJson()).replace('\n', "").replace(' ', "");

	// 发送数据至充电柜
	quint64 len = m_socket->write(tmp.toLocal8Bit());
	m_socket->flush();

	if (len == tmp.length())
	{
		WriteToLogDataBase(QString::fromLocal8Bit("发送"),
			tmp
			, _code);
	}
	else
	{
		WriteToLogDataBase(QString::fromLocal8Bit("异常"),
			QString::fromLocal8Bit("Error:%1 cause write data [%1] failed.").arg(m_socket->errorString()).arg(tmp)
			, _code);

		ClearBoxOpenCmd(_code);
	}

	return;
}

void QBatteryCabinet::ProcessCommand(const QJsonObject& _json)
{
	if (_json.isEmpty())
	{
		return;
	}

	int cmd = 0;		/*!< 命令符 */
	QJsonValue value = _json.value("cmd");
	if (value.isString())
	{
		cmd = _json.value("cmd").toString().toInt();
	}
	else
	{
		cmd = _json.value("cmd").toInt();
	}
	QJsonObject data = _json.value("data").toObject();	/*!< 数据 */

	QString cabinet = "", box = "";

	switch (cmd)
	{
	case 0:
		return;
	case Cmd_Bind:
	{
		cabinet = data.value("cabinetcode").toString();

		if (cabinet.isNull() || cabinet.isEmpty())
		{
			break;
		}

		m_strCode = cabinet;

		QString sql = QString::fromLocal8Bit("insert into BATTERYDB_INFO_CABINET([cabinet_code],[cabinet_connection],[cabinet_host]) values('%1','%2','%3')")
			.arg(m_strCode)
			.arg(QString::fromLocal8Bit("已连接"))
			.arg(QString("%1:%2")
				.arg(m_socket->peerAddress().toString())
				.arg(m_socket->peerPort()));

		// 写入数据库
		QSqlQuery query(m_db);

		m_mutex.lock();

		if (query.exec(sql))
		{
			m_mutex.unlock();

			// 回复绑定成功
			BindSuccess();
		}
		else
		{
			m_mutex.unlock();

			qDebug() << QString::fromLocal8Bit("写入数据库失败:%1").arg(query.lastError().text()) << endl;
		}

		break;
	}
	default:
	{
		box = data.value("boxcode").toString();

		if (box.isNull() || box.isEmpty())
		{
			break;
		}

		// 添加电池盒
		AddBox(box);

		// 更新电池盒状态
		UpdateBoxStatus(box, cmd);

		break;
	}
	}

	QString tmp = QString(QJsonDocument(_json).toJson()).replace('\n', "").replace(' ', "");

	WriteToLogDataBase(QString::fromLocal8Bit("接收"), tmp, box);

	return;
}

void QBatteryCabinet::WriteToLogDataBase(const QString& _type, const QString& _info, const QString _box)
{
	if (m_socket == nullptr)
	{
		return;
	}

	// 在数据库中增加记录
	QString sql = QString::fromLocal8Bit(
		"insert into BATTERYDB_INFO_LOG([log_cabinet],[log_box],[log_type],[log_info],[log_address]) values('%1','%2','%3','%4','%5')"
	)
		.arg(m_strCode)
		.arg(_box)
		.arg(_type)
		.arg(_info)
		.arg(QString("%1:%2")
			.arg(m_socket->peerAddress().toString())
			.arg(m_socket->peerPort()));

	// 写入数据库
	QSqlQuery query(m_db);

	m_mutex.lock();

	if (query.exec(sql))
	{
		m_mutex.unlock();
		return;
	}

	m_mutex.unlock();

	qDebug() << QString::fromLocal8Bit("写入数据库失败:%1").arg(query.lastError().text()) << endl;

	return;
}

void QBatteryCabinet::ClearBoxOpenCmd(const QString& _code)
{
	QString sql = QString::fromLocal8Bit("update BATTERYDB_INFO_BOX set [box_cmd_open]=0 where [box_code]='%1' and [box_cabinet]='%2'")
		.arg(_code)
		.arg(m_strCode);

	// 写入数据库
	QSqlQuery query(m_db);

	m_mutex.lock();

	if (query.exec(sql))
	{
		m_mutex.unlock();
		return;
	}

	m_mutex.unlock();

	qDebug() << QString::fromLocal8Bit("写入数据库失败:%1").arg(query.lastError().text()) << endl;

	return;
}

void QBatteryCabinet::ScanBoxList()
{
	if (m_strCode.isNull() || m_strCode.isEmpty())
	{
		Bind();

		return;
	}

	QString sql = QString::fromLocal8Bit("select [box_code],[box_door_status],[box_battery_status],[box_cmd_open] from BATTERYDB_INFO_BOX where [box_cabinet]='%1'")
		.arg(m_strCode);

	QSqlQuery query(m_db);

	m_mutex.lock();

	if (query.exec(sql) == false)
	{
		m_mutex.unlock();

		return;
	}

	m_mutex.unlock();

	while (query.next())
	{
		QString code = query.value("box_code").toString();

		int door = query.value("box_door_status").toInt();
		int battery = query.value("box_battery_status").toInt();

		if (m_mapBoxs.find(code) == m_mapBoxs.end())
		{
			m_mapBoxs[code] = new QBatteryBox(this, code);
		}

		if (door != 0 && m_mapBoxs[code]->m_doorStatus != door)
		{
			m_mapBoxs[code]->m_doorStatus = door;
		}

		if (battery != 0 && m_mapBoxs[code]->m_batteryStatus != battery)
		{
			m_mapBoxs[code]->m_batteryStatus = battery;
		}

		if (query.value("box_cmd_open").toInt() != 0)
		{
			OpenBox(code);
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	return;
}

void QBatteryCabinet::slotDisconnected()
{
	m_bDestory = true;

	QString sql = QString::fromLocal8Bit("update BATTERYDB_INFO_CABINET set [cabinet_connection]='%1' where [cabinet_code]='%2'")
		.arg(QString::fromLocal8Bit("未连接"))
		.arg(m_strCode);

	// 写入数据库
	QSqlQuery query(m_db);

	m_mutex.lock();

	query.exec(sql);

	m_mutex.unlock();

	WriteToLogDataBase(QString::fromLocal8Bit("日志"),
		QString::fromLocal8Bit("客户端中断连接"));

	m_socket = nullptr;

	return;
}

void QBatteryCabinet::slotReadyRead()
{
	if (m_socket->isReadable() == false)
	{
		return;
	}

	QByteArray buf = m_buffer + m_socket->readAll();

	m_buffer.clear();

	QByteArrayList list = buf.split('|');

	for (QByteArrayList::const_iterator it = list.begin(); it != list.end(); ++it)
	{
		qDebug() << *it << endl;

		QJsonObject obj = QJsonDocument::fromJson(*it).object();

		if (obj.isEmpty())
		{
			m_buffer = *it;
			continue;
		}

		ProcessCommand(QJsonDocument::fromJson(*it).object());
	}

	return;
}

void QBatteryCabinet::slotThread()
{
	while (m_bDestory == false)
	{
		ScanBoxList();

		std::this_thread::sleep_for(std::chrono::seconds(30));
	}

	return;
}
