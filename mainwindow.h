#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QFont>
#include <QDebug>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    Stopwatch* stopwatch;
public slots:
    void slot_timer();

//private slots:
//    void on_pb_send_signal_clicked();
private slots:
    void on_btn_start_clicked();
};
#endif // MAINWINDOW_H
