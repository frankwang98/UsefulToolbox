#include "utils.h"

QString getSysInfo()
{
    QString info;

    // 1. 获取操作系统信息
    info += QString("操作系统: %1\n").arg(QSysInfo::prettyProductName());
    info += QString("版本: %1\n").arg(QSysInfo::productVersion());
    info += QString("架构: %1\n").arg(QSysInfo::currentCpuArchitecture());

    return info;
}
