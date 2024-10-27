#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent}
{
    time = new QTime(0,0,0,0);
}

Stopwatch::~Stopwatch()
{
    qDebug() << "Stopwatch's deleted";
}

void Stopwatch::send_signal()
{
    emit sig_send_signal();
}


QString Stopwatch::show_time()
{
    return time->toString("hh::mm::ss");    //QString::number(hour) + "::" + QString::number(min) + "::" + QString::number(sec);
}

void Stopwatch::add_millisec()
{
    *time = time->addMSecs(1);
}
