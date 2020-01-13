#include "PushButtonEx.h"


PushButtonEx::PushButtonEx(QWidget *parent) : QPushButton(parent)
{
    init();
}


void PushButtonEx::init()
{
    setStyleSheet("QPushButton{background:#DB6574; border-radius:5px; font-size:10pt; font-family:Microsoft YaHei; color:#FFFFFF} \
                  QPushButton::hover{background:#D44658; color:#FFFCFA} \
                  QPushButton::pressed{background:#D13C4F; color:#FFFCF9; border: 3px solid #844B54}");
}
