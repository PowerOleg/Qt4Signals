#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font("Times", 28, QFont::Bold);
    ui->lb_time->setFont(font);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slot_timer()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_timer()
{
//TODO
    ui->lb_time->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void MainWindow::on_btn_start_clicked()
{
    //connect(timer, SIGNAL(timeout()), this, SLOT(slot_timer()));
    //timer->start(1000);
}

