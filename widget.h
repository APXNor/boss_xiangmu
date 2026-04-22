#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QLabel>
#include<QTimer>
#include<QDateTime>
#include<QStackedWidget>
#include<QPixmap>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include"dingshi.h"
#include"jisuan.h"
#include"fanyi.h"
#include"tianqi.h"
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include<QPalette>
#include<QMediaPlayer>
#include<QAudioOutput>
#include<QPixmap>




QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void updataCurrentTime();
    void replyFinished(QNetworkReply *reply);
    void replyFinishedSong(QNetworkReply *reply);


private slots:
    void on_pushDingshi_clicked();

    void on_pushJishuan_clicked();

    void on_pushButton_clicked();

    void on_PushButtonSousuo_clicked();

    void on_tianqiPushbutton_clicked();

protected:

private:
    Ui::Widget *ui;
    QLabel *timeLabel;
    QTimer *timer;
    QStackedWidget *stacked;
    QNetworkAccessManager *manager;

    const QString API_KEY="sk-onodolmjyqpxwzbvutddfnlyizmpeynbkwwmbuvpwljqacwt";

    QMediaPlayer *player;

    QAudioOutput *audioOutput;

    QUrl currentMusicUrl;






};
#endif // WIDGET_H
