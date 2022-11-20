#include "videowidget.h"





VideoWidget::VideoWidget(QWidget *parent) : QGraphicsView(parent)
{

}


void VideoWidget::paintEvent(QPaintEvent *e)
{
    QGraphicsView::paintEvent(e);
    QPainter painter(this->viewport());
    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawLine(width()/2, height()/2-50, width()/2, height()/2+50);
    painter.drawLine(width()/2-50, height()/2, width()/2+50, height()/2);
}

/*
void VideoWidget::paintEvent(QPaintEvent *e)
{
    QVideoWidget::paintEvent(e);
    QPainter painter(this);
    //painter.save();
    painter.setPen(Qt::white);
    painter.setBrush(Qt::red);
    painter.drawLine(150,50,150,90);
    painter.drawLine(50,70,200,70);
    painter.drawLine(0,0,width(),height());

    //painter.restore();
}
*/
