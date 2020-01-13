#include "QBatteryBox.h"
#include <QDebug>

QBatteryBox::QBatteryBox(QObject* parent, const QString& _no)
	: QObject(parent)
	, m_strNo(_no)
	, m_batteryStatus(Battery_Empty)
	, m_doorStatus(Door_Closed)
{
}

QBatteryBox::~QBatteryBox()
{
}
