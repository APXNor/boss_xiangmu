#include "jisuan.h"
#include "ui_jisuan.h"

jisuan::jisuan(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::jisuan)
{
    ui->setupUi(this);
    settings=new QSettings("Myjisuan","Histroy",this);

    ui->histroyList->setStyleSheet(R"(
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
    ui->histroyList->viewport()->setStyleSheet("background-color: transparent;");



    loadHistroy();






    this->setFixedSize(500,400);
    this->setWindowTitle("帅坤计算");
    label=new QLabel();
    btMapper=new QSignalMapper;
    QFont font;
    font.setFamily(QString::fromUtf8("Agency FB"));
    font.setPointSize(20);
    font.setBold(true);
    label->setFont(font);
    label->setText("0");
    label->setAlignment(Qt::AlignRight);
    label->setGeometry(20,5,250,30);
    label->setParent(this);
    label->setStyleSheet("border:1px solid red;");
    QStringList btnName={"7","8","9","+","4","5","6","-","1","2","3","*",".","0","=","/","P"};

    int row=45;
    int col=0;
    for(int i=0;i<17;i++){
        btn[i]=new QPushButton(btnName[i],this);
        btn[i]->setGeometry(col*60+30,row,50,30);
        col++;
        if((col+1)%5==0){
            row+=45;
            col=0;
        }
        btMapper->setMapping(btn[i],col+1);
        connect(btn[i],&QPushButton::clicked,[=](){
            if(btnName[i]=="="){
                QJSEngine myEngine;
                QString calStr=label->text();
                QJSValue calResult=myEngine.evaluate(calStr);//计算
                if(calResult.isError()){
                    label->setText("0");
                }
                else{
                    label->setText(calResult.toString());
                }



                QString result=calResult.toString();

                QString record=calStr+"="+result;

                saveHistory(record);





            }
            else{
                if(btnName[i]=="+"||btnName[i]=="-"||btnName[i]=="*"||btnName[i]=="/"){
                    QString inputStr=label->text();
                    if(flag){
                        flag=false;
                    }
                    else{
                        int inputLength=inputStr.length()-1;
                        label->setText(inputStr.left(inputLength));
                    }
                }
                else{
                    if(label->text()=="0"){
                        label->setText("");
                    }
                    flag=true;
                }
                label->setText(label->text()+btnName[i]);
            }
            if(btnName[i]=="P"){
                label->setText("0");
            }

        });


    }


}

void jisuan::saveHistory(const QString &expression){
    QStringList history=settings->value("histroy").toStringList();

    history.append(expression);

    settings->setValue("histroy",history);

    ui->histroyList->addItem(expression);




}

void jisuan::loadHistroy(){

    QStringList histroy=settings->value("histroy").toStringList();

    ui->histroyList->addItems(histroy);


}






jisuan::~jisuan()
{
    delete ui;
}



void jisuan::on_clear_clicked()
{
    settings->remove("histroy");
    ui->histroyList->clear();


}






















