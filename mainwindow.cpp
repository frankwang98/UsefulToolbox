#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "utils.h"
#include "my_style.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("实用工具箱");

    timer = new QTimer(this);
    timer->start(1000);
    connect(timer, &QTimer::timeout, this, &MainWindow::showDateTime);
    
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
    ui->stackedWidget->setCurrentWidget(ui->pageClock);
    ui->pbHome->show();

    connect(timer, &QTimer::timeout, this, &MainWindow::showClock);
}

void MainWindow::on_pbMap_clicked()
{
    qDebug() << "pbMap";
    ui->stackedWidget->setCurrentWidget(ui->pageMap);
    ui->pbHome->show();
}

void MainWindow::on_pbWeather_clicked()
{
    qDebug() << "pbWeather";
    ui->stackedWidget->setCurrentWidget(ui->pageWeather);
    ui->pbHome->show();
}

void MainWindow::on_pbBmi_clicked()
{
    qDebug() << "pbBmi";
    ui->stackedWidget->setCurrentWidget(ui->pageBmi);
    ui->pbHome->show();

    ui->leHeight->setPlaceholderText("输入身高(cm)");
    ui->leWeight->setPlaceholderText("输入体重(kg)");
    connect(ui->pbBmiCal, &QPushButton::clicked, this, &MainWindow::showBmi);
    QString tableHtml = 
        "<h3>身体质量指数参考表</h3>"
        "<div style='text-align:center;'>"
        "<table border='1' cellpadding='5'>"
        "<tr><th>BMI 范围</th><th>体重描述</th></tr>"
        "<tr><td>&lt; 18.5</td><td>过轻</td></tr>"
        "<tr><td>18.5 - 23.9</td><td>正常</td></tr>"
        "<tr><td>24.0 - 27.9</td><td>偏胖</td></tr>"
        "<tr><td>&gt;= 28.0</td><td>肥胖</td></tr>"
        "</table>";

    ui->lbBmiRef->setText(tableHtml);
}

void MainWindow::on_pbCount_clicked()
{
    qDebug() << "pbCount";
    ui->stackedWidget->setCurrentWidget(ui->pageCount);
    ui->pbHome->show();

    connect(timer, &QTimer::timeout, this, &MainWindow::showCountDown);
}

void MainWindow::on_pbTimestamp_clicked()
{
    qDebug() << "pbTimestamp";
    ui->stackedWidget->setCurrentWidget(ui->pageTimestamp);
    ui->pbHome->show();

    ui->leTimestamp->setPlaceholderText("输入时间戳");
    connect(timer, &QTimer::timeout, this, &MainWindow::showTimestamp);
    connect(ui->pbTimeConvert, &QPushButton::clicked, this, &MainWindow::showConvertTimestamp);
}

void MainWindow::on_pbUuid_clicked()
{
    qDebug() << "pbUuid";
    ui->stackedWidget->setCurrentWidget(ui->pageUuid);
    ui->pbHome->show();

    connect(ui->pbUuidGen, &QPushButton::clicked, this, &MainWindow::showUuid);
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

/***************************************************************************/

void MainWindow::showDateTime()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    ui->lbClock->setText(dateTimeString);
}

void MainWindow::showClock()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();

    QString dateTimeString2 = currentDateTime.toString("hh:mm:ss");
    ui->lbClockInfo->setAlignment(Qt::AlignCenter);
    ui->lbClockInfo->setText(dateTimeString2);
    ui->lbClockInfo->setStyleSheet(clockStyle);
}

void MainWindow::showBmi()
{
    double height = ui->leHeight->text().toDouble();
    double weight = ui->leWeight->text().toDouble();
    QString bmi = getBmiInfo(height, weight);
    ui->lbBmiResult->setText(bmi);
}

void MainWindow::showCountDown()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    
    // 设置New Year（例如：2025年1月1日 00:00:00）
    QDateTime newYearDateTime(QDate(2025, 1, 1), QTime(0, 0, 0));

    qint64 secondsLeft = currentDateTime.secsTo(newYearDateTime);
    int daysLeft = secondsLeft / 86400;
    int hoursLeft = (secondsLeft % 86400) / 3600;
    int minutesLeft = (secondsLeft % 3600) / 60;
    int secondsLeftFinal = secondsLeft % 60;

    QString countdownText = QString("距离新年还有 %1天 \n %2小时 %3分钟 %4秒 \n 享受当下的时光！")
                                .arg(daysLeft)
                                .arg(hoursLeft, 2, 10, QChar('0'))
                                .arg(minutesLeft, 2, 10, QChar('0'))
                                .arg(secondsLeftFinal, 2, 10, QChar('0'));

    ui->lbCountDown->setAlignment(Qt::AlignCenter);
    ui->lbCountDown->setText(countdownText);
    ui->lbCountDown->setStyleSheet(countStyle);
}

void MainWindow::showTimestamp()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString timestampString = currentDateTime.toString("yyyy-MM-dd hh:mm:ss");
    ui->lbTimestamp1->setText(timestampString);

    qint64 timestamp = currentDateTime.toSecsSinceEpoch();
    ui->lbTimestamp2->setText(QString::number(timestamp));

    ui->lbTimestamp3->setText(currentDateTime.toUTC().toString());
}

void MainWindow::showConvertTimestamp()
{
    qint64 timestamp = ui->leTimestamp->text().toLongLong();
    ui->lbConvertResult->setText(convertTimestamp(timestamp));
}

void MainWindow::showUuid()
{
    ui->leUuidCount->setPlaceholderText("输入要生成的UUID数量");
    ui->tbUuid->setText(getUuidInfo(ui->leUuidCount->text().toInt()));
}
