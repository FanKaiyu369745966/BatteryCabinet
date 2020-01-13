#include "CheckBoxEx.h"

CheckBoxEx::CheckBoxEx(QWidget *parent) : QCheckBox(parent)
{
    setStyleSheet("QCheckBox::indicator{width: 16px;height: 16px;background-color: #DDDDDD; border: 1px solid #22252A;}\
                  QCheckBox::indicator::checked{background-color: #D13C4F;}\
                  QCheckBox::indicator:disabled{background-color: #22252A;}\
                    QCheckBox::indicator::hover{background-color: #DB6574}\
                    QCheckBox::checked{font: 10pt Microsoft YaHei;  color:#FFFFFF}\
                    QCheckBox::!checked{font: 10pt Microsoft YaHei;  color:#CCCCCC}");

}
