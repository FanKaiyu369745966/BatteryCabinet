#include "WaitingForm.h"
#include "ui_WaitingForm.h"

WaitingForm::WaitingForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WaitingForm),
    m_movie(nullptr)
{
    ui->setupUi(this);

    this->setWindowOpacity(0.8);
    setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);//设置为对话框风格，并且去掉边框
    setWindowModality(Qt::WindowModal);//设置为模式对话框，同时在构造该对话框时要设置父窗口
    ui->label->setStyleSheet("background-color: transparent;");
    m_movie = new QMovie("./res/icon/waiting.gif");
    ui->label->setMovie(m_movie);
    ui->label->setScaledContents(true);
    m_movie->start();
}

WaitingForm::~WaitingForm()
{
    m_movie->stop();
    delete ui;
}
