#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QDebug>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();
    void send_signal();
    QString make_time();
    void add_sec();
signals:
    void sig_send_signal();
private:
    int hour;
    int min;
    int sec;
};

#endif // STOPWATCH_H
