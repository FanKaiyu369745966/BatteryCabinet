#include "GroupBoxEx.h"

GroupBoxEx::GroupBoxEx(QWidget *parent) : QGroupBox(parent)
{
    setStyleSheet("QGroupBox::title{background:#22252A; color:#CCCCCC; subcontrol-origin: margin;\
                   subcontrol-position: top; padding: 18 1000px;}\
                   QGroupBox{border: 1px solid #000000; font: 12pt Microsoft YaHei;}");
}
