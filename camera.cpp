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

Camera::Camera(OnvifData *arg)
{
    onvif_data = arg;
    CameraPoint = new QList<Point3D>();
}

Camera::~Camera()
{
    delete CameraPoint;
    free(onvif_data);
}

QString Camera::getCameraName()
{
    return QString(onvif_data->camera_name);
}

bool Camera::hasPTZ()
{
    if (strcmp(onvif_data->ptz_service, "") == 0)
        return false;
    else
        return true;
}

void Camera::SetPoint(int num, Point3D coord)
{
    if(num>CameraPoint->count())
    {
        CameraPoint->append(coord);
    }else{
        Point3D p = CameraPoint->at(num);
        CameraPoint->removeAt(num);
        CameraPoint->insert(num,coord);
    }
}
