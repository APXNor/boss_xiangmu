#include "tianqi.h"
#include "ui_tianqi.h"

tianqi::tianqi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tianqi)
{
    ui->setupUi(this);

    ui->date_temp->setStyleSheet(R"(
    QTextEdit {
        /* 替换为你的图片完整路径，注意用 / 分隔 */
        background-image: url(C:/Users/Lenovo/Downloads/e3dazi41yf0njutxq6kp9obcrw78ghvl_PIC2018.png);
        background-repeat: no-repeat;
        background-position: center;
        background-size: cover;  /* 等比铺满控件，不变形 */
        border: none;           /* 去掉默认边框，和背景融合 */
        color: #ffffff;         /* 文字设为白色，适配浅蓝背景 */
        font-size: 14px;
    }
    /* 滚动条透明美化（可选，不影响核心功能） */
    QScrollBar:vertical {
        background-color: transparent;
        width: 8px;
    }
    QScrollBar::handle:vertical {
        background-color: rgba(255, 255, 255, 0.3);
        border-radius: 4px;
    }
)");


    ui->date_temp->viewport()->setStyleSheet("background-color: transparent;");

    netManager=new QNetworkAccessManager(this);

    QNetworkRequest ipRequest;

    ipRequest.setUrl(QUrl("https://whois.pconline.com.cn/ipJson.jsp?ip&json=true"));

    QNetworkReply *netReply=netManager->get(ipRequest);

    connect(netReply,SIGNAL(finished()),this,SLOT(slotGetReplyFinished()));

}


tianqi::~tianqi()
{
    delete ui;
}

void tianqi::slotGetReplyFinished(){
    QNetworkReply *reply=(QNetworkReply *)sender();

    QByteArray data=reply->readAll();

    QString jsonStr=QString::fromLocal8Bit(data);

    qDebug()<<"获取的数据"<<jsonStr;


    QJsonDocument doc=QJsonDocument::fromJson(jsonStr.toUtf8());

    if(doc.isNull()){
        qDebug()<<"JSON解析失败，文档为空";
        reply->deleteLater();
        return ;

    }

    QJsonObject obj=doc.object();

    QString cityName=obj["city"].toString();

    qDebug()<<"123456"<<cityName;

    ui->cityName->setText(cityName);

    reply->deleteLater();

    QNetworkRequest weatherRequest;

    QUrl url("https://uapis.cn/api/v1/misc/weather");

    QUrlQuery query;
    query.addQueryItem("city",cityName);

    query.addQueryItem("forecast","true");

    url.setQuery(query);

    weatherRequest.setUrl(url);

    weatherRequest.setRawHeader("Authorization",QString("Bearer%1").arg(UAPI_TOKEN).toUtf8());

    weatherRequest.setHeader(QNetworkRequest::UserAgentHeader,"Mozilla/5.0");

    QNetworkReply *weatherReply=netManager->get(weatherRequest);

    connect(weatherReply,SIGNAL(finished()),this,SLOT(slotGetWeatherReplyFinished()));



}



void tianqi::slotGetWeatherReplyFinished(){
    QNetworkReply *weather_reply=(QNetworkReply *)sender();

    QByteArray weather_data=weather_reply->readAll();

    QJsonDocument doc=QJsonDocument::fromJson(weather_data);

    QJsonObject weaobj=doc.object();

    QString weather=weaobj["weather"].toString();

    int temp=weaobj["temperature"].toInt();

    QString reportTime=weaobj["report_time"].toString();

    int currentT=weaobj["temp_max"].toInt();

    int cyrrentT2=weaobj["temp_min"].toInt();

    ui->currentT->setText(QString::number(currentT)+"~"+QString::number(cyrrentT2)+"℃");

    QJsonArray forecastArray =weaobj["forecast"].toArray();

    for(int i=0;i<forecastArray.size();++i){
        QJsonObject dayObj=forecastArray[i].toObject();
        QString date=dayObj["date"].toString();

        QString week=dayObj["week"].toString();

        int tempMax=dayObj["temp_max"].toInt();

        int tempMin=dayObj["temp_min"].toInt();


        ui->date_temp->append(date+week);
        ui->date_temp->append(QString::number(tempMax)+"~"+QString::number(tempMin)+"℃");

        QFont font=ui->date_temp->font();

        font.setBold(true);

        ui->date_temp->setStyleSheet("color:black;");

        ui->date_temp->setFont(font);



        qDebug()<<date<<week<<tempMax;

    }



    qDebug()<<reportTime;

    ui->temp_time->setText(reportTime);


    qDebug()<<weather<<temp;

    ui->district->setText(QString::number(temp)+"℃");
    ui->Text_weather->setText(weather);








}















