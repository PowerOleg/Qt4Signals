#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font("Times", 28, QFont::Bold);
    ui->lb_time->setFont(font);
    this->stopwatch = new Stopwatch(this);
    //connect(stopwatch, &Stopwatch::sig_send_signal, this, &MainWindow::slot_timer);
    connect(this->stopwatch->getTimer(), &QTimer::timeout, this, &MainWindow::slot_timer, static_cast<Qt::ConnectionType>(Qt::AutoConnection | Qt::UniqueConnection));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_timer()
{
    this->stopwatch->Add100Millisec();
    ui->lb_time->setText(stopwatch->ShowTime());
}

void MainWindow::on_btn_start_clicked()
{
    if (!QString::compare(ui->btn_start->text(), "старт", Qt::CaseInsensitive))
    {
        ui->btn_start->setText("Стоп");
        this->stopwatch->Start();
    }
    else
    {
        ui->btn_start->setText("Старт");
        this->stopwatch->Stop();
    }
}

void MainWindow::on_btn_stop_clicked()
{
    this->stopwatch->Clear();
    ui->lb_time->setText(stopwatch->ShowTime());
}

void MainWindow::on_btn_setLap_reset_clicked()
{
    ui->tb_stop->setText(stopwatch->ShowLap());
}
