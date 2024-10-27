#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QDebug>
#include <QTime>


class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();
    void send_signal();
    QString show_time();
    void add_millisec();
signals:
    void sig_send_signal();
private:
    QTime* time;
};

#endif // STOPWATCH_H
