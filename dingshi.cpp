#include "dingshi.h"
#include "ui_dingshi.h"

dingshi::dingshi(QWidget *parent)
    : QWidget(parent)
    , m_totalMs(0)
    , m_running(false)
    , ui(new Ui::dingshi)
{
    ui->setupUi(this);


    m_label=new QLabel("00:00:00",this);

    QFont font;
    font.setPointSize(22);
    font.setBold(true);
    m_label->setFont(font);
    m_label->setAlignment(Qt::AlignCenter);


    QPushButton *btnStart=new QPushButton("开始",this);
    QPushButton *btnReset=new QPushButton("重置",this);
    btnReset->move(100,50);
    btnStart->move(0,50);



    connect(btnStart,&QPushButton::clicked,this,&dingshi::startPause);

    connect(btnReset,&QPushButton::clicked,this,&dingshi::reset);








    m_refreshTimer=new QTimer(this);
    m_refreshTimer->setInterval(10);

    connect(m_refreshTimer,&QTimer::timeout,this,&dingshi::updateTimer);
    m_timer.start();

    m_refreshTimer->start();

    m_timer.restart();


}

dingshi::~dingshi()
{
    delete ui;
}

void dingshi::updateTimer(){

    if(!m_running) return;
    qint64 ms=m_totalMs+m_timer.elapsed();


    int min=ms/60000;
    int sec=(ms%60000)/1000;
    int m=(ms%1000)/10;
    QString timeStr=QString::asprintf("%02d:%02d.%02d",min,sec,m);

    m_label->setText(timeStr);


    update();
}

void dingshi::paintEvent(QPaintEvent *){
    QPainter p(this);

    p.setRenderHint(QPainter::Antialiasing);
    int centerX = width() / 2;
    int centerY = height() / 2;
    int radius = qMin(centerX, centerY) - 30; // 表盘半径，留边距
    QFont font("Arial", 10, QFont::Normal); // 数字字体
    p.setFont(font);
    p.setPen(Qt::black);

    // 2. 循环绘制 0-60 数字
    for (int i = 0; i <= 60; i+=5) {
        // 计算角度：0度在3点方向，顺时针旋转，减去90度让12点(0/60)在正上方
        double angle = (i * 6.0 - 90.0) * M_PI / 180.0;

        // 计算数字中心点坐标
        int offset=8;
        int numX = centerX + (radius +offset) * cos(angle);
        int numY = centerY + (radius +offset) * sin(angle);


        // 3. 绘制文字（关键：用QRect保证居中）
        QString text = QString::number(i);

        QRect textRect(0, 0, 35, 35); // 文字绘制区域
        textRect.moveCenter(QPoint(numX, numY)); // 移动区域中心到计算点
        p.drawText(textRect, Qt::AlignCenter, text);
    }



    int cx=width()/2;
    int cy=height()/2;
    int r=150;

    p.setPen(QPen(Qt::black,2));
    p.drawEllipse(cx-r,cy-r,r*2,r*2);

    for(int i=0;i<=60;++i){
        double angle =qDegreesToRadians(i*6-90);

        int x1=cx+(r-10)*cos(angle);
        int y1=cy+(r-10)*sin(angle);

        int x2=cx+r*cos(angle);
        int y2=cy+r*sin(angle);
        p.drawLine(x1,y1,x2,y2);
    }

    qint64 ms=m_timer.elapsed()+m_totalMs;
    double sec=ms/1000.0;

    double angle=qDegreesToRadians(sec*6-90);

    int len=r-20;
    p.setPen(QPen(Qt::blue,4));

    p.setPen(QPen(QColor(0,180,255),4));
    p.drawLine(cx,cy,cx+len*cos(angle),cy+len*sin(angle));

    p.setPen(QPen(QColor(0,160,255,180),8));
    p.drawLine(cx,cy,cx+len*cos(angle),cy+len*sin(angle));

    p.setPen(QPen(QColor(0,120,255,80),14));
    p.drawLine(cx,cy,cx+len*cos(angle),cy+len*sin(angle));

    p.setPen(Qt::NoPen);
    p.setBrush(Qt::blue);
    p.drawEllipse(cx-6,cy-6,12,12);


}

void dingshi::startPause(){
    if(!m_running){
        m_timer.restart();
        m_running=true;
        m_refreshTimer->start();
        sender()->setProperty("text","暂停");
    }
    else{
        m_totalMs+=m_timer.elapsed();
        m_running=false;
        m_refreshTimer->stop();
        sender()->setProperty("text","开始");

    }

}


void dingshi::reset(){


    m_timer.restart();

    m_running=false;
    m_refreshTimer->stop();

    m_totalMs=0;

    m_label->setText("00:00:00");



    QPushButton *btn=findChild<QPushButton*>();
    if(btn) btn->setText("开始");

    update();


}








































