#pragma once

#include <QObject>

/*!< 电池盒状态 */
enum BoxStatus
{
	Door_Opened = 12,	/*!< 已开门 */
	Door_OpenFailed,	/*!< 开门失败 */
	Door_Closed = 23,	/*!< 已关门 */
	Door_Error = 32,	/*!< 门异常开启 */
	Battery_Ready = 21,	/*!< 充电完成 */
	Battery_Empty = 24,	/*!< 空柜 */
	Battery_New,		/*!< 新电池 */
	Battery_Error = 31,	/*!< 充电异常 */
};

/*!
 * @class QBatteryBox
 * @brief 电池盒
 *
 * 描述电池盒基础属性以及功能的类
 * @date 2020-01-09
 * @author FanKaiyu
*/
class QBatteryBox : public QObject
{
	Q_OBJECT

public:
	QBatteryBox(QObject* parent = nullptr, const QString& _no = "");
	~QBatteryBox();
protected:
	QString m_strNo;	/*!< 电池盒编号 */

public:
	int m_doorStatus;		/*!< 柜门状态 */
	int m_batteryStatus;	/*!< 电池状态 */
};
