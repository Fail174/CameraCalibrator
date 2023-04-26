#include <QThread>
#include <QGridLayout>
#include <QNetworkRequest>
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogcoordedit.h"
#include "cameramath.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    config = new MainSettings();
    map = new QPixmap(":/images/img/map.png");
    icon_camera = new QPixmap(":/images/img/camera-48.png");
    icon_mark = new QPixmap(":/images/img/mark-48.png");
    ui->label_map->setScaledContents(true);
    ui->label_map->setPixmap(*map);
    InitVideoWindow();


    //connect(ui->pushButton, &QPushButton::pressed, [=] {onCameraConnect();});
    //connect(ui->pushButton, &QPushButton::pressed, this, SLOT(onCameraConnect()));
    connect(ui->pushButton, &QPushButton::pressed, this, &MainWindow::onCameraConnect);

    connect(ui->pb_Move_Up, &QPushButton::pressed, [=] {CameraMove(0.0, 0.3, 0.0);});
    connect(ui->pb_Move_Down, &QPushButton::pressed, [=] {CameraMove(0.0, -0.3, 0.0);});
    connect(ui->pb_Move_Left, &QPushButton::pressed, [=] {CameraMove(-0.3, 0.0, 0.0);});
    connect(ui->pb_Move_Right, &QPushButton::pressed, [=] {CameraMove(0.3, 0.0, 0.0);});
    connect(ui->pb_Zoom_Up, &QPushButton::pressed, [=] {CameraMove(0.0, 0.0, 0.5);});
    connect(ui->pb_Zoom_Down, &QPushButton::pressed, [=] {CameraMove(0.0, 0.0, -0.5);});
    connect(ui->pb_Move_Up, SIGNAL(released()), this, SLOT(CameraStop()));
    connect(ui->pb_Move_Down, SIGNAL(released()), this, SLOT(CameraStop()));
    connect(ui->pb_Move_Left, SIGNAL(released()), this, SLOT(CameraStop()));
    connect(ui->pb_Move_Right, SIGNAL(released()), this, SLOT(CameraStop()));
    connect(ui->pb_Zoom_Up, SIGNAL(released()), this, SLOT(ZoomStop()));
    connect(ui->pb_Zoom_Down, SIGNAL(released()), this, SLOT(ZoomStop()));

    //QStandardItemModel *model = new QStandardItemModel(this);

    model->setStringList(config->GetPointList());
    ui->listView->setModel(model);
    ui->Host->insertItems(0, config->GetCameraList());
    UpdateCameraList();
    LoadFromFile(txtFileName);


    connect(ui->listView, SIGNAL(clicked(const QModelIndex)), this, SLOT(PointChanged(QModelIndex)));
    connect(ui->listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(PointEdit(QModelIndex)));
    InitOnVIF();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateCameraStatus()));
    //timer->start(1000);
}


void MainWindow::UpdateCameraList()
{
    cameraList->cameras.clear();
    for (int i=0; i<config->CameraList->count();i++)
    {
        CamPoint cm = config->GetCamera(i);
        Camera *cam= new Camera(cm.Name);
        cam->Data = cm;
        for (int j=0; j<config->PointList->count();j++)
        {
            Point3D p3d;
            CamPoint pm = config->GetPoint(j);
            p3d.X = pm.Coord.X - cm.Coord.X;
            p3d.Y = pm.Coord.Y - cm.Coord.Y;
            p3d.Z = pm.Coord.Z - cm.Coord.Z;
            cam->SetPoint(j,p3d);
        }
        cameraList->cameras.push_back(cam);

    }
}

void MainWindow::updateCameraStatus()
{
    GetMarkPosition();
    //PtzStatus st = onvif->getPtzStatus();
}

void MainWindow::InitOnVIF()
{
    onvif = new OnvifControl();
    connect(this, &MainWindow::eCameraMove, onvif, &OnvifControl::ContinuousMove);
    connect(this, &MainWindow::eCameraStop, onvif, &OnvifControl::PtzStop);
    connect(this, &MainWindow::eInitMediaClient, onvif, &OnvifControl::InitMediaClient);
    connect(this, &MainWindow::eInitPTZClient, onvif, &OnvifControl::InitPtzClient);

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    double ScaleX = (double)map->width()/ui->label_map->width();
    double ScaleY = (double)map->height()/ui->label_map->height();
    mapbuffer = map->copy();
    QPainter paint(&mapbuffer);
    for(int i=0; i<config->CameraList->count();i++)
    {

        CamPoint p = config->CameraList->at(i);
        CamPoint s = GetScreeFromGeo(p);
        paint.drawPixmap(QRect(s.Coord.X*ScaleX-10,s.Coord.Y*ScaleY-10,20,20),*icon_camera);
        paint.drawText(s.Coord.X*ScaleX+10,s.Coord.Y*ScaleY-10,QString::number(i+1));
    }

    for(int i=0; i<config->PointList->count();i++)
    {
        CamPoint p = config->PointList->at(i);
        CamPoint s = GetScreeFromGeo(p);
        paint.drawPixmap(QRect(s.Coord.X*ScaleX-10,s.Coord.Y*ScaleY-10,20,20),*icon_mark);
        paint.drawText(s.Coord.X*ScaleX+10,s.Coord.Y*ScaleY-10,QString::number(i+1));
    }
    if((CurrentPointIndex>0)&&(ui->Host->currentIndex()>=0))
    {
        QPen pen;
        pen.setColor(Qt::red);
        pen.setWidth(2);
        paint.setPen(pen);
        CamPoint p = config->GetPoint(CurrentPointIndex-1);
        CamPoint s = GetScreeFromGeo(p);
        p = config->GetCamera(ui->Host->currentIndex());
        p = GetScreeFromGeo(p);
        paint.drawLine(s.Coord.X*ScaleX,s.Coord.Y*ScaleY,p.Coord.X*ScaleX,p.Coord.Y*ScaleY);
    }
    ui->label_map->setPixmap(mapbuffer);
    QMainWindow::paintEvent(event);

}

CamPoint MainWindow::GetScreeFromGeo(CamPoint p)
{
    CamPoint s;
    double dx = config->mapX1-config->mapX2;
    double dy = config->mapY1-config->mapY2;
    s.Coord.X = ui->label_map->width() - (p.Coord.X-config->mapX2)*ui->label_map->width()/dx;
    s.Coord.Y = ui->label_map->height() - (p.Coord.Y-config->mapY2)*ui->label_map->height()/dy;
    s.Coord.Z = p.Coord.Z;
    return s;
}

MainWindow::~MainWindow()
{
    delete map;
    delete icon_camera;
    delete icon_mark;
    delete _player;
    delete model;
    delete videowdg;
    delete scene;
    delete ui;
}

QStringList MainWindow::GetPointList()
{
    return config->GetPointList();
}


///
/// \brief MainWindow::on_pushButton_clicked
/// Формирование видеопотока
//void MainWindow::on_pushButton_clicked()
void MainWindow::onCameraConnect()
{
    QString onvifHost = ui->Host->currentText();
    QString user = ui->UserName->text();
    QString pass = ui->Password->text();

    emit eInitMediaClient(onvifHost,user,pass);
    emit eInitPTZClient(onvifHost,user,pass);
    QString login = ui->UserName->text() + ":" + ui->Password->text() + "@";
    QString url = onvif->stream_uri;
    ui->textEdit->append(url );
    url.insert(7,login);
    CreateStream(url);
    timer->start(1000);
}


///
/// \brief MainWindow::on_pushButton_2_clicked
/// Seach PTZ camera
/*void MainWindow::on_pushButton_2_clicked()
{
    struct OnvifSession *onvif_session = (struct OnvifSession*)malloc(sizeof(struct OnvifSession));
    onvif_session->discovery_msg_id = 0;
    initializeSession(onvif_session);
    int number_of_cameras = broadcast(onvif_session);
    fprintf(stdout, "libonvif found %d cameras\n", number_of_cameras);

    //ui->Host->clear();
    for (int i = 0; i < number_of_cameras; i++)
    {
      struct OnvifData *onvif_data = (struct OnvifData*)malloc(sizeof(struct OnvifData));
      prepareOnvifData(i, onvif_session, onvif_data);

      ui->textEdit->append(onvif_data->camera_name);
      ui->textEdit->append( onvif_data->xaddrs );
      ui->textEdit->append( onvif_data->device_service );
      if(i>=ui->Host->count()){
            ui->Host->addItem(onvif_data->xaddrs);
      }else{
            ui->Host->setItemText(i,onvif_data->xaddrs);
      }

      getCapabilities(onvif_data);
      getNetworkInterfaces(onvif_data);
      getNetworkDefaultGateway(onvif_data);
      getDNS(onvif_data);
      getVideoEncoderConfigurationOptions(onvif_data);
      getVideoEncoderConfiguration(onvif_data);
      getOptions(onvif_data);
      getImagingSettings(onvif_data);

      getProfile(onvif_data);
      getDeviceInformation(onvif_data);

      cameraList->pushCamera(onvif_data);

    }
}*/
/*
void MainWindow::on_pushButton_3_clicked()
{
    QString onvifHost = ui->Host->currentText();
    QString user = ui->UserName->text();
    QString pass = ui->Password->text();
    //if(onvif != nullptr){
        emit eInitMediaClient(onvifHost,user,pass);
        emit eInitPTZClient(onvifHost,user,pass);
    //}
}
*/
Point3D MainWindow::GetMarkPosition()
{
    Point3D pos;

    //QString user = ui->UserName->text();
    //QString pass = ui->Password->text();

    PtzStatus status = onvif->getPtzStatus();
    //getPosition(&x,&y,&z,onvif_data);
    pos.X = status.pan;
    pos.Y = status.tilt;
    pos.Z = status.zoom;

    CurrentAzimut = pos.X*180.0;//grad
    CurrentElevation = pos.Y*90.0;//grad
    ui->edit_Azimut->setText(QString::number(CurrentAzimut));
    ui->edit_Elevation->setText(QString::number(CurrentElevation));
    return pos;
}

/// Позиционирование и зумирование камеры
/// \brief MainWindow::CameraMove
/// \param x - лево, право
/// \param y - вниз, вверх
/// \param z - зум +, -
///
void MainWindow::CameraMove(float x,float y,float z)
{
    //onvif->ContinuousMove(x,y,z);
    emit eCameraMove(x,y,z);
}
/*
void MainWindow::addCamera(OnvifData *onvif_data)
{
    getProfile(onvif_data);
    getDeviceInformation(onvif_data);

    QString str;
    str.append(QString("%1\n").arg(onvif_data->stream_uri));
    str.append(QString("serial number: %1\nmfgr name: %2\n").arg(onvif_data->serial_number, onvif_data->camera_name));

    QString key = onvif_data->serial_number;
    QString alias = cameraAlias.value(key);
    if (alias.length() > 0)
        strncpy(onvif_data->camera_name, alias.toLatin1().data(), alias.length());

    //emit found(onvif_data);

    str.append(QString("display name: %1\n").arg(onvif_data->camera_name));
    //emit msg(str);
    ui->textEdit->append( str);
}*/

/// Инициализация видео окна
/// \brief MainWindow::InitVideoWindow
///
void MainWindow::InitVideoWindow()
{

    QGraphicsVideoItem *item = new QGraphicsVideoItem();
    videowdg = new VideoWidget(this);
    videowdg->move(290,ui->label_map->height()+15);
    videowdg->resize(width()-295,height()-ui->label_map->height()-ui->textEdit->height()-30);
    //ui->mainwidget->setCentralWidget(videowdg);

    // Инициализация сцены
    scene = new QGraphicsScene(this);
    //scene->setSceneRect(0.0, 0.0, ui->mainwidget->width()-2, ui->mainwidget->height()-2);
    videowdg->setScene(scene);
    //videowdg->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //QBrush brush;
    //brush.setStyle(Qt::SolidPattern);
    //brush.setColor(QColor(0,0,0));
    //scene->setBackgroundBrush(brush);

    item->setOffset(QPointF(0,0));
    item->setSize(QSizeF(700,400));
    scene->addItem(item);
    /*
    videowdg = new VideoWidget(this);
    //videowdg->move(290,90);
    //videowdg->resize(711,441);
    QGridLayout *layout = new QGridLayout;
    //layout->addWidget(_vw,0,0,0,0);
    layout->addWidget(videowdg,0,0,0,0);
    ui->mainwidget->setLayout(layout);
    //videowdg->setLayout(layout);
    //setCentralWidget(win);
    //_player->setVideoOutput(_vw);
    _player->setVideoOutput(videowdg);
    */

    /*VideoWidget *view = new VideoWidget(this);
    view->move(290,90);
    view->resize(711,441);
    QGraphicsScene *scene = new QGraphicsScene(view);
    QGraphicsVideoItem *item = new QGraphicsVideoItem();
    view->setScene(scene);
    scene->addItem(item);
    view->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету
    scene->setSceneRect(0,0,view->width(),view->height());*/

    _player = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    _player->setVideoOutput(item);


    /*const QUrl url = QUrl("rtsp://admin:magos2020@192.168.0.64:554");
    const QNetworkRequest requestRtsp(url);
    _player->setMedia(requestRtsp);
    _player->play();*/
}


/// Подключение камеры к видеоокну
/// \brief MainWindow::CreateStream
///
void MainWindow::CreateStream(QString rtspurl)
{
    if(_player->state() == QMediaPlayer::PlayingState)
    {
        _player->stop();
    }
    const QUrl url = QUrl(rtspurl);
    //const QUrl url = QUrl("rtsp://admin:magos2020@192.168.0.64:554");
    const QNetworkRequest requestRtsp(url);
    _player->setMedia(requestRtsp);
    _player->play();
}

/// Остановка зумирования
/// \brief MainWindow::ZoomStop
///
void MainWindow::ZoomStop()
{
    //onvif->PtzStop();
    emit eCameraStop();
}

/// Остановка позиционирования
/// \brief MainWindow::CameraStop
///
void MainWindow::CameraStop()
{
    //onvif->PtzStop();
    emit eCameraStop();
}


/// Позиционрование на маркер
/// \brief MainWindow::on_pb_Preset_Load_clicked
///
void MainWindow::on_pb_Preset_Load_clicked()
{
    double az,el;
    Camera *cam = cameraList->cameras.at(ui->Host->currentIndex());
    az = (-cam->A + cam->GetAzimut(CurrentPointIndex-1))/180-1;
    el = (-cam->E + cam->GetElevation(CurrentPointIndex-1))/180;

    onvif->AbsoluteMove(az,el,0);
}

/// Записать новое направление позиционирования
/// \brief MainWindow::on_pb_Preset_Save_clicked
///
void MainWindow::on_pb_Preset_Save_clicked()
{
    GetMarkPosition();
    double d;
    Point3D p;
    Camera *cam = cameraList->cameras.at(ui->Host->currentIndex());
    d = cam->GetRange(CurrentPointIndex-1);
    double xy = cos(CurrentElevation*M_PI/180)*d;
    p.Z = tan(CurrentElevation*M_PI/180)*xy;//H
    p.X = sin(CurrentAzimut*M_PI/180)*xy;//X
    p.Y = cos(CurrentAzimut*M_PI/180)*xy;//Y
    cam->SetPoint(CurrentPointIndex-1,p);
}

void MainWindow::PointChanged(const QModelIndex index)
{
    CurrentPointIndex = index.row()+1;
}

void MainWindow::PointEdit(const QModelIndex index)
{
    DialogCoordEdit * dialog = new DialogCoordEdit(this);
    int i = index.row();
    CamPoint cp = config->GetPoint(i);
    dialog->SetName(cp.Name);
    dialog->SetCoord(cp.Coord.X,cp.Coord.Y,cp.Coord.Z);
    if(dialog->exec()==QDialog::Accepted)
    {// showNormal();
        dialog->GetCoord(cp.Coord.X,cp.Coord.Y,cp.Coord.Z);
        cp.Name = dialog->GetName();
        config->SetPoint(i,cp);
        config->UpDatePoint();
        update();
    }
}

void MainWindow::on_pushButton_SetCamCoord_clicked()
{
    int index = ui->Host->currentIndex();
    if((index<0)||(index>config->CameraList->count()))return;
    Camera  *camera = cameraList->getCameraAt(index);
    CamPoint cmp = config->GetCamera(index);

    DialogCoordEdit * dialog = new DialogCoordEdit(this);
    dialog->SetCoord(cmp.Coord.X,cmp.Coord.Y,cmp.Coord.Z);
    dialog->SetName(cmp.Name);
    if(dialog->exec()==QDialog::Accepted)
    {
        dialog->GetCoord(cmp.Coord.X,cmp.Coord.Y,cmp.Coord.Z);
        if(camera != nullptr){
            dialog->GetCoord(camera->Data.Coord.X,camera->Data.Coord.Y,camera->Data.Coord.Z);
            camera->Data.Name = dialog->GetName();
        }
        config->SetCamera(index,cmp);
        config->UpDateCamera();
        UpdateCameraList();
        update();
    }
}

void MainWindow::on_toolButton_Add_clicked()
{
    CamPoint cp = GetPointCoord(config->PointCount);
    config->AddPoint(cp);
    config->UpDatePoint();
    model->setStringList(GetPointList());
    update();
}

void MainWindow::on_pb_CalculatDelta_clicked()
{
    int index = ui->Host->currentIndex();
/*    Camera  *camera = cameraList->getCameraAt(index);
    if(camera == nullptr) return ;
*/
    cameramath *cmath = new cameramath();

    QList<CamPoint> *cam = new QList<CamPoint>();

    QList<Point3D> *point = new  QList<Point3D>();

    for(int i =0 ; i<cameraList->cameras.count();i++)
    {
        Camera *cm = cameraList->getCameraAt(i);
        cam->append(cm->Data);
        for(int j=0;j<cm->CameraPoint->count();j++)
        {
            Point3D cpoint =  cm->CameraPoint->at(j);
            point->append(cpoint);
        }
    }
    cmath->UpdateData(cam,config->PointList);//координаты камер и маркеров

    cmath->UpdatePointCoord(index, point);//координаты маркеров в системе камеры

    cmath->StartCalc(index);

    ui->lineEdit_XShift->setText(QString::number(cmath->dA));
    ui->lineEdit_YShift->setText(QString::number(cmath->dE));
    ui->lineEdit_ZShift->setText(QString::number(cmath->dC));
    Camera *cm = cameraList->getCameraAt(index);
    if(cm!=nullptr){
        cm->A = cmath->dA;
        cm->E = cmath->dE;
        cm->C = cmath->dC;
    }
    delete point;
    delete cam;
    delete cmath;
}

void MainWindow::on_toolButton_Add_CAM_clicked()
{
    DialogCoordEdit * dialog = new DialogCoordEdit(this);
    CamPoint cp = GetCAMCoord(config->CameraCount);
    dialog->SetCoord(cp.Coord.X,cp.Coord.Y,cp.Coord.Z);
    dialog->SetName(cp.Name);
    if(dialog->exec()==QDialog::Accepted)
    {
        dialog->GetCoord(cp.Coord.X,cp.Coord.Y,cp.Coord.Z);
        cp.Name = dialog->GetName();
        ui->Host->addItem(cp.Name);
        config->AddCamera(cp);
        config->UpDateCamera();
        update();
    }
}

CamPoint MainWindow::GetCAMCoord(int i)
{
    CamPoint p;

    switch(i)
    {
    case 0:
        p.Name = "192.168.200.65";
        p.Coord.X = 6428434.783;
        p.Coord.Y = 6404149.169;
        p.Coord.Z = 23.5;
        break;
    case 1:
        p.Name = "192.168.200.66";
        p.Coord.X = 6428439.542;
        p.Coord.Y = 6404150.527;
        p.Coord.Z = 23.5;
        break;
    case 2:
        p.Name = "192.168.200.67";
        p.Coord.X = 6429165.265;
        p.Coord.Y = 6404228.132;
        p.Coord.Z = 12.5;
        break;
    case 3:
        p.Name = "192.168.200.68";
        p.Coord.X = 6429003.093;
        p.Coord.Y = 6404058.408;
        p.Coord.Z = 45;
        break;
    default:
        p.Name = "192.168.200.65";
        p.Coord.X = 6428434.783;
        p.Coord.Y = 6404149.169;
        p.Coord.Z = 23.5;
        break;

    }
    return p;
    //1 - 57.964123, 31.380582   высота 23,5 м
    //2 - 57.964166, 31.380603 высота 23,5 м
    //3 - 57.970696, 31.381620 высота 12,5 м
    //4 - 57.969204, 31.378819 высота 45 м
}

CamPoint MainWindow::GetPointCoord(int i)
{
    CamPoint p;

    switch(i)
    {

    case 4:
        p.Name = "Маркер 5";
        p.Coord.X = 6427151.294;
        p.Coord.Y = 6404238.657;
        p.Coord.Z = 2;
        break;
    case 3:
        p.Name = "Маркер 4";
        p.Coord.X = 6427483.457;
        p.Coord.Y = 6404401.018;
        p.Coord.Z = 2;
        break;
    case 2:
        p.Name = "Маркер 3";
        p.Coord.X = 6428231.792;
        p.Coord.Y = 6404656.485;
        p.Coord.Z = 2;
        break;
    case 1:
        p.Name = "Маркер 2";
        p.Coord.X = 6428572.938	;
        p.Coord.Y = 6404760.424;
        p.Coord.Z = 2;
        break;
    case 0:
        p.Name = "Маркер 1";
        p.Coord.X = 6428892.715	;
        p.Coord.Y = 6404830.682;
        p.Coord.Z = 2;
        break;
    default:
        p.Name = "Маркер ";
        p.Coord.X = 6429248.501;
        p.Coord.Y = 6404853.299;
        p.Coord.Z = 2;
        break;
    }
    return p;
    //1 - 57.964123, 31.380582   высота 23,5 м
    //2 - 57.964166, 31.380603 высота 23,5 м
    //3 - 57.970696, 31.381620 высота 12,5 м
    //4 - 57.969204, 31.378819 высота 45 м
}

///
/// \brief MainWindow::on_pushButton_Save_clicked
/// Записать расчитанные поправки в файл
void MainWindow::on_pushButton_Save_clicked()
{
    SaveToFile(txtFileName);
}

void MainWindow::SaveToFile(QString Filename)
{
    QFile filetxt;

    filetxt.setFileName(Filename);
    if (!filetxt.open(QIODevice::WriteOnly))
    {
        return;
    }
    QTextStream wstream(&filetxt);
    for(int i =0 ; i<cameraList->cameras.count();i++)
    {
        Camera *cam = cameraList->cameras.at(i);
        wstream << "Camera" << i << ": Azimut=" << cam->A <<
                                      " Elevation=" << cam->E <<
                                      " Cren=" << cam->C << "\n";
    }

    filetxt.close();
}

///
/// \brief MainWindow::LoadFromFile
/// Считать расчитанные поправки из файла
void MainWindow::LoadFromFile(QString Filename)
{
    QFile filetxt;
    filetxt.setFileName(Filename);
    if (!filetxt.open(QIODevice::ReadOnly))
    {
        return;
    }
    QTextStream wstream(&filetxt);
    for(int i =0 ; i<cameraList->cameras.count();i++)
    {
        if(not wstream.atEnd())
        {
            QString str = wstream.readLine();
            Camera *cam = cameraList->cameras.at(i);
            if (str.indexOf("Camera")>=0)
            {
                QStringList Ss = str.split(' ');//разделитель space

                for(int j=0;j<Ss.count();j++)
                {
                     if (Ss[j].indexOf("Azimut=")>=0)
                     {
                          str = Ss[j].mid(Ss[j].indexOf("=")+1,Ss[j].length()-1);//оставляем только числовые данные
                          cam->A= str.toDouble();
                     }
                     if (Ss[j].indexOf("Elevation=")>=0)
                     {
                          str = Ss[j].mid(Ss[j].indexOf("=")+1,Ss[j].length()-1);//оставляем только числовые данные
                          cam->E= str.toDouble();
                     }
                     if (Ss[j].indexOf("Cren=")>=0)
                     {
                          str = Ss[j].mid(Ss[j].indexOf("=")+1,Ss[j].length()-1);//оставляем только числовые данные
                          cam->C= str.toDouble();
                     }
                }
                cameraList->cameras.removeAt(i);
                cameraList->cameras.insert(i,cam);
            }

        }
    }
    filetxt.close();
}

void MainWindow::on_toolButton_Del_clicked()
{
    QModelIndex index=ui->listView->currentIndex();
    if(index.row() >=0)
    {
        int i = index.row();
        config->DelPoint(i);
        config->UpDatePoint();
        model->setStringList(GetPointList());
        CurrentPointIndex = CurrentPointIndex - 1;
        update();
    }
}


void MainWindow::on_toolButton_Del_CAM_clicked()
{
    int index = ui->Host->currentIndex();
    if((index<0)||(index>config->CameraList->count()))return;

    ui->Host->removeItem(index);
    cameraList->delCameraAt(index);
    config->DelCamera(index);
    config->UpDateCamera();
    UpdateCameraList();
    update();
}

void MainWindow::on_pushButton_clicked()
{

}

