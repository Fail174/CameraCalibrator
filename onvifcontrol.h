#ifndef ONVIFCONTROL_H
#define ONVIFCONTROL_H

#include <QObject>
#include "OnvifDeviceClient.h"
#include "OnvifPtzClient.h"
//#include "OnvifMediaClient.h"

typedef struct
{
    QDateTime time;
    double pan;
    double tilt;
    double zoom;
} PtzStatus;

class OnvifControl : public QObject
{
    Q_OBJECT
public:
    explicit OnvifControl(QObject *parent = nullptr);
    QString ProfileToken = "";
    OnvifPtzClient *ptzClient = nullptr;
    //OnvifMediaClient *mediaClient = nullptr;
    QString stream_uri;
    QString xaddrs;

    void InitPtzClient(QString ipaddr, QString login, QString pass);
    void ClosePtzClient();
    void CloseMediaClient();
    PtzStatus getPtzStatus();
    void PtzStop();
    void ContinuousMove(float x, float y, float z);
    void AbsoluteMove(float x, float y, float z);
    int GetDeviceServices( QString ipaddr, QString login, QString pass);
    void InitMediaClient(QString ipaddr, QString login, QString pass);
    void GetProfile(QString ipaddr, QString login, QString pass);
    void GetStreamUri(QString ipaddr, QString login, QString pass);

signals:

};

#endif // ONVIFCONTROL_H
