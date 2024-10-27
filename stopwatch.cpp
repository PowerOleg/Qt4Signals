#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent}, hour{0}, min{0}, sec{0}
{}

Stopwatch::~Stopwatch()
{
    qDebug() << "Stopwatch's deleted";
}

void Stopwatch::send_signal()
{
    emit sig_send_signal();
}


QString Stopwatch::make_time()
{
    QString result =  QString::number(hour) + "::" + QString::number(min) + "::" + QString::number(sec);
    return result;
}

void Stopwatch::add_sec()
{
    ++sec;
    if (sec == 60)
    {
        ++min;
        sec = 0;
    }

    if (min == 60)
    {
        ++hour;
        min = 0;
    }

}
