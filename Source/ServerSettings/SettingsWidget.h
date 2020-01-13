#pragma once

#include <QtWidgets/QWidget>
#include <QtWidgets/QTabWidget>	
#include <QtWidgets/QTabBar>
#include <QStandardItemModel>
#include <QtXml>
#include "ui_SettingsWidget.h"
#include "DatabaseSettingsWidget.h"	
#include "NetSettingsWidget.h"

class SettingsWidget : public QWidget
{
	Q_OBJECT

public:
	SettingsWidget(QWidget* parent = Q_NULLPTR);

private:
	//Ui::SettingsWidgetClass ui;

private:
	//QTabWidget* m_tab;
	DatabaseSettingsWidget* m_dbSettings;
	NetSettingsWidget* m_netSettings;
private:
	/*!
	 * @brief 初始化控件
	 * @date 2020/01/12
	 * @author FanKaiyu
	 */
	void Initialize();

private slots:
	/*!
	 * @brief 点击重启服务端按钮触发的槽函数
	 * @date 2020/01/12
	 * @author FanKaiyu
	 */
	void onClickButtonRestart(bool bClicked = false);

	/*!
	 * @brief 点击提交修改按钮触发的槽函数
	 * @date 2020/01/12
	 * @author FanKaiyu
	 */
	void onClickButtonSumbit(bool bClicked = false);
};
