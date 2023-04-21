#include <cmath>
#include "cameramath.h"

cameramath::cameramath()
{
            //1 - 57.964123, 31.380582   высота 23,5 м
            //2 - 57.964166, 31.380603 высота 23,5 м
            //3 - 57.970696, 31.381620 высота 12,5 м
            //4 - 57.969204, 31.378819 высота 45 м
}

double cameramath::hypot3D(double x, double y, double z)
{
    return sqrt(x*x+y*y+z*z);
}


/// Расчет растояния между камерой и реперной точкой
/// \brief GetDistans
/// \param nc
/// \param np
/// \return
double cameramath::GetDistans(int nc, int np)
{
    Point3D point = Pointlist.at(np);
    Point3D camera = CameraList.at(nc);
    return hypot3D(point.X-camera.X,point.Y-camera.Y,point.Z-camera.Z);
}

/// Расчет крена для камеры nc по двум точкам
/// \brief CalculateCren
/// \param nc номер камеры
/// \param p1 номер первой точки
/// \param p2 номер второй точки
/// \return крен в град
double cameramath::CalculateCren(int nc, int p1, int p2)
{
    Point3D point1 = Pointlist.at(p1);
    Point3D point2 = Pointlist.at(p2);
    double delta = point1.Z - point2.Z;//реальная разность высот
    double dist = hypot3D(point1.X-point2.X,point1.Y-point2.Y,point1.Z-point2.Z);

    //координаты точек в системе камеры
    int N = Pointlist.count();
    Point3D camerapoint1 = CameraPoint.at(nc*N+p1);
    Point3D camerapoint2 = CameraPoint.at(nc*N+p2);
    double deltaH = camerapoint1.Z - camerapoint2.Z;//полученная разность высот

    deltaH = deltaH - delta;
    return asin(deltaH/dist)*180/M_PI;//ошибка по крену
}

/// Расчет поправки к углу места
/// \brief CalcElevation
/// \param nc номер камеры
/// \param p1 номер точки
/// \return поправка к углу места в град
double cameramath::CalcElevation(int nc, int p1)
{
    Point3D point = Pointlist.at(p1);
    Point3D camera = CameraList.at(nc);
    double D = GetDistans(nc,p1);
    double El1= asin((point.Z-camera.Z)/D)*180/M_PI;//реальный угол места на точку

    //координаты точки в системе камеры
    int N = Pointlist.count();
    Point3D camerapoint1 = CameraPoint.at(nc*N+p1);
    double dist = hypot3D(camerapoint1.X,camerapoint1.Y,camerapoint1.Z);
    double El2= asin(camerapoint1.Z/D)*180/M_PI;//полученный угол места на точку

    return (El2 - El1)*180/M_PI;//ошибка по углу места

}

/// Расчет поправки по азимуту
/// \brief CalcAzimut
/// \param nc номер камеры
/// \param p1 номер первой точки
/// \return поправка по азимуту
double cameramath::CalcAzimut(int nc, int p1)
{
    //азимут отностительно севера
    Point3D point = Pointlist.at(p1);
    Point3D camera = CameraList.at(nc);
    double a1 = atan((point.X-camera.X)/(point.Y-camera.Y));//реальный азимут

    //координаты точки в системе камеры
    int N = Pointlist.count();
    Point3D camerapoint = CameraPoint.at(nc*N+p1);
    double a2 = atan(camerapoint.X/camerapoint.Y);//полученный азимут

    return a2-a1;//поправка по азимуту
}
///
/// \brief cameramath::StartCalc
/// \param nc
/// \return
/// Расчет поправок для камеры номер nc
bool cameramath::StartCalc(int nc)
{
    dA=0;
    dE=0;
    dC=0;
    if((nc<0)||(CameraList.count()<=nc)) return false;
    int i=0,j;
    for(i=0;i<Pointlist.count();i++)
    {
        dA = dA + CalcAzimut(nc, i);
        dE = dE + CalcElevation(nc, i);
        if(i>0)
        {
            j = i - 1;
        }else{
            j = Pointlist.count()-1;
        }
        dC = dC + CalculateCren(nc,i,j);
    }

    //расчет усредненных поправок
    if(i>0){
        dA = dA/i;
        dE = dE/i;
        dC = dC/i;
        return true;
    }
    return false;
}

void cameramath::UpdateData(QList<CamPoint> *cam, QList<CamPoint> *pl)
{
    if( cam!=nullptr && pl!=nullptr )
    {
        CameraList.clear();
        Pointlist.clear();
        for(int i=0;i<pl->count();i++)
        {
            CamPoint point = pl->at(i);
            Pointlist.append(point.Coord);
        }

        for(int i=0;i<cam->count();i++)
        {
            CamPoint point = cam->at(i);
            CameraList.append(point.Coord);

        }
    }
}

void cameramath::UpdatePointCoord(QList<Point3D> *p)//координаты маркеров в системе камеры
{
    if( p!=nullptr)
    {
        CameraPoint.clear();
        for(int i=0;i<p->count();i++)
        {
            Point3D point = p->at(i);
            CameraPoint.append(point);
        }
    }
}

