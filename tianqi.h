#ifndef TIANQI_H
#define TIANQI_H

#include <QWidget>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QUrl>
#include<QUrlQuery>
#include<QJsonArray>
#include<QPalette>

namespace Ui {
class tianqi;
}

class tianqi : public QWidget
{
    Q_OBJECT
private slots:
    void slotGetReplyFinished();
    void slotGetWeatherReplyFinished();



public:
    tianqi(QWidget *parent = nullptr);
    ~tianqi();



private:
    Ui::tianqi *ui;
    QNetworkAccessManager *netManager;
    const QString UAPI_TOKEN="xuxurusheng";





};

#endif // TIANQI_H
