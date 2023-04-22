/*******************************************************************************
* camera.h
*
* Copyright (c) 2020 Stephen Rhodes
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along
* with this program; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*
*******************************************************************************/

#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include "mainsettings.h"


class Camera : public QObject
{
    Q_OBJECT

public:
    Camera(QString addr);
    ~Camera();
    QString xaddrs;

    QString getCameraName();

    bool onvif_data_read = false;
    CamPoint Data;
    double A=0;
    double E=0;
    double C=0;
    double GetAzimut(int i);
    double GetElevation(int i);
    double GetRange(int i);
    QList<Point3D> *CameraPoint;//координаты точек в системе камеры
    void SetPoint(int num, Point3D coord);
};

#endif // CAMERA_H
