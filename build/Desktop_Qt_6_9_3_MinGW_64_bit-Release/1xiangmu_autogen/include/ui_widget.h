/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushDingshi;
    QPushButton *pushJishuan;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QPushButton *PushButtonSousuo;
    QTextEdit *textEdit_chat;
    QPushButton *tianqiPushbutton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(568, 772);
        pushDingshi = new QPushButton(Widget);
        pushDingshi->setObjectName("pushDingshi");
        pushDingshi->setGeometry(QRect(60, 180, 111, 41));
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/Lenovo/Pictures/Saved Pictures/10452499(1).jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushDingshi->setIcon(icon);
        pushDingshi->setIconSize(QSize(50, 50));
        pushJishuan = new QPushButton(Widget);
        pushJishuan->setObjectName("pushJishuan");
        pushJishuan->setGeometry(QRect(210, 180, 111, 41));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("C:/Users/Lenovo/Pictures/Saved Pictures/t04370440b63b30cd0b(1).jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushJishuan->setIcon(icon1);
        pushJishuan->setIconSize(QSize(50, 50));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(360, 180, 111, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("C:/Users/Lenovo/Pictures/Saved Pictures/t01f0fc6d17d70af55c(1).jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon2);
        pushButton->setIconSize(QSize(50, 50));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(30, 80, 381, 71));
        PushButtonSousuo = new QPushButton(Widget);
        PushButtonSousuo->setObjectName("PushButtonSousuo");
        PushButtonSousuo->setGeometry(QRect(430, 100, 99, 28));
        textEdit_chat = new QTextEdit(Widget);
        textEdit_chat->setObjectName("textEdit_chat");
        textEdit_chat->setGeometry(QRect(10, 480, 531, 271));
        tianqiPushbutton = new QPushButton(Widget);
        tianqiPushbutton->setObjectName("tianqiPushbutton");
        tianqiPushbutton->setGeometry(QRect(60, 240, 111, 41));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("C:/Users/Lenovo/Pictures/Saved Pictures/t013ab8a7c83a413a7d.jpg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        tianqiPushbutton->setIcon(icon3);
        tianqiPushbutton->setIconSize(QSize(50, 50));
        tianqiPushbutton->setAutoRepeat(false);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushDingshi->setText(QCoreApplication::translate("Widget", "\347\247\222\350\241\250", nullptr));
        pushJishuan->setText(QCoreApplication::translate("Widget", "\350\256\241\347\256\227", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\345\215\225\350\257\215\346\237\245\350\257\242", nullptr));
        PushButtonSousuo->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242", nullptr));
        tianqiPushbutton->setText(QCoreApplication::translate("Widget", "\345\244\251\346\260\224\351\242\204\346\212\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
