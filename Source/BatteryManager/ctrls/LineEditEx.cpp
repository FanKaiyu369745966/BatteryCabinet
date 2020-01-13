#include "LineEditEx.h"

LineEditEx::LineEditEx(QWidget *parent) : QLineEdit(parent)
{
    init();
}
void LineEditEx::init()
{
    setStyleSheet("QLineEdit{background:#2D3035; border:1px solid #979A9F; border-radius:5px; \
                  font-size:12pt; font-family:Microsoft YaHei; color:#979A9F} \
                  QLineEdit:enabled:focus {background:#2D3035; border:1px solid #DB6574;}\
                  QLineEdit:!enabled {background: #CCCCCC;}");
}
