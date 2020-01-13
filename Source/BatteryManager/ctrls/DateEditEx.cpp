#include "DateEditEx.h"


DateEditEx::DateEditEx(QWidget *parent) : QDateEdit(parent)
{
    init();
}
void DateEditEx::init()
{
    setStyleSheet("QDateEdit {border-radius: 5px; border:1px solid #868E96; background:#2D3035;\
                  font-size:10pt; font-family:Microsoft YaHei; color:#FFEDD6}\
                  QDateEdit:enabled:hover{background:#868E96; border:1px solid #868E96; color:#F7FDF1}\
                  QDateEdit:enabled:focus{background:#2D3035; border:1px solid #DB6574; color:#979A9F}\
                  QDateEdit:!enabled {background:#8A8D93; color:#595F65}\
                  QDateEdit QAbstractItemView {border:1px solid #393C43; background:#2D3035; font-size:10pt; font-family:Microsoft YaHei; color:#646466;}\
                  QDateEdit QAbstractItemView::item {height:30px; color:#777777;}\
                  QDateEdit QAbstractItemView::item:hover {background:#2D3035; color:#DB6574}");
}
