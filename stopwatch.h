#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QDebug>

class Stopwatch : QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();
    void send_signal();
signals:
    void sig_send_signal();
};

#endif // STOPWATCH_H
