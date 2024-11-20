#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTimer>
#include <QPainter>
#include <QFont>
#include <QTime>
#include <QGeoCoordinate>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QQuickView>
#include <QtQuickWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbDevice_clicked();

    void on_pbClock_clicked();

    void on_pbMap_clicked();

    void on_pbWeather_clicked();

    void on_pbBmi_clicked();

    void on_pbCount_clicked();

    void on_pbTimestamp_clicked();

    void on_pbUuid_clicked();

    void on_pbHome_clicked();

    void on_pbShare_clicked();

private:
    Ui::MainWindow *ui;

    QTimer *timer;

    void showDateTime();

    void showClock();

    void showWeather();

    void showBmi();

    void showCountDown();

    void showTimestamp();

    void showConvertTimestamp();

    void showUuid();
};

#endif // MAINWINDOW_H
