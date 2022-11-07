#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <libxml/parser.h>
#include <libxml/xpath.h>
#include "cameralistmodel.h"

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
    void on_pb_Preset_Load_clicked();

    void on_pb_Preset_Save_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *_player = new QMediaPlayer;
    QVideoWidget *_vw = new QVideoWidget;
    CameraListModel *cameraList = new CameraListModel;
    void discover();
    void InitVideoWindow();
    void CreateStream();
    OnvifData * GetCurrentOnviv();
};
#endif // MAINWINDOW_H
