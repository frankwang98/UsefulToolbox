#ifndef MY_STYLE_H
#define MY_STYLE_H

#include <QString>

QString clockStyle = R"(
    QLabel {
        background-color: #1ABC9C; /* 背景颜色：绿 */
        color: #ECF0F1;
        font-family: "Segoe UI", Arial, sans-serif;
        font-size: 80px;
        font-weight: bold;
        text-align: center;
        border: 2px solid #2C3E50;
        border-radius: 10px;
        padding: 20px;
        box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.6);
    }

    // 34495E
    // QLabel:hover {
    //     background-color: #1ABC9C;
    //     color: white;
    // }

    // QLabel:focus {
    //     border: 2px solid #1ABC9C;
    //     box-shadow: 0px 0px 15px rgba(26, 188, 156, 0.8);
    // }
)";

QString bmiStyle = R"(
    QWidget {
        background-color: #ECF0F1;  /* 背景颜色：浅灰 */
        font-family: "Segoe UI", Arial, sans-serif;
        font-size: 14px;
    }

    QLabel {
        color: #2C3E50;  /* 文字颜色：深色 */
        font-weight: bold;
        font-size: 18px;
        padding: 5px;
    }

    QLineEdit {
        background-color: #FFFFFF;  /* 输入框背景颜色：白色 */
        border: 1px solid #BDC3C7;  /* 边框颜色：浅灰 */
        border-radius: 5px;
        padding: 5px;
        font-size: 16px;
        color: #2C3E50;
    }

    QPushButton {
        background-color: #1ABC9C;  /* 按钮背景颜色 */
        color: white;  /* 按钮文字颜色 */
        border: none;
        border-radius: 10px;
        font-size: 16px;
        padding: 10px 20px;
        margin-top: 20px;
        cursor: pointer;
    }

    QPushButton:hover {
        background-color: #16A085;
    }

    QPushButton:pressed {
        background-color: #1C7D67;
    }
)";

QString countStyle = R"(
    QLabel {
        background-color: #1ABC9C; /* 背景颜色：绿 */
        color: #ECF0F1;
        font-family: "Segoe UI", Arial, sans-serif;
        font-size: 40px;
        font-weight: bold;
        text-align: center;
        border: 2px solid #2C3E50;
        border-radius: 10px;
        padding: 20px;
        box-shadow: 0px 0px 10px rgba(0, 0, 0, 0.6);
    }
)";

#endif // MY_STYLE_H
