#include "NetSettingsWidget.h"

NetSettingsWidget::NetSettingsWidget(QWidget* parent)
	: QWidget(parent)
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

	QComboBox* _comboIp = new QComboBox(this);
	QSpinBox* _spinPort = new QSpinBox(this);

	_comboIp->setEditable(true);

	_comboIp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
	_spinPort->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);

	QVBoxLayout* _vlayout = new QVBoxLayout();
	_vlayout->addStretch();
	_vlayout->addWidget(_comboIp);
	_vlayout->addStretch();
	_vlayout->addWidget(_spinPort);
	_vlayout->addStretch();

	QHBoxLayout* _hlayout = new QHBoxLayout();
	_hlayout->addLayout(_vlayoutLab);
	_hlayout->addLayout(_vlayout);

	setLayout(_hlayout);

	return;
}
