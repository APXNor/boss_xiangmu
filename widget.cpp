#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setAutoFillBackground(true);

    QPalette palette;
    QPixmap pix("C:/Users/Lenovo/Desktop/Pixmap/e3dazi41yf0njutxq6kp9obcrw78ghvl_PIC2018 (1).png!w800");  // 这里改你图片路径

    palette.setBrush(QPalette::Window,
                     pix.scaled(this->size(),
                                Qt::IgnoreAspectRatio,
                                Qt::SmoothTransformation));

    this->setPalette(palette);


    manager=new QNetworkAccessManager(this);

    player=new QMediaPlayer(this);

    audioOutput=new QAudioOutput(this);

    player->setAudioOutput(audioOutput);

    audioOutput->setVolume(1);




    timeLabel=new QLabel(this);
    QFont font=timeLabel->font();
    font.setPointSize(14);
    timeLabel->setFont(font);
    updataCurrentTime();
    timer=new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::updataCurrentTime);
    timer->start(1000);

    dingshi *Page1=new dingshi;
    jisuan *Page2=new jisuan;
    fanyi *Page3=new fanyi;
    tianqi *Page4=new tianqi;


    Page1->setStyleSheet("backGround-color:lightgray;");
    Page2->setStyleSheet("backGround-color:lightgray;");
    Page3->setStyleSheet("backGround-color:lightgray;");
    ui->textEdit_chat->setStyleSheet("backGround-color:lightgray;");
    Page4->setStyleSheet("backGround-color:lightgray;");


    stacked=new QStackedWidget(this);
    stacked->addWidget(Page1);
    stacked->addWidget(Page2);
    stacked->addWidget(Page3);
    stacked->addWidget(ui->textEdit_chat);
    stacked->addWidget(Page4);



    stacked->setFrameStyle(QFrame::Panel|QFrame::Raised);
    stacked->move(0,350);
    stacked->setFixedWidth(560);
    stacked->setFixedHeight(370);





    connect(manager,&QNetworkAccessManager::finished,this,&Widget::replyFinished);





}

Widget::~Widget()
{
    delete ui;
}

void Widget::updataCurrentTime(){
    QDateTime currentTime=QDateTime::currentDateTime();
    QString timeString=currentTime.toString("yyyy-MM-dd HH:mm:ssdddd");
    timeLabel->setText(timeString);

}


void Widget::on_pushDingshi_clicked()
{
    stacked->setCurrentIndex(0);
}
void Widget::on_pushJishuan_clicked()
{
    stacked->setCurrentIndex(1);

}


void Widget::on_pushButton_clicked()
{
    stacked->setCurrentIndex(2);

}


void Widget::on_PushButtonSousuo_clicked()
{

    stacked->setCurrentIndex(3);

    QString prompt=ui->lineEdit->text().trimmed();

    if(prompt.isEmpty()) return ;

    ui->textEdit_chat->setText("你："+prompt+"\n\nAI:");
    QNetworkRequest req(QUrl("https://api.siliconflow.cn/v1/chat/completions"));
    req.setRawHeader("Content-Type","applications/json");
    req.setRawHeader("Authorization",("Bearer "+ API_KEY).toUtf8());

    QJsonArray messages;
    QJsonObject msg;
    msg["role"]="user";
    msg["content"]=prompt;
    messages.append(msg);
    QJsonObject body;
    body["model"]="Pro/zai-org/GLM-4.7";
    body["messages"]=messages;
    body["temperature"]=0.7;
    QJsonDocument doc(body);
    manager->post(req,doc.toJson());









}


void Widget::replyFinished(QNetworkReply *reply){
    if(reply->error()!=QNetworkReply::NoError){
        ui->textEdit_chat->setText("错误："+reply->errorString()+"\n");
        reply->deleteLater();
        return;

    }

    QByteArray data=reply->readAll();
    QJsonDocument doc=QJsonDocument::fromJson(data);
    QJsonObject obj=doc.object();
    QString ans=obj["choices"][0]["message"]["content"].toString();
    ui->textEdit_chat->setText(ans+"\n\n---\n");
    reply->deleteLater();


}


void Widget::on_tianqiPushbutton_clicked(){
    stacked->setCurrentIndex(4);

}
















