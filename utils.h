#ifndef UTILS_H
#define UTILS_H

#include <QSysInfo>
#include <QProcess>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QDateTime>
#include <QMessageBox>
#include <QUuid>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include "httplib.h"
#include "json.hpp"

QString getSysInfo();

QString getClockInfo();

QString getBmiInfo(double height, double weight);

QString convertTimestamp(int timestamp);

QString getUuidInfo(int count);

QByteArray getJsonData(const QString &url);

int getAreaIdByCityName(const QString &cityName, const QByteArray &fileData);

int longitudeToZone(double longitude);

#endif // UTILS_H
