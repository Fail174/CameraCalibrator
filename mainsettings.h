#ifndef MAINSETTINGS_H
#define MAINSETTINGS_H
#include <QSettings>

struct CamPoint
{
    QString Name;
    double X;
    double Y;
    double Z;
};

class MainSettings
{
public:
    MainSettings();
    QVariant readValue(const QString &key, const QVariant &defaultValue);
    void saveValue(const QString &key, const QVariant &value);
    void AddPoint(CamPoint cp);
    void AddCamera(CamPoint cp);
    CamPoint GetPoint(int index);
    void SetPoint(int i, CamPoint cp);
    void UpDatePoint();
    void UpDateCamera();
    QStringList GetPointList();
signals:
    void sendError(const QString &errStr);
private:
    QSettings * config = nullptr;
    uint PointCount = 0;
    uint CameraCount = 0;
    QList<CamPoint> *PointList = nullptr;
    QList<CamPoint> *CameraList = nullptr;

    QString convertErrorCodeToString(QSettings::Status code);
    void initSettings();
    CamPoint * initPoint(int i);
    CamPoint * initCamera(int i);



};

#endif // MAINSETTINGS_H
