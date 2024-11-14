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
    void Start();
    void Stop();
    void Clear();
    void SendSignal();

    QString ShowTime();
    QString ShowLap();
    void Add100Millisec();

    QTimer *getTimer() const;

signals:
    void sig_SendSignal();
private:
    QTimer* timer;
    QTime* time;
    QTime* lap;
    size_t lap_count;
};

#endif // STOPWATCH_H
