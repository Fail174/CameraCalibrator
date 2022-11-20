#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

//#include <QWidget>
#include <QGraphicsView>
#include <QPainter>

class VideoWidget : public QGraphicsView
{
    Q_OBJECT
public:
    explicit VideoWidget(QWidget *parent = nullptr);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
    //virtual void paintCallback(QPainter &painter, const QRect &imgRect);
};

#endif // VIDEOWIDGET_H
