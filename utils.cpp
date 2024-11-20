#include "utils.h"
#include <QDebug>

QString getSysInfo()
{
    QString info;

    // 1. 获取操作系统信息
    info += QString("操作系统: %1\n").arg(QSysInfo::prettyProductName());
    info += QString("版本: %1\n").arg(QSysInfo::productVersion());
    info += QString("架构: %1\n").arg(QSysInfo::currentCpuArchitecture());

    return info;
}

QString getClockInfo()
{
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString dateTimeString = currentDateTime.toString("hh:mm:ss");

    return dateTimeString;
}

QString getBmiInfo(double height, double weight)
{
    height /= 100.0;
    double bmi = weight / (height * height);
    
    QString healthAdvice;
    if (bmi < 18.5) {
        healthAdvice = "您的体重偏轻，建议增加营养和锻炼以增重。";
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        healthAdvice = "您的体重正常，继续保持健康的生活方式。";
    } else if (bmi >= 25 && bmi <= 29.9) {
        healthAdvice = "您的体重偏重，建议适当控制饮食并增加运动。";
    } else {
        healthAdvice = "您的体重属于肥胖范围，建议制定减重计划。";
    }

    return QString("您的 BMI 值: %1 \n健康建议: %2")
                    .arg(bmi, 0, 'f', 2)
                    .arg(healthAdvice);
}

QString convertTimestamp(int timestamp)
{
    // 将时间戳转换回 QDateTime 对象
    QDateTime dateTimeFromTimestamp = QDateTime::fromSecsSinceEpoch(timestamp);
    // qDebug() << "从时间戳转换回的时间：" << dateTimeFromTimestamp.toString();
    return dateTimeFromTimestamp.toString("yyyy-MM-dd hh:mm:ss");
}

QString getUuidInfo(int count)
{
    QString result;

    for (int i = 0; i < count; ++i) {
        QUuid uuid = QUuid::createUuid();
        result += uuid.toString();  // 添加 UUID
        if (i < count - 1) {
            result += "\n";
        }
    }

    return result;
}

QByteArray getJsonData(const QString &url)
{
    QFile file(url);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Could not open the file!";
    }

    QByteArray fileData = file.readAll();
    file.close();

    return fileData;
}

int getAreaIdByCityName(const QString &cityName, const QByteArray &fileData)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData);
    if (jsonDoc.isNull()) {
        qDebug() << "Failed to create JSON doc.";
    }

    if (!jsonDoc.isArray()) {
        qDebug() << "JSON is not an array.";
    }

    QJsonArray jsonArray = jsonDoc.array();

    // for (const QJsonValue &value : jsonArray) {
    //     if (value.isObject()) {
    //         QJsonObject jsonObject = value.toObject();
    //         int areaid = jsonObject["areaid"].toInt();
    //         QString countyname = jsonObject["countyname"].toString();
    //         qDebug() << "Area ID:" << areaid << "County Name:" << countyname;
    //     }
    // }

    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        QString countyName = obj["countyname"].toString();
        if (countyName == cityName) {
            return obj["areaid"].toInt();
        }
    }

    return -1;
}