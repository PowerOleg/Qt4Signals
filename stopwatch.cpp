#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent}
{
    this->time = new QTime(0,0,0,0);
    this->timer = new QTimer();
}

Stopwatch::~Stopwatch()
{
    qDebug() << "Stopwatch's deleted";
}

void Stopwatch::start()
{
    this->timer->start(100);
}

void Stopwatch::stop()
{
    this->timer->stop();
}

void Stopwatch::send_signal()
{
    emit sig_send_signal();
}

QString Stopwatch::show_time()
{
    return time->toString("hh::mm::ss");    //QString::number(hour) + "::" + QString::number(min) + "::" + QString::number(sec);
}

void Stopwatch::add_100_millisec()
{
    *time = time->addMSecs(100);
}

QTimer *Stopwatch::getTimer() const
{
    return timer;
}
