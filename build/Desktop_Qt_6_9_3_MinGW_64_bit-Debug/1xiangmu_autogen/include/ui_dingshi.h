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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dingshi
{
public:

    void setupUi(QWidget *dingshi)
    {
        if (dingshi->objectName().isEmpty())
            dingshi->setObjectName("dingshi");
        dingshi->resize(560, 360);
        dingshi->setStyleSheet(QString::fromUtf8(""));

        retranslateUi(dingshi);

        QMetaObject::connectSlotsByName(dingshi);
    } // setupUi

    void retranslateUi(QWidget *dingshi)
    {
        dingshi->setWindowTitle(QCoreApplication::translate("dingshi", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dingshi: public Ui_dingshi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DINGSHI_H
