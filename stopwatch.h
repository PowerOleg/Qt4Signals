#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QDebug>
#include <QTime>
#include <QTimer>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    ~Stopwatch();
    void start();
    void stop();
    void send_signal();
    QString show_time();
    void add_100_millisec();

    QTimer *getTimer() const;

signals:
    void sig_send_signal();
private:
    QTimer* timer;
    QTime* time;
};

#endif // STOPWATCH_H
