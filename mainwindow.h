#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QStringList>
#include <QStringListModel>
#include <QStandardItem>
#include <QTimer>

#include "onvifcontrol.h"
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
    void CameraMove(float x,float y,float z);
    void CameraStop();
    void ZoomStop();
    void updateCameraStatus();

    Point3D GetMarkPosition();
    void on_pb_Preset_Load_clicked();
    void PointChanged(const QModelIndex index);
    void PointEdit(const QModelIndex index);
    void on_pb_Preset_Save_clicked();

    void on_pushButton_SetCamCoord_clicked();

    void on_toolButton_Add_clicked();

    void on_pb_CalculatDelta_clicked();

    void on_toolButton_Add_CAM_clicked();

    void on_pushButton_Save_clicked();

    void on_toolButton_Del_clicked();

    void on_toolButton_Del_CAM_clicked();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QPixmap *map;
    QPixmap mapbuffer;

    QPixmap *icon_mark;
    QPixmap *icon_camera;
    VideoWidget *videowdg;
    MainSettings * config;
    QStringListModel *model = new QStringListModel(nullptr);
    QMediaPlayer *_player           {nullptr};
    QGraphicsScene *scene           {nullptr};
    //QVideoWidget *_vw = new QVideoWidget;
    CameraListModel *cameraList = new CameraListModel;
    CamPoint CurentPoint;//текущее положение камеры
    int CurrentPointIndex=0;
    QString txtFileName = "table.txt";
    double CurrentAzimut=0, CurrentElevation=0;

    void InitVideoWindow();
    void CreateStream(QString rtspurl);
    QStringList GetPointList();
    OnvifControl *onvif;
    OnvifControl * GetCurrentOnviv();
    CamPoint GetScreeFromGeo(CamPoint p);
    void paintEvent(QPaintEvent *event);
    void onCameraConnect();
    void InitOnVIF();
    CamPoint GetCAMCoord(int i);
    CamPoint GetPointCoord(int i);
    void UpdateCameraList();
    void SaveToFile(QString Filename);
    void LoadFromFile(QString Filename);
signals:
    //void eUpdateShift(float X, Y, Z);
    void eCameraMove(float x, float y, float z);
    void eCameraStop();
    void eInitMediaClient(QString ipaddr, QString login, QString pass);
    void eInitPTZClient(QString ipaddr, QString login, QString pass);
};
#endif // MAINWINDOW_H
