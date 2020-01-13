#ifndef DATEEDITEX_H
#define DATEEDITEX_H


#include <QDateEdit>
#include <QListView>

class DateEditEx : public QDateEdit
{
    Q_OBJECT
public:
    explicit DateEditEx(QWidget *parent = 0);
private:
    void init();
};

#endif // DATEEDITEX_H
