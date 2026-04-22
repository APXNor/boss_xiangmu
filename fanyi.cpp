#include "fanyi.h"
#include "ui_fanyi.h"

fanyi::fanyi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::fanyi)
{
    ui->setupUi(this);


    ui->HistroyList->setStyleSheet(R"(
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

    // 彻底消除白色残留（关键！解决你截图里的空白块）
    ui->HistroyList->viewport()->setStyleSheet("background-color: transparent;");


    networkManager=new QNetworkAccessManager(this);
    connect(networkManager,&QNetworkAccessManager::finished,this,&fanyi::onTranslationReply);

    settings=new QSettings("Myffanyi","Histroy",this);

    loadHistroy();




}

fanyi::~fanyi()
{
    delete ui;
}



void fanyi::on_btnTranslate_clicked()
{
    QString inputText=ui->lineEditInput->text().trimmed();
    if(inputText.isEmpty()){
        QMessageBox::warning(this,"提示","请输入要翻译的内容");
        return ;

    }

    QString q=inputText;
    QString from="en";
    QString to="zh";
    QString salt=QString::number(QRandomGenerator::global()->generate());

    QString signStr=APP_ID+q+salt+APP_SECRET_KEY;

    QString sign=QCryptographicHash::hash(signStr.toUtf8(),QCryptographicHash::Md5).toHex();






    QUrl url("https://fanyi-api.baidu.com/api/trans/vip/translate");

    QUrlQuery query;
    query.addQueryItem("q",q);
    query.addQueryItem("from",from);
    query.addQueryItem("to",to);
    query.addQueryItem("appid",APP_ID);
    query.addQueryItem("salt",salt);
    query.addQueryItem("sign",sign);


    url.setQuery(query);

    networkManager->get(QNetworkRequest(url));


}


void fanyi::on_btnReset_clicked()
{
    ui->lineEditInput->clear();
    ui->lineEditResult->clear();


}


void fanyi::onTranslationReply(QNetworkReply *reply){
    if(reply->error()!=QNetworkReply::NoError){
        QMessageBox::critical(this,"错误","翻译失败："+reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray responseData=reply->readAll();
    QJsonDocument jsonDoc=QJsonDocument::fromJson(responseData);
    QJsonObject jsonObj=jsonDoc.object();
    if(jsonObj.contains("error_code")){
        QString errorMsg=jsonObj["error_mag"].toString();
        QMessageBox::critical(this,"翻译失败","错误信息:"+errorMsg);

    }
    else{
        QJsonArray transResult=jsonObj["trans_result"].toArray();

        QString reslut=transResult[0].toObject()["dst"].toString();

        ui->lineEditResult->setText(reslut);


        QString record=ui->lineEditInput->text()+"="+reslut;

        saveHistroy(record);
    }







}

void fanyi::saveHistroy(const QString &expression){
    QStringList history=settings->value("histroy").toStringList();

    history.append(expression);

    settings->setValue("histroy",history);

    ui->HistroyList->addItem(expression);


}

void fanyi::loadHistroy(){

    QStringList histroy=settings->value("histroy").toStringList();

    ui->HistroyList->addItems(histroy);



}

void fanyi::on_clear_clicked()
{
    settings->remove("histroy");
    ui->HistroyList->clear();


}

