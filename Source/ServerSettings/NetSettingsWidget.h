#pragma once

#include <QWidget>
#include <QSpinbox>
#include <QCombobox>
#include <QLabel>
#include <QLayout>
//#include "ui_NetSettingsWidget.h"

class NetSettingsWidget : public QWidget
{
	Q_OBJECT

public:
	NetSettingsWidget(QWidget* parent = Q_NULLPTR);
	~NetSettingsWidget();

private:
	//Ui::NetSettingsWidget ui;
private:
	QString m_strIp;	/*!< IP地址 */
	quint16 m_usPort;	/*!< 端口号 */
private:
	QComboBox* m_comboIp;
	QSpinBox* m_spinPort;
private:
	void Initialize();

public:
	QString ip() const { return m_strIp; }
	quint16 port() const { return m_usPort; }

	void SetIp(const QString& ip);
	void SetPort(const quint16& port);

private slots:
	void onComboTextChanged(const QString& text);
	void onSpinValueChanged(int i);
};
