#ifndef CAMERAMATH_H
#define CAMERAMATH_H
#include "mainsettings.h"
#include "camera.h"

class cameramath
{
public:
    cameramath();
    double dA;
    double dE;
    double dC;
    QList<Point3D> Pointlist;//координаты точек в системе WGS
    QList<Point3D> CameraList;//координаты камер в системе WGS

    QList<Point3D> CameraPoint;//координаты точек в системе камеры

    /// Расчет гипотенузы в 3D
    /// \brief hypot3D
    /// \param x
    /// \param y
    /// \param z
    /// \return
    double hypot3D(double x, double y, double z);

    /// Расчет растояния между камерой и реперной точкой
    /// \brief GetDistans
    /// \param nc
    /// \param np
    /// \return
    double GetDistans(int nc, int np);

    /// Расчет крена для камеры nc по двум точкам
    /// \brief CalculateCren
    /// \param nc номер камеры
    /// \param p1 номер первой точки
    /// \param p2 номер второй точки
    /// \return крен в град
    double CalculateCren(int nc, int p1, int p2);

    /// Расчет поправки к углу места
    /// \brief CalcElevation
    /// \param nc номер камеры
    /// \param p1 номер точки
    /// \return поправка к углу места в град
    double CalcElevation(int nc, int p1);

    /// Расчет поправки по азимуту
    /// \brief CalcAzimut
    /// \param nc номер камеры
    /// \param p1 номер первой точки
    /// \return поправка по азимуту
    double CalcAzimut(int nc, int p1);

    bool StartCalc(int nc);

    void UpdateData(QList<CamPoint> *cam, QList<CamPoint> *pl);
    void UpdatePointCoord(QList<Point3D> *p);//координаты маркеров в системе камеры
};

#endif // CAMERAMATH_H
