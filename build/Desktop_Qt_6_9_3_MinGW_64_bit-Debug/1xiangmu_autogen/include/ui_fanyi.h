/********************************************************************************
** Form generated from reading UI file 'fanyi.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FANYI_H
#define UI_FANYI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fanyi
{
public:
    QLabel *label;
    QPushButton *btnReset;
    QLineEdit *lineEditResult;
    QPushButton *btnTranslate;
    QLabel *label_2;
    QLineEdit *lineEditInput;
    QListWidget *HistroyList;
    QPushButton *clear;

    void setupUi(QWidget *fanyi)
    {
        if (fanyi->objectName().isEmpty())
            fanyi->setObjectName("fanyi");
        fanyi->resize(605, 382);
        label = new QLabel(fanyi);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 80, 101, 51));
        btnReset = new QPushButton(fanyi);
        btnReset->setObjectName("btnReset");
        btnReset->setGeometry(QRect(70, 230, 99, 28));
        lineEditResult = new QLineEdit(fanyi);
        lineEditResult->setObjectName("lineEditResult");
        lineEditResult->setGeometry(QRect(150, 140, 271, 41));
        btnTranslate = new QPushButton(fanyi);
        btnTranslate->setObjectName("btnTranslate");
        btnTranslate->setGeometry(QRect(230, 220, 121, 41));
        label_2 = new QLabel(fanyi);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 150, 71, 31));
        lineEditInput = new QLineEdit(fanyi);
        lineEditInput->setObjectName("lineEditInput");
        lineEditInput->setGeometry(QRect(150, 80, 271, 41));
        HistroyList = new QListWidget(fanyi);
        HistroyList->setObjectName("HistroyList");
        HistroyList->setGeometry(QRect(440, 80, 141, 192));
        HistroyList->setStyleSheet(QString::fromUtf8(""));
        clear = new QPushButton(fanyi);
        clear->setObjectName("clear");
        clear->setGeometry(QRect(440, 280, 99, 28));

        retranslateUi(fanyi);

        QMetaObject::connectSlotsByName(fanyi);
    } // setupUi

    void retranslateUi(QWidget *fanyi)
    {
        fanyi->setWindowTitle(QCoreApplication::translate("fanyi", "Form", nullptr));
        label->setText(QCoreApplication::translate("fanyi", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\350\276\223\345\205\245\357\274\232</span></p></body></html>", nullptr));
        btnReset->setText(QCoreApplication::translate("fanyi", "\351\207\215\346\226\260\350\276\223\345\205\245", nullptr));
        btnTranslate->setText(QCoreApplication::translate("fanyi", "\347\277\273\350\257\221", nullptr));
        label_2->setText(QCoreApplication::translate("fanyi", "<html><head/><body><p align=\"center\"><span style=\" font-size:12pt;\">\347\273\223\346\236\234\357\274\232</span></p></body></html>", nullptr));
        clear->setText(QCoreApplication::translate("fanyi", "\346\270\205\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class fanyi: public Ui_fanyi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FANYI_H
