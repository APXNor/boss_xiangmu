/********************************************************************************
** Form generated from reading UI file 'dingshi.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DINGSHI_H
#define UI_DINGSHI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dingshi
{
public:
    QPushButton *kaishi;
    QPushButton *tingzhi;
    QPushButton *guiling;
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *dingshi)
    {
        if (dingshi->objectName().isEmpty())
            dingshi->setObjectName("dingshi");
        dingshi->resize(560, 360);
        kaishi = new QPushButton(dingshi);
        kaishi->setObjectName("kaishi");
        kaishi->setGeometry(QRect(50, 240, 99, 28));
        tingzhi = new QPushButton(dingshi);
        tingzhi->setObjectName("tingzhi");
        tingzhi->setGeometry(QRect(210, 240, 99, 28));
        guiling = new QPushButton(dingshi);
        guiling->setObjectName("guiling");
        guiling->setGeometry(QRect(350, 240, 99, 28));
        lcdNumber = new QLCDNumber(dingshi);
        lcdNumber->setObjectName("lcdNumber");
        lcdNumber->setGeometry(QRect(50, 50, 401, 161));

        retranslateUi(dingshi);

        QMetaObject::connectSlotsByName(dingshi);
    } // setupUi

    void retranslateUi(QWidget *dingshi)
    {
        dingshi->setWindowTitle(QCoreApplication::translate("dingshi", "Form", nullptr));
        kaishi->setText(QCoreApplication::translate("dingshi", "\345\274\200\345\247\213", nullptr));
        tingzhi->setText(QCoreApplication::translate("dingshi", "\345\201\234\346\255\242", nullptr));
        guiling->setText(QCoreApplication::translate("dingshi", "\345\275\222\351\233\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dingshi: public Ui_dingshi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINGSHI_H
