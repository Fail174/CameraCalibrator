#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QStringList>
#include <QStringListModel>
#include <QStandardItem>

#include <libxml/parser.h>
#include <libxml/xpath.h>
#include "cameralistmodel.h"
#include "mainsettings.h"
#include "videowidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void CameraMove(float x,float y,float z);
    void CameraStop();
    void ZoomStop();
    void GetPosition();
    void on_pb_Preset_Load_clicked();
    void PointChanged(const QModelIndex index);
    void PointEdit(const QModelIndex index);
    void on_pb_Preset_Save_clicked();

    void on_pushButton_SetCamCoord_clicked();

    void on_toolButton_Add_clicked();

private:
    Ui::MainWindow *ui;
    VideoWidget *videowdg;
    MainSettings * config;
    QStringListModel *model = new QStringListModel(nullptr);
    QMediaPlayer *_player           {nullptr};
    QGraphicsScene *scene           {nullptr};
    //QVideoWidget *_vw = new QVideoWidget;
    CameraListModel *cameraList = new CameraListModel;
    CamPoint CurentPoint;//текущее положение камеры
    int CurrentPointIndex=0;


    void discover();
    void InitVideoWindow();
    void CreateStream(QString rtspurl);
    QStringList GetPointList();
    OnvifData * GetCurrentOnviv();

signals:
    //void eUpdateShift(float X, Y, Z);
};
#endif // MAINWINDOW_H
