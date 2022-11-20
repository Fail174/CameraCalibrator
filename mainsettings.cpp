#include "mainsettings.h"

MainSettings::MainSettings()
{
    QString initFileName = "calibrator.ini";
    config = new QSettings(initFileName,QSettings::IniFormat);
    PointList = new QList<CamPoint>();
    CameraList = new QList<CamPoint>();
    initSettings();
}


/**
 * @brief MainSettings::readValue
 *        Чтение параметра key из файла настроек
 * @param key
 * @param defaultValue значение по умолчанию
 * @return
 */
QVariant MainSettings::readValue(const QString &key, const QVariant &defaultValue)
{
    QVariant value = config->value(key, defaultValue);
    QSettings::Status status = config->status();
    //при чтении произошла какая-то ошибка
    if(status != QSettings::NoError) {
//        emit sendError(convertErrorCodeToString(status));
    }
    return value;
}

/**
 * @brief MainSettings::saveValue
 * @param key
 * @param value
 */
void MainSettings::saveValue(const QString &key, const QVariant &value)
{
    config->setValue(key, value);
    config->sync();
    QSettings::Status status = config->status();
    if(status != QSettings::NoError) {
//        emit sendError(convertErrorCodeToString(status));
    }
}

/**
 * @brief MainSettings::convertErrorCodeToString
 * @param code код статуса QSettings
 * @return errorString
 */
QString MainSettings::convertErrorCodeToString(QSettings::Status code)
{
    QString errorString = "";
    switch (code) {
    case QSettings::NoError:
        errorString = "NoError";
        break;
    case QSettings::AccessError:
        errorString = "AccessError";
        break;
    case QSettings::FormatError:
        errorString = "FormatError";
        break;
    default:
        errorString = "InvalidCodeError";
        break;
    }
    return errorString;
}


/**
 * @brief MainWindow::initSettings
 * Инициализация настроек программы
 */
void MainSettings::initSettings()
{
    QString tmpStr = readValue("POINT_SETTINGS/Count", "").toString();
    uint tmpValue;
    if(!tmpStr.isEmpty())
    {
        bool ok = false;
        tmpValue = tmpStr.toUInt(&ok);
        if(!ok)     saveValue("POINT_SETTINGS/Count", QString::number(PointCount));
        else        PointCount = tmpValue;
    }
    else saveValue("POINT_SETTINGS/Count", QString::number(PointCount));

    for(int i=0;i<PointCount;i++)
    {
        CamPoint *cp=  initPoint(i);
        PointList->append(*cp);
    }


    tmpStr = readValue("CAMERA_SETTINGS/Count", "").toString();
    if(!tmpStr.isEmpty())
    {
        bool ok = false;
        tmpValue = tmpStr.toUInt(&ok);
        if(!ok)     saveValue("CAMERA_SETTINGS/Count", QString::number(CameraCount));
        else        CameraCount = tmpValue;
    }
    else saveValue("CAMERA_SETTINGS/Count", QString::number(CameraCount));

    for(int i=0;i<CameraCount;i++)
    {
        CamPoint *cp=  initCamera(i);
        CameraList->append(*cp);
    }
}

CamPoint *MainSettings::initPoint(int i)
{
    CamPoint *Coord = new CamPoint;
    QString fieldName = "POINT_" +QString::number(i)+"/Name";
    QString tmpStr = readValue(fieldName, "").toString();

    if(!tmpStr.isEmpty())
    {
        Coord->Name = tmpStr;
    }
    else {
        Coord->Name = "Point " + QString::number(i);
        saveValue(fieldName, Coord->Name);
    }

    fieldName = "POINT_" +QString::number(i)+"/CoordX";
    tmpStr = readValue(fieldName, "").toString();
    uint tmpValue;
    if(!tmpStr.isEmpty())
    {
        bool ok = false;
        tmpValue = tmpStr.toUInt(&ok);
        if(!ok)     saveValue(fieldName, QString::number(Coord->X));
        else        Coord->X = tmpValue;
    }
    else saveValue(fieldName, QString::number(Coord->X));


    fieldName = "POINT_" +QString::number(i)+"/CoordY";
    tmpStr = readValue(fieldName, "").toString();
    if(!tmpStr.isEmpty())
    {
        bool ok = false;
        tmpValue = tmpStr.toUInt(&ok);
        if(!ok)     saveValue(fieldName, QString::number(Coord->Y));
        else        Coord->Y = tmpValue;
    }
    else saveValue(fieldName, QString::number(Coord->Y));


    fieldName = "POINT_" +QString::number(i)+"/CoordZ";
    tmpStr = readValue(fieldName, "").toString();
    if(!tmpStr.isEmpty())
    {
        bool ok = false;
        tmpValue = tmpStr.toUInt(&ok);
        if(!ok)     saveValue(fieldName, QString::number(Coord->Z));
        else        Coord->Z = tmpValue;
    }
    else saveValue(fieldName, QString::number(Coord->Z));

    return Coord;
}


CamPoint *MainSettings::initCamera(int i)
{
    CamPoint *Coord = new CamPoint;
    QString fieldName = "CAMERA_" +QString::number(i)+"/Name";
    QString tmpStr = readValue(fieldName, "").toString();

    if(!tmpStr.isEmpty())
    {
        Coord->Name = tmpStr;
    }
    else {
        Coord->Name = "Camera " + QString::number(i);
        saveValue(fieldName, Coord->Name);
    }

    fieldName = "CAMERA_" +QString::number(i)+"/CoordX";
    tmpStr = readValue(fieldName, "").toString();
    uint tmpValue;
    if(!tmpStr.isEmpty())
    {
        bool ok = false;
        tmpValue = tmpStr.toUInt(&ok);
        if(!ok)     saveValue(fieldName, QString::number(Coord->X));
        else        Coord->X = tmpValue;
    }
    else saveValue(fieldName, QString::number(Coord->X));


    fieldName = "CAMERA_" +QString::number(i)+"/CoordY";
    tmpStr = readValue(fieldName, "").toString();
    if(!tmpStr.isEmpty())
    {
        bool ok = false;
        tmpValue = tmpStr.toUInt(&ok);
        if(!ok)     saveValue(fieldName, QString::number(Coord->Y));
        else        Coord->Y = tmpValue;
    }
    else saveValue(fieldName, QString::number(Coord->Y));


    fieldName = "CAMERA_" +QString::number(i)+"/CoordZ";
    tmpStr = readValue(fieldName, "").toString();
    if(!tmpStr.isEmpty())
    {
        bool ok = false;
        tmpValue = tmpStr.toUInt(&ok);
        if(!ok)     saveValue(fieldName, QString::number(Coord->Z));
        else        Coord->Z = tmpValue;
    }
    else saveValue(fieldName, QString::number(Coord->Z));

    return Coord;
}

void MainSettings::AddPoint(CamPoint cp)
{
    PointList->append(cp);
    PointCount++;
}

CamPoint MainSettings::GetPoint(int index)
{
    return PointList->at(index);
}

void MainSettings::SetPoint(int i, CamPoint cp)
{
    PointList->removeAt(i);
    PointList->insert(i, cp);
}

void MainSettings::AddCamera(CamPoint cp)
{
    CameraList->append(cp);
    CameraCount++;
}

void MainSettings::UpDatePoint()
{
    QString fieldName = "POINT_SETTINGS/Count";
    saveValue(fieldName, QString::number(PointCount));
    for(int i=0;i<PointCount;i++)
    {
        CamPoint cp = PointList->at(i);
        fieldName = "POINT_" +QString::number(i)+"/CoordX";
        saveValue(fieldName, QString::number(cp.X));

        fieldName = "POINT_" +QString::number(i)+"/CoordY";
        saveValue(fieldName, QString::number(cp.Y));

        fieldName = "POINT_" +QString::number(i)+"/CoordZ";
        saveValue(fieldName, QString::number(cp.Z));
    }
}

void MainSettings::UpDateCamera()
{
    QString fieldName = "CAMERA_SETTINGS/Count";
    saveValue(fieldName, QString::number(CameraCount));
    for(int i=0;i<CameraCount;i++)
    {
        CamPoint cp = CameraList->at(i);
        QString fieldName = "CAMERA_" +QString::number(i)+"/CoordX";
        saveValue(fieldName, QString::number(cp.X));

        fieldName = "CAMERA_" +QString::number(i)+"/CoordY";
        saveValue(fieldName, QString::number(cp.Y));

        fieldName = "CAMERA_" +QString::number(i)+"/CoordZ";
        saveValue(fieldName, QString::number(cp.Z));
    }
}

QStringList MainSettings::GetPointList()
{
    QStringList str;
    for(int i=0; i<PointCount;i++)
    {
        str << "Точка " + QString::number(i);
    }
    return str;
}
