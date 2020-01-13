#include "ComboBoxEx.h"

ComboBoxEx::ComboBoxEx(QWidget *parent) : QComboBox(parent)
{
    init();
}

void ComboBoxEx::init()
{
    setView(new QListView());
    setStyleSheet("QComboBox {border-radius: 5px; border:1px solid #868E96; background:#2D3035;\
                  font-size:10pt; font-family:Microsoft YaHei; color:#FFEDD6}\
                  QComboBox:enabled:hover{background:#868E96; border:1px solid #868E96; color:#F7FDF1}\
                  QComboBox:enabled:focus{background:#868E96; border:3px solid #595F65; color:#F4FDFF}\
                  QComboBox:!enabled {background:#8A8D93; color:#595F65}\
                  QComboBox QAbstractItemView {border:1px solid #393C43; background:#2D3035; font-size:10pt; font-family:Microsoft YaHei; color:#646466;}\
                  QComboBox QAbstractItemView::item {height:30px; color:#777777;}\
                  QComboBox QAbstractItemView::item:hover {background:#2D3035; color:#DB6574}");
}
