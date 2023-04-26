#ifndef MAINSETTINGS_H
#define MAINSETTINGS_H
#include <QSettings>

struct Point3D
{
    double X;
    double Y;
    double Z;
};

struct CamPoint
{
    QString Name;
    Point3D Coord;
};

class MainSettings
{
public:
    uint PointCount = 0;
    uint CameraCount = 0;
    //кординаты верхнего левого и нижнего правого углов карты
   /* double mapX1=6429078.837;
    double mapY1=6404852.044;
    double mapX2=6426858.325;
    double mapY2=6403720.353;*/
     double mapX1=6429317.476;
     double mapY1=6405073.396;
     double mapX2=6426985.564;
     double mapY2=6403692.788;

    QList<CamPoint> *PointList = nullptr;
    QList<CamPoint> *CameraList = nullptr;

    MainSettings();
    QVariant readValue(const QString &key, const QVariant &defaultValue);
    void saveValue(const QString &key, const QVariant &value);
    void AddPoint(CamPoint cp);
    void DelPoint(int i);
    void AddCamera(CamPoint cp);
    void DelCamera(int i);
    CamPoint GetPoint(int index);
    void SetPoint(int i, CamPoint cp);
    void SetCamera(int i, CamPoint cp);
    CamPoint GetCamera(int index);
    void UpDatePoint();
    void UpDateCamera();
    QStringList GetPointList();
    QStringList GetCameraList();
signals:
    void sendError(const QString &errStr);
private:
    QSettings * config = nullptr;

    QString convertErrorCodeToString(QSettings::Status code);
    void initSettings();
    CamPoint * initPoint(int i);
    CamPoint * initCamera(int i);



};

#endif // MAINSETTINGS_H
