/*******************************************************************************
* camera.cpp
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

#include "camera.h"
#include <cmath>

Camera::Camera(QString addr)
{
    xaddrs = addr;
    CameraPoint = new QList<Point3D>();
}

Camera::~Camera()
{
    delete CameraPoint;
}

QString Camera::getCameraName()
{
    return xaddrs;
}

double Camera::GetRange(int i)
{
    double dx = CameraPoint->at(i).X;
    double dy = CameraPoint->at(i).Y;
    double dz = CameraPoint->at(i).Z;
    double A = sqrt(dz*dz+dy*dy+dx*dx);
    return  A;
}

double Camera::GetAzimut(int i)
{
    double dx = CameraPoint->at(i).X;
    double dy = CameraPoint->at(i).Y;
    double A = atan(dx/dy);
    if(A<0) A = A + M_PI*2;
    return  A*180/M_PI;
}

double Camera::GetElevation(int i)
{
    double dx = CameraPoint->at(i).X;
    double dy = CameraPoint->at(i).Y;
    double dz = CameraPoint->at(i).Z;
    double E = atan(dz/sqrt(dy*dy+dx*dx));
    if(E>M_PI/2) E = E - M_PI*2;
    return  E*180/M_PI;
}

void Camera::SetPoint(int num, Point3D coord)
{
    if(num>=CameraPoint->count())
    {
        CameraPoint->append(coord);
    }else{
        Point3D p = CameraPoint->at(num);
        CameraPoint->removeAt(num);
        CameraPoint->insert(num,coord);
    }
}
