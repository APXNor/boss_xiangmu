#ifndef JISUAN_H
#define JISUAN_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QSignalMapper>
#include<QDebug>
#include<QJSEngine>
#include<QJSValue>
#include<QSettings>


namespace Ui {
class jisuan;
}

class jisuan : public QWidget
{
    Q_OBJECT

public:
    explicit jisuan(QWidget *parent = nullptr);
    ~jisuan();
    void saveHistory( const QString &expression);


private slots:
    void on_clear_clicked();

private:
    Ui::jisuan *ui;
    QSignalMapper *btMapper;
    QPushButton *btn[30];
    QLabel *label;
    bool flag=true;
    QSettings *settings;

    void loadHistroy();





};

#endif // JISUAN_H
