/********************************************************************************
** Form generated from reading UI file 'tianqi.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIANQI_H
#define UI_TIANQI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tianqi
{
public:
    QLabel *district;
    QLabel *cityName;
    QLabel *currentT;
    QLabel *temp_time;
    QLabel *location_image;
    QLabel *Text_weather;
    QTextEdit *date_temp;
    QLabel *label;

    void setupUi(QWidget *tianqi)
    {
        if (tianqi->objectName().isEmpty())
            tianqi->setObjectName("tianqi");
        tianqi->resize(718, 458);
        district = new QLabel(tianqi);
        district->setObjectName("district");
        district->setGeometry(QRect(170, 60, 71, 31));
        district->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        cityName = new QLabel(tianqi);
        cityName->setObjectName("cityName");
        cityName->setGeometry(QRect(80, 60, 81, 41));
        cityName->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);"));
        currentT = new QLabel(tianqi);
        currentT->setObjectName("currentT");
        currentT->setGeometry(QRect(250, 60, 71, 31));
        currentT->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        temp_time = new QLabel(tianqi);
        temp_time->setObjectName("temp_time");
        temp_time->setGeometry(QRect(390, 60, 121, 31));
        temp_time->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        location_image = new QLabel(tianqi);
        location_image->setObjectName("location_image");
        location_image->setGeometry(QRect(10, 60, 69, 19));
        Text_weather = new QLabel(tianqi);
        Text_weather->setObjectName("Text_weather");
        Text_weather->setGeometry(QRect(320, 60, 71, 31));
        Text_weather->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        date_temp = new QTextEdit(tianqi);
        date_temp->setObjectName("date_temp");
        date_temp->setGeometry(QRect(100, 110, 431, 241));
        date_temp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(tianqi);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 120, 69, 19));

        retranslateUi(tianqi);

        QMetaObject::connectSlotsByName(tianqi);
    } // setupUi

    void retranslateUi(QWidget *tianqi)
    {
        tianqi->setWindowTitle(QCoreApplication::translate("tianqi", "Form", nullptr));
        district->setText(QString());
        cityName->setText(QString());
        currentT->setText(QString());
        temp_time->setText(QString());
        location_image->setText(QCoreApplication::translate("tianqi", "TextLabel", nullptr));
        Text_weather->setText(QString());
        label->setText(QCoreApplication::translate("tianqi", "\345\276\200\345\220\216\344\270\200\345\221\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tianqi: public Ui_tianqi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIANQI_H
