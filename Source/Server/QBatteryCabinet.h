#pragma once

#include <QObject>
#include <QTcpSocket>
#include <QSqlDatabase>
#include <QJsonObject>
#include <QMutex>
#include <mutex>
#include <thread>
#include <map>
#include "QBatteryBox.h"

/*!
 * @class QBatteryCabinet
 * @brief 电池柜
 *
 * 描述电池柜基本属性与动作的类
 * @date 2020-01-09
 * @author FanKaiyu
*/
class QBatteryCabinet : public QObject
{
	Q_OBJECT

public:
	explicit QBatteryCabinet(const QSqlDatabase& _db, QMutex& _mutex, QTcpSocket* socket, QObject* parent = nullptr);
	~QBatteryCabinet();
protected:
	QString m_strCode;							/*!< 电池柜编号 */
	std::map<QString, QBatteryBox*> m_mapBoxs;	/*!< 电池盒组 */
	QTcpSocket* m_socket;						/*!< 客户端指针 */
	QSqlDatabase m_db;							/*!< 数据库对象 */
	std::thread m_thread;
	bool m_bDestory;
	QByteArray m_buffer;
	QMutex& m_mutex;

public:
	/*!
	 * @brief 绑定电池柜
	 *
	 * 向电池柜发送绑定申请
	 * {“cmd”:”200”}
	 * @date 2020-01-09
	 * @author FanKaiyu
	*/
	void Bind();

protected:
	/*!
	 * @brief 绑定电池柜成功
	 *
	 * 向电池柜发送绑定成功
	 * {”cmd”:101,”data”:{“cabinetcode”:”xxx电池柜编号”}}
	 * @date 2020-01-09
	 * @author FanKaiyu
	*/
	void BindSuccess();

public:
	/*!
	 * @brief 添加电池盒
	 * @date 2020-01-09
	 * @author FanKaiyu
	 * @param const QString& 电池盒编号
	*/
	void AddBox(const QString& _no);

	/*!
	 * @brief 更新电池盒状态
	 * @date 2020-01-09
	 * @author FanKaiyu
	 * @param const QString& 电池盒编号
	 * @param const int& 状态指令码
	*/
	void UpdateBoxStatus(const QString& _code, const int& _cmd);

public:
	/*!
	 * @brief 打开电池盒
	 * @date 2020-01-09
	 * @author FanKaiyu
	 * @param const QString& 电池盒编号
	*/
	void OpenBox(const QString& _code);

protected:
	/*!
	 * @brief 解析指令报文
	 * @date 2020-01-09
	 * @author FanKaiyu
	 * @param const QJsonObject& JSON格式命令符
	*/
	void ProcessCommand(const QJsonObject& _json);

	/*!
	 * @brief 写入数据库日志
	 * @date 2020-01-09
	 * @author FanKaiyu
	 * @param const QString& 记录类型
	 * @param const QString& 记录内容
	 * @param cosnt QString& 充电盒编号
	*/
	void WriteToLogDataBase(const QString& _type, const QString& _info, const QString _box = "");

	/*!
	 * @brief 清除电池盒开启指令标识
	 * @date 2020-01-09
	 * @author FanKaiyu
	 * @param cosnt QString& 充电盒编号
	*/
	void ClearBoxOpenCmd(const QString& _code);

	/*!
	 * @brief 扫描电池盒
	 * @date 2020-01-09
	 * @author FanKaiyu
	*/
	void ScanBoxList();

	/*!
	 * @brief 线程循环
	*/
	void slotThread();

protected:
	/*! @brief 充电柜命令符枚举 */
	enum CmdCode
	{
		Cmd_Open = 11,		/*!< 打开柜门 */
		Cmd_Bind = 100,		/*!< 绑定充电柜 */
		Cmd_BindSuccess,	/*!< 绑定成功 */
		Cmd_Request = 200,	/*!< 握手请求/请求绑定充电柜 */
	};
public slots:
	/*!
	 * @brief 客户端中断连接
	*/
	void slotDisconnected();

	/*!
	 * @brief 读取数据
	*/
	void slotReadyRead();
};
