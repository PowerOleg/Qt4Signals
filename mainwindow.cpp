#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font("Times", 28, QFont::Bold);
    ui->lb_time->setFont(font);

    this->timer = new QTimer();
    this->stopwatch = new Stopwatch(this);
    //connect(stopwatch, &Stopwatch::sig_send_signal, this, &MainWindow::slot_timer);
    connect(timer, &QTimer::timeout, this, &MainWindow::slot_timer, static_cast<Qt::ConnectionType>(Qt::AutoConnection | Qt::UniqueConnection));//Unique_PTR в тему использую? чтобы единожды вызывался сигнал
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_timer()
{
    stopwatch->add_sec();
    ui->lb_time->setText(stopwatch->make_time());//QTime::currentTime().toString("hh:mm:ss")
}

void MainWindow::on_btn_start_clicked()
{
    if (!QString::compare(ui->btn_start->text(), "старт", Qt::CaseInsensitive))
    {
        ui->btn_start->setText("Стоп");
        this->timer->start(1000);
    }
    else
    {
        ui->btn_start->setText("Старт");
        this->timer->stop();
    }
}

