#include <QThread>
#include <QGridLayout>
#include <QNetworkRequest>
#include <QGraphicsScene>
#include <QGraphicsVideoItem>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "source/onvif.h"
#include "dialogcoordedit.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    config = new MainSettings();
    InitVideoWindow();

    connect(ui->pb_Move_Up, &QPushButton::pressed, [=] {CameraMove(0.0, 0.5, 0.0);});
    connect(ui->pb_Move_Down, &QPushButton::pressed, [=] {CameraMove(0.0, -0.5, 0.0);});
    connect(ui->pb_Move_Left, &QPushButton::pressed, [=] {CameraMove(-0.5, 0.0, 0.0);});
    connect(ui->pb_Move_Right, &QPushButton::pressed, [=] {CameraMove(0.5, 0.0, 0.0);});
    connect(ui->pb_Zoom_Up, &QPushButton::pressed, [=] {CameraMove(0.0, 0.0, 0.5);});
    connect(ui->pb_Zoom_Down, &QPushButton::pressed, [=] {CameraMove(0.0, 0.0, -0.5);});
    connect(ui->pb_Move_Up, SIGNAL(released()), this, SLOT(CameraStop()));
    connect(ui->pb_Move_Down, SIGNAL(released()), this, SLOT(CameraStop()));
    connect(ui->pb_Move_Left, SIGNAL(released()), this, SLOT(CameraStop()));
    connect(ui->pb_Move_Right, SIGNAL(released()), this, SLOT(CameraStop()));
    connect(ui->pb_Zoom_Up, SIGNAL(released()), this, SLOT(ZoomStop()));
    connect(ui->pb_Zoom_Down, SIGNAL(released()), this, SLOT(ZoomStop()));

    //QStandardItemModel *model = new QStandardItemModel(this);

    model->setStringList(GetPointList());
    ui->listView->setModel(model);

    connect(ui->listView, SIGNAL(clicked(const QModelIndex)), this, SLOT(PointChanged(QModelIndex)));
    connect(ui->listView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(PointEdit(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete _player;
    //delete _vw;
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
/// \brief MainWindow::discover
///Обнаружение подключенных видокамер
void MainWindow::discover()
{
    int nb_loops = 1;
//    if (CP->configTab->multiBroadcast->isChecked())
//        nb_loops = CP->configTab->broadcastRepeat->value();

    for (int k=0; k<nb_loops; k++) {
        OnvifSession *onvif_session = (OnvifSession*)malloc(sizeof(OnvifSession));
//        ConfigTab *configTab = CP->configTab;

        QString str = "Discovery started\n";
        onvif_session->discovery_msg_id = k;

        initializeSession(onvif_session);
        int number_of_cameras = broadcast(onvif_session);
        str.append(QString("libonvif found %1 cameras\n").arg(QString::number(number_of_cameras)));
//        emit msg(str);

        for (int i=0; i<number_of_cameras; i++) {
//            if (running) {
                OnvifData *onvif_data = (OnvifData*)malloc(sizeof(OnvifData));
                memset(onvif_data, 0, sizeof(OnvifData));
                prepareOnvifData(i, onvif_session, onvif_data);

//                emit msg(QString("Connecting to camera %1 at %2").arg(onvif_data->camera_name, onvif_data->xaddrs));

                QString username = ui->UserName->text();
                QString password = ui->Password->text();
                strncpy(onvif_data->username, username.toLatin1(), username.length());
                strncpy(onvif_data->password, password.toLatin1(), password.length());

                bool loggedIn = false;//alreadyLoggedIn(onvif_data);
/*                if (loggedIn) {
                    emit msg(QString("Duplicate discovery packet for camera %1\n").arg(onvif_data->camera_name));
                }*/

                while (!loggedIn) {
                    if (fillRTSP(onvif_data) == 0) {
                        loggedIn = true;
                        cameraList->pushCamera(onvif_data);
//                        addCamera(onvif_data);
                    }
/*                    else {
                        QString error_msg = onvif_data->last_error;
                        if (error_msg.contains("ter:NotAuthorized") || error_msg.contains("Unauthorized")) {
                            memset(&credential, 0, sizeof(credential));
                            strncpy(credential.camera_name, onvif_data->camera_name, strlen(onvif_data->camera_name));
//                            emit login(&credential);

//                            emit msg("starting login");
                            mutex.lock();
                            waitCondition.wait(&mutex);
                            mutex.unlock();

                            if (credential.accept_requested) {
                                strncpy(onvif_data->username, credential.username, strlen(credential.username));
                                strncpy(onvif_data->password, credential.password, strlen(credential.password));

                                if (fillRTSP(onvif_data) == 0) {
                                    loggedIn = true;
                                    addCamera(onvif_data);
                                }
                                else {
//                                    emit msg(QString("Login failure for camera %1\n").arg(onvif_data->camera_name));
                                }
                            }
                            else {
//                                emit msg(QString("Login cancelled for camera %1\n").arg(onvif_data->camera_name));
                                break;
                            }
                        }
                        else {
//                            emit msg(QString("ONVIF error %1\n").arg(onvif_data->last_error));
                            break;
                        }
                    }*/
                }
/*            }
            else {
                break;
            }*/
        }

        closeSession(onvif_session);
        free(onvif_session);
        //thread->msleep(200);
    }
    //stop();
}


void MainWindow::on_pushButton_clicked()
{
    struct OnvifSession *onvif_session = (struct OnvifSession*)malloc(sizeof(struct OnvifSession));

//    struct OnvifData *onvif_data = (struct OnvifData*)malloc(sizeof(struct OnvifData));
    initializeSession(onvif_session);
    int index = ui->Host->currentIndex();
    Camera  *camera = cameraList->getCameraAt(index);
    if(camera == nullptr) return;
    OnvifData *onvif_data = camera->onvif_data;


    QString onvifHost = ui->Host->currentText();
    QString user = ui->UserName->text();
    QString pass = ui->Password->text();

//    clearData(onvif_data);
//  strncpy(onvif_data->camera_name, "UNKNOWN CAMERA", strlen(onvif_data->camera_name));
//    strcpy(onvif_data->device_service, "POST /onvif/device_service HTTP/1.1");
//    strcpy(onvif_data->xaddrs, onvifHost.toStdString().c_str());
    strcpy(onvif_data->username, user.toStdString().c_str());
    strcpy(onvif_data->password, pass.toStdString().c_str());

    extractOnvifService(onvif_data->device_service, true);
//    getTimeOffset(onvif_data);
// time_offset not set correctly for some cameras? so set = 0 explicitely if needed
//qDebug() << "Time offset " << onvif_data->time_offset;
//    qDebug("Time offset " + onvif_data->time_offset);
    onvif_data->time_offset = 0;

    if( fillRTSP(onvif_data) == 0 ) {
        ui->textEdit->append( onvif_data->stream_uri );
    }

    getCapabilities(onvif_data);

    saveProfiles("Profiles.txt", onvif_data);

    QString login = user + ":" + pass + "@";
    QString url = QString(onvif_data->stream_uri);
    url.insert(7,login);
    CreateStream(url);

    closeSession(onvif_session);
    free(onvif_session);
//    free(onvif_data);
}

void MainWindow::on_pushButton_2_clicked()
{
    struct OnvifSession *onvif_session = (struct OnvifSession*)malloc(sizeof(struct OnvifSession));
    onvif_session->discovery_msg_id = 0;
    initializeSession(onvif_session);
    int number_of_cameras = broadcast(onvif_session);
    fprintf(stdout, "libonvif found %d cameras\n", number_of_cameras);

    ui->Host->clear();
    for (int i = 0; i < number_of_cameras; i++) {
      struct OnvifData *onvif_data = (struct OnvifData*)malloc(sizeof(struct OnvifData));
      prepareOnvifData(i, onvif_session, onvif_data);

      ui->textEdit->append(onvif_data->camera_name);
      ui->textEdit->append( onvif_data->xaddrs );
      ui->textEdit->append( onvif_data->device_service );
      ui->Host->addItem(onvif_data->xaddrs);

//      getCapabilities(onvif_data);
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

    closeSession(onvif_session);
    free(onvif_session);
//    free(onvif_data);
}

void MainWindow::on_pushButton_3_clicked()
{
    struct OnvifSession *onvif_session = (struct OnvifSession*)malloc(sizeof(struct OnvifSession));
    struct OnvifData *onvif_data = (struct OnvifData*)malloc(sizeof(struct OnvifData));
    initializeSession(onvif_session);


    QString onvifHost = ui->Host->currentText();
    QString user = ui->UserName->text();
    QString pass = ui->Password->text();

    clearData(onvif_data);
    strncpy(onvif_data->camera_name, "UNKNOWN CAMERA", strlen(onvif_data->camera_name));
    strcpy(onvif_data->device_service, "POST /onvif/device_service HTTP/1.1");
    strcpy(onvif_data->xaddrs, onvifHost.toStdString().c_str());

    strcpy(onvif_data->username, user.toStdString().c_str());
    strcpy(onvif_data->password, pass.toStdString().c_str());

    extractOnvifService(onvif_data->device_service, true);
    getTimeOffset(onvif_data);
    onvif_data->time_offset = 0;

    // getCapabilities fills in service addresses
    getCapabilities(onvif_data);

    saveProfiles("Profiles.txt", onvif_data);

    closeSession(onvif_session);
    free(onvif_session);
//    free(onvif_data);
}

void MainWindow::GetPosition()
{
    struct OnvifSession *onvif_session = (struct OnvifSession*)malloc(sizeof(struct OnvifSession));

    OnvifData *onvif_data = GetCurrentOnviv();

    initializeSession(onvif_session);

    QString user = ui->UserName->text();
    QString pass = ui->Password->text();
    strcpy(onvif_data->username, user.toStdString().c_str());
    strcpy(onvif_data->password, pass.toStdString().c_str());

    //GetPosition(x,y,z,onvif_data);
    //CurentPoint.X = x;
    //CurentPoint.Y = y;
    //CurentPoint.Z = z;


    closeSession(onvif_session);
    free(onvif_session);
    //emit eUpdateShift;
}

/// Позиционирование и зумирование камеры
/// \brief MainWindow::CameraMove
/// \param x - лево, право
/// \param y - вниз, вверх
/// \param z - зум +, -
///
void MainWindow::CameraMove(float x,float y,float z)
{
    struct OnvifSession *onvif_session = (struct OnvifSession*)malloc(sizeof(struct OnvifSession));

    OnvifData *onvif_data = GetCurrentOnviv();

    initializeSession(onvif_session);

    QString user = ui->UserName->text();
    QString pass = ui->Password->text();
    strcpy(onvif_data->username, user.toStdString().c_str());
    strcpy(onvif_data->password, pass.toStdString().c_str());

    continuousMove(x,y,z,onvif_data);


    closeSession(onvif_session);
    free(onvif_session);
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
    videowdg->move(290,5);
    videowdg->resize(width()-295,height()-90);
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
    OnvifData *onvif_data = GetCurrentOnviv();
    struct OnvifSession *onvif_session = (struct OnvifSession*)malloc(sizeof(struct OnvifSession));
    initializeSession(onvif_session);

/*    QString user = ui->UserName->text();
    QString pass = ui->Password->text();
    strcpy(onvif_data->username, user.toStdString().c_str());
    strcpy(onvif_data->password, pass.toStdString().c_str());*/

    moveStop(ZOOM_STOP,onvif_data);

    closeSession(onvif_session);
    free(onvif_session);
}

/// Остановка позиционирования
/// \brief MainWindow::CameraStop
///
void MainWindow::CameraStop()
{
    OnvifData *onvif_data = GetCurrentOnviv();
    struct OnvifSession *onvif_session = (struct OnvifSession*)malloc(sizeof(struct OnvifSession));
    initializeSession(onvif_session);

/*    QString user = ui->UserName->text();
    QString pass = ui->Password->text();
    strcpy(onvif_data->username, user.toStdString().c_str());
    strcpy(onvif_data->password, pass.toStdString().c_str());*/

    moveStop(PAN_TILT_STOP,onvif_data);

    closeSession(onvif_session);
    free(onvif_session);
}

/// Получить структуру ONVIV к текущей камере
/// \brief MainWindow::GetCurrentOnviv
/// \return
///
OnvifData * MainWindow::GetCurrentOnviv()
{
    int index = ui->Host->currentIndex();
    Camera  *camera = cameraList->getCameraAt(index);
    if(camera == nullptr) return nullptr;
    OnvifData *onvif_data = camera->onvif_data;
    return onvif_data;
}


/// Считать пресет
/// \brief MainWindow::on_pb_Preset_Load_clicked
///
void MainWindow::on_pb_Preset_Load_clicked()
{
    char* pos;
    std::string  num = QString::number(CurrentPointIndex).toStdString();
    pos = new char [num.size()+1];
    strcpy( pos, num.c_str() );
//    const char *p = QString::number(CurrentPointIndex).toStdString().c_str();
    OnvifData *onvif_data = GetCurrentOnviv();
    struct OnvifSession *onvif_session = (struct OnvifSession*)malloc(sizeof(struct OnvifSession));
    initializeSession(onvif_session);
    //char * pos = "1";//  QString::number(CurrentPointIndex).toUtf8().data();// Local8Bit().data();
    gotoPreset(pos, onvif_data);

    closeSession(onvif_session);
    free(onvif_session);
}

/// Записать пресет
/// \brief MainWindow::on_pb_Preset_Save_clicked
///
void MainWindow::on_pb_Preset_Save_clicked()
{
    char* pos;
    std::string  num = QString::number(CurrentPointIndex).toStdString();
    pos = new char [num.size()+1];
    strcpy( pos, num.c_str() );

    OnvifData *onvif_data = GetCurrentOnviv();
    struct OnvifSession *onvif_session = (struct OnvifSession*)malloc(sizeof(struct OnvifSession));
    initializeSession(onvif_session);
    //char * pos =  "1";//QString::number(CurrentPointIndex).toUtf8().data();
    setPreset(pos, onvif_data);

    closeSession(onvif_session);
    free(onvif_session);
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
    dialog->SetCoord(cp.X,cp.Y,cp.Z);
    if(dialog->exec()==QDialog::Accepted)
    {// showNormal();
        dialog->GetCoord(cp.X,cp.Y,cp.Z);
        config->SetPoint(i,cp);
        config->UpDatePoint();
    }
}

void MainWindow::on_pushButton_SetCamCoord_clicked()
{
    int index = ui->Host->currentIndex();
    Camera  *camera = cameraList->getCameraAt(index);
    if(camera == nullptr) return ;

    DialogCoordEdit * dialog = new DialogCoordEdit(this);
    dialog->SetCoord(camera->Coord.X,camera->Coord.Y,camera->Coord.Z);
    dialog->showNormal();
    dialog->GetCoord(camera->Coord.X,camera->Coord.Y,camera->Coord.Z);
}

void MainWindow::on_toolButton_Add_clicked()
{
    CamPoint cp;
    cp.X = 0;
    cp.Y = 0;
    cp.Z = 0;
    config->AddPoint(cp);
    config->UpDatePoint();
    model->setStringList(GetPointList());
}
