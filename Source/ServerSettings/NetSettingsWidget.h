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
	void Initialize();
};
