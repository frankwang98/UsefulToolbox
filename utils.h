#ifndef UTILS_H
#define UTILS_H

#include <QSysInfo>
#include <QProcess>
#include <QDateTime>
#include <QMessageBox>
#include <QUuid>
#include <QTextStream>

QString getSysInfo();

QString getClockInfo();

QString getBmiInfo(double height, double weight);

QString convertTimestamp(int timestamp);

QString getUuidInfo(int count);

#endif // UTILS_H
