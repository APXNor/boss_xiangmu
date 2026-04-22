/********************************************************************************
** Form generated from reading UI file 'jisuan.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JISUAN_H
#define UI_JISUAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_jisuan
{
public:
    QListWidget *histroyList;
    QPushButton *clear;

    void setupUi(QWidget *jisuan)
    {
        if (jisuan->objectName().isEmpty())
            jisuan->setObjectName("jisuan");
        jisuan->resize(537, 300);
        histroyList = new QListWidget(jisuan);
        histroyList->setObjectName("histroyList");
        histroyList->setGeometry(QRect(360, 0, 161, 261));
        clear = new QPushButton(jisuan);
        clear->setObjectName("clear");
        clear->setGeometry(QRect(370, 270, 99, 28));

        retranslateUi(jisuan);

        QMetaObject::connectSlotsByName(jisuan);
    } // setupUi

    void retranslateUi(QWidget *jisuan)
    {
        jisuan->setWindowTitle(QCoreApplication::translate("jisuan", "Form", nullptr));
        clear->setText(QCoreApplication::translate("jisuan", "\346\270\205\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class jisuan: public Ui_jisuan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JISUAN_H
