#include "mainwindow.h"
#include <QApplication>

QString windowSheet = R"(
    QPushButton {
        background-color: #4CAF50;
        border: none;
        color: white;
        padding: 10px 20px;
        font-size: 16px;
        border-radius: 5px;
        transition: background-color 0.3s;
    }
    QPushButton:hover {
        background-color: #45a049;
    }
    QLabel {
        font-size: 18px;
        color: #333;
        font-family: Arial, sans-serif;
        padding: 5px;
    }
)";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet(windowSheet);

    MainWindow w;
    w.show();

    QQmlApplicationEngine engine;
    // engine.load(QUrl(QStringLiteral("qrc:/mapApp.qml")));
    // if (engine.rootObjects().isEmpty()) {
    //     return -1;
    // }

    return a.exec();
}
