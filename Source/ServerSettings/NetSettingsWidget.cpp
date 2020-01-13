#include "NetSettingsWidget.h"
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>
#include <QDebug>

NetSettingsWidget::NetSettingsWidget(QWidget* parent)
	: QWidget(parent)
	, m_strIp("")
	, m_usPort(0)
	, m_comboIp(nullptr)
	, m_spinPort(nullptr)
{
	//ui.setupUi(this);
	Initialize();
}

NetSettingsWidget::~NetSettingsWidget()
{
}

void NetSettingsWidget::Initialize()
{
	QLabel* _labIp = new QLabel(QString::fromLocal8Bit("IP地址:"), this);
	QLabel* _labPort = new QLabel(QString::fromLocal8Bit("端口:"), this);

	_labIp->setAlignment(Qt::AlignRight | Qt::AlignHCenter | Qt::AlignVCenter);
	_labPort->setAlignment(Qt::AlignRight | Qt::AlignHCenter | Qt::AlignVCenter);

	QVBoxLayout* _vlayoutLab = new QVBoxLayout();
	_vlayoutLab->addStretch();
	_vlayoutLab->addWidget(_labIp);
	_vlayoutLab->addStretch();
	_vlayoutLab->addWidget(_labPort);
	_vlayoutLab->addStretch();

	m_comboIp = new QComboBox(this);
	m_spinPort = new QSpinBox(this);

	m_comboIp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	m_spinPort->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	m_comboIp->setEditable(true);
	m_spinPort->setMaximum(0xFFFF);
	m_spinPort->setMinimum(0);

	foreach(const QHostAddress & hostAddress, QNetworkInterface::allAddresses())
	{
		if (/*hostAddress != QHostAddress::LocalHost &&*/ hostAddress.toIPv4Address())
		{
			m_comboIp->addItem(hostAddress.toString());
		}
	}

	m_comboIp->setCurrentIndex(-1);

	QObject::connect(m_comboIp, &QComboBox::currentTextChanged, this, &NetSettingsWidget::onComboTextChanged);
	QObject::connect(m_spinPort, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &NetSettingsWidget::onSpinValueChanged);

	QVBoxLayout* _vlayout = new QVBoxLayout();
	_vlayout->addStretch();
	_vlayout->addWidget(m_comboIp);
	_vlayout->addStretch();
	_vlayout->addWidget(m_spinPort);
	_vlayout->addStretch();

	QHBoxLayout* _hlayout = new QHBoxLayout();
	_hlayout->addLayout(_vlayoutLab);
	_hlayout->addLayout(_vlayout);

	setLayout(_hlayout);

	return;
}


void NetSettingsWidget::onComboTextChanged(const QString& text)
{
	QHostAddress addr(text);

	if (addr.toIPv4Address() == 0)
	{
		return;
	}

	m_strIp = text;

	return;
}

void NetSettingsWidget::SetIp(const QString& ip)
{
	m_strIp = ip;

	if (m_comboIp)
	{
		m_comboIp->setEditText(m_strIp);
	}

	return;
}

void NetSettingsWidget::SetPort(const quint16& port)
{
	m_usPort = port;

	if (m_spinPort)
	{
		m_spinPort->setValue(m_usPort);
	}

	return;
}

void NetSettingsWidget::onSpinValueChanged(int i)
{
	m_usPort = static_cast<quint16>(i);

	return;
}
