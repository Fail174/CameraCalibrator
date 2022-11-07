/*******************************************************************************
* cameralistmodel.cpp
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

#include "cameralistmodel.h"


CameraListModel::CameraListModel()
{

}

int CameraListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return cameras.size();
}

QVariant CameraListModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && (role == Qt::DisplayRole || role == Qt::EditRole)) {
        Camera *tmp = (Camera *)cameras[index.row()];
        return tmp->getCameraName();
    }
    return QVariant();
}

bool CameraListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole) {
        Camera *camera = (Camera *)cameras[index.row()];
        strncpy(camera->onvif_data->camera_name, value.toString().toLatin1(), value.toString().length());
        return true;
    }
    else {
        return false;
    }
}

Qt::ItemFlags CameraListModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractListModel::flags(index);
}

void CameraListModel::beginInsertItems(int start, int end)
{
    beginInsertRows(QModelIndex(), start, end);
}

void CameraListModel::endInsertItems()
{
    //endInsertRows();
}

void CameraListModel::pushCamera(OnvifData *onvif_data)
{
    bool found = false;
    for (int i = 0; i < cameras.size(); i++) {
        if (!strcmp(onvif_data->xaddrs, cameras[i]->onvif_data->xaddrs))
            found = true;
    }
    if (!found) {
        Camera *camera = new Camera(onvif_data);
        cameras.push_back(camera);
        emit dataChanged(QModelIndex(), QModelIndex());
    }
}

Camera * CameraListModel::getCameraAt(int index)
{
    if(cameras.length()>index && index>=0)
    {
        return cameras[index];
    }else{
        return nullptr;
    }
}

void CameraListModel::onSelectedItemsChanged(QItemSelection selected, QItemSelection deselected)
{
    Q_UNUSED(deselected)
    if (!selected.empty()) {
        int index = selected.first().indexes().first().row();
        Camera *camera = cameras[index];
        if (camera->onvif_data_read) {
            emit showCameraData();
        }
        else {
            emit getCameraData();
        }
    }
}
