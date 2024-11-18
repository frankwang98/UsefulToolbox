#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "utils.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("DevFrank实用工具箱");

    ui->stackedWidget->setCurrentWidget(ui->pageHome);
    ui->pbHome->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbDevice_clicked()
{
    qDebug() << "pbDevice";
    ui->stackedWidget->setCurrentWidget(ui->pageDevice);
    ui->pbHome->show();

    ui->tbOS->setText(getSysInfo());
}

void MainWindow::on_pbClock_clicked()
{
    qDebug() << "pbClock";
}

void MainWindow::on_pbMap_clicked()
{
    qDebug() << "pbMap";
}

void MainWindow::on_pbWeather_clicked()
{
    qDebug() << "pbWeather";
}

void MainWindow::on_pbBmi_clicked()
{
    qDebug() << "pbBmi";
}

void MainWindow::on_pbCount_clicked()
{
    qDebug() << "pbCount";
}

void MainWindow::on_pbTimestamp_clicked()
{
    qDebug() << "pbTimestamp";
}

void MainWindow::on_pbUuid_clicked()
{
    qDebug() << "pbUuid";
}

void MainWindow::on_pbHome_clicked()
{
    qDebug() << "pbHome";
    ui->stackedWidget->setCurrentWidget(ui->pageHome);
    ui->pbHome->hide();
}

void MainWindow::on_pbShare_clicked()
{
    qDebug() << "pbShare";
}
