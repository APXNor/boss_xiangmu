#ifndef DINGSHI_H
#define DINGSHI_H

#include <QWidget>
#include<QTimer>
#include<QPainter>
#include<QLabel>
#include<QElapsedTimer>
#include<QPushButton>

namespace Ui {
class dingshi;
}

class dingshi : public QWidget
{
    Q_OBJECT

public:
    explicit dingshi(QWidget *parent = nullptr);
    ~dingshi();

protected:
    void paintEvent(QPaintEvent *);


private slots:
    void updateTimer();
    void startPause();
    void reset();


private:
    Ui::dingshi *ui;
    QElapsedTimer m_timer;
    QTimer *m_refreshTimer;
    qint64 m_totalMs;
    bool m_running;
    QLabel *m_label;


};

#endif // DINGSHI_H
