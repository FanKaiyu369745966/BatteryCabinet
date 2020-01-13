#pragma once

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QtSql/QSqlDatabase>
#include <QLineEdit>
#include <QToolButton>
//#include "ui_DatabaseSettingsWidget.h"

class DatabaseSettingsWidget : public QWidget
{
	Q_OBJECT

public:
	DatabaseSettingsWidget(QWidget* parent = Q_NULLPTR);
	~DatabaseSettingsWidget();

private:
	//Ui::DatabaseSettingsWidget ui;

private:
	QString m_strHost;		/*!< 数据库的地址/源地址 */
	QString m_strName;		/*!< 数据库的名称 */
	QString	m_strUser;		/*!< 用户名 */
	QString m_strPassword;	/*!< 密码 */

private:
	//QLabel* m_labConn;		/*!< 用以测试连接结果的label标签 */
	QLineEdit* m_editHost;		/*!< 获取数据库主机名的编辑框 */
	QLineEdit* m_editName;		/*!< 获取数据库名的编辑框 */
	QLineEdit* m_editUser;		/*!< 获取用户名的编辑框 */
	QLineEdit* m_editPassword;	/*!< 获取用户密码的编辑框 */
	bool m_bTested;

private:
	QSqlDatabase m_db;			/*!< 测试数据库连接的数据库对象 */

private:
	/*!
	 * @brief 初始化控件
	 * @date 2020/01/12
	 * @author FanKaiyu
	 */
	void Initialize();

public:
	/*!
	 * @brief 设置默认的数据库主机名
	 * @date 2020/01/12
	 * @author FanKaiyu
	 * @param const QString &
	 */
	void SetDefaultHost(const QString& host);

	/*!
	 * @brief 设置默认的数据库名
	 * @date 2020/01/12
	 * @author FanKaiyu
	 * @param const QString &
	 */
	void SetDefaultName(const QString& name);
	/*!
	 * @brief 设置默认的用户名
	 * @date 2020/01/12
	 * @author FanKaiyu
	 * @param const QString &
	 */
	void SetDefaultUser(const QString& user);

	/*!
	 * @brief 设置默认的密码
	 * @date 2020/01/12
	 * @author FanKaiyu
	 * @param const QString &
	 */
	void SetDefaultPassword(const QString& password);

	/*!
	 * @brief 获取数据的地址/源地址
	 * @date 2020/01/12
	 * @author FanKaiyu
	 * @return QT_NAMESPACE::QString 数据库地址
	 */
	QString host() const { return m_strHost; }

	/*!
	 * @brief 获取数据库名称
	 * @date 2020/01/12
	 * @author FanKaiyu
	 * @return QT_NAMESPACE::QString 数据库名称
	 */
	QString name() const { return m_strName; }

	/*!
	 * @brief 获取用户名
	 * @date 2020/01/12
	 * @author FanKaiyu
	 * @return QT_NAMESPACE::QString 用户名
	 */
	QString user() const { return m_strUser; }

	/*!
	 * @brief 获取密码
	 * @date 2020/01/12
	 * @author FanKaiyu
	 * @return QT_NAMESPACE::QString 密码
	 */
	QString password() const { return m_strPassword; }

	/*!
	 * @brief 判断当前配置是否已经测试
	 * @date 2020/01/12
	 * @author FanKaiyu
	 * @return bool 测试过返回true,否则返回false
	*/
	bool IsTested() const { return m_bTested; }
signals:
	//void Submited();
private slots:
	/*!
	 * @brief 点击测试按钮时触发的槽函数
	 * @date 2020/01/12
	 * @author FanKaiyu
	 */
	void onClickButtonTest(bool bClicked = false);

	/*!
	 * @brief 点击显示密码按钮时触发的槽函数
	 * @date 2020/01/12
	 * @author FanKaiyu
	 * @param bool bClicked
	 */
	void onClickCheckPassword(bool bClicked = false);

	/*!
	 * @brief 点击设置按钮时触发的槽函数
	 * @date 2020/01/12
	 * @author FanKaiyu
	 */
	void onClickButtonSumbit(bool bClicked = false);

	/*!
	 * @brief 编辑框文本内容改变时触发的槽函数
	 * @date 2020/01/12
	 * @author FanKaiyu
	 */
	void onEditTextChanged(const QString& text);
};
