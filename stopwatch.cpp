#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent}
{}

Stopwatch::~Stopwatch()
{
    qDebug() << "Stopwatch's deleted";
}

void Stopwatch::send_signal()
{
    emit sig_send_signal();
}
