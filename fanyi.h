#ifndef FANYI_H
#define FANYI_H

#include <QWidget>
#include<QtNetwork/QNetworkAccessManager>
#include<QtNetwork/QNetworkReply>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QMessageBox>
#include<QUrlQuery>
#include<QRandomGenerator>
#include<QSettings>

namespace Ui {
class fanyi;
}

class fanyi : public QWidget
{
    Q_OBJECT

public:
    explicit fanyi(QWidget *parent = nullptr);
    ~fanyi();

private slots:

    void onTranslationReply(QNetworkReply *reply);

    void on_btnTranslate_clicked();

    void on_btnReset_clicked();

    void saveHistroy(const QString &expression);

    void on_clear_clicked();

private:
    Ui::fanyi *ui;
    QNetworkAccessManager *networkManager;
    const QString APP_ID="20251203002511857";
    const QString APP_SECRET_KEY="_SUTtnYnx4hyN28maMOK";
    QSettings *settings;
    void loadHistroy();


};

#endif // FANYI_H
