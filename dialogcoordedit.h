#ifndef DIALOGCOORDEDIT_H
#define DIALOGCOORDEDIT_H

#include <QDialog>

namespace Ui {
class DialogCoordEdit;
}

class DialogCoordEdit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogCoordEdit(QWidget *parent = 0);
    ~DialogCoordEdit();
    void SetName(QString name);
    QString GetName();
    void SetCoord(double X, double Y, double Z);
    void GetCoord(double &X, double &Y, double &Z);
private:
    Ui::DialogCoordEdit *ui;
};

#endif // DIALOGCOORDEDIT_H
