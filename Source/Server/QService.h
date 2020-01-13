#pragma once

#include <QObject>
#include <QTcpServer>
#include "QBatteryCabinet.h"

class QService : public QObject
{
	Q_OBJECT

public:
	QService(QObject* parent = nullptr);
	~QService();

protected:
	QTcpServer m_server;
	QSqlDatabase m_db;
	QMutex m_mutex;
public:
	/*!
	 * @brief 启动
	 * @return bool 启动成功返回true,否则返回false
	*/
	bool Start();
protected:
	/*!
	 * @brief 写入数据库日志
	 * @date 2020-01-09
	 * @author FanKaiyu
	 * @param const QString& 记录类型
	 * @param const QString& 记录内容
	*/
	void WriteToLogDataBase(const QString& _type, const QString& _info);
private slots:
	/*!
	 * @brief 接收客户端连接
	*/
	void slotNewConnection();

	/*!
	 * @brief 接收客户端连接异常
	 * @param QAbstractSocket::SocketError
	*/
	void slotAcceptError(QAbstractSocket::SocketError);
};
