#ifndef WAITINGFORM_H
#define WAITINGFORM_H

#include <QWidget>
#include <QMovie>

namespace Ui {
class WaitingForm;
}

class WaitingForm : public QWidget
{
    Q_OBJECT

public:
    explicit WaitingForm(QWidget *parent = nullptr);
    ~WaitingForm();

private:
    Ui::WaitingForm *ui;
    QMovie *m_movie;
};

#endif // WAITINGFORM_H
