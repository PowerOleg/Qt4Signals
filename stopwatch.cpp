#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent}, lap_count{0}
{
    this->time = new QTime(0,0,0,0);
    this->lap = new QTime(0,0,0,0);
    this->timer = new QTimer();
}

Stopwatch::~Stopwatch()
{
    qDebug() << "Stopwatch's deleted";
}

void Stopwatch::Start()
{
    this->timer->start(100);
}

void Stopwatch::Stop()
{
    this->timer->stop();
}

 void Stopwatch::Clear()
 {
    this->time->setHMS(0,0,0,0);
    this->lap->setHMS(0,0,0,0);
    this->lap_count = 0;
 }

void Stopwatch::SendSignal()
{
    emit sig_SendSignal();
}

QString Stopwatch::ShowTime()
{
    return this->time->toString("hh::mm::ss::z"); //QString::number(hour) + "::" + QString::number(min) + "::" + QString::number(sec);
}

QString Stopwatch::ShowLap()//Круг N, время: M сек
{
    int hour = this->lap->hour();
    int min = this->lap->minute();
    int sec = this->lap->second();
    for (int var = 0; var < hour; ++var) {
        sec += 3600;
    }
    for (int var = 0; var < min; ++var) {
        sec += 60;
    }

    QString text_lap = "Круг " + QString::number(++lap_count) + " , время: " + QString::number(sec) + " сек";
    this->lap->setHMS(0,0,0,0);
    return text_lap;
}

void Stopwatch::Add100Millisec()
{
    *time = time->addMSecs(100);
    *lap = lap->addMSecs(100);
}

QTimer *Stopwatch::getTimer() const
{
    return timer;
}
