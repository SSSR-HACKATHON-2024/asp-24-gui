#ifndef CGROUPBOX_H
#define CGROUPBOX_H

#include <QObject>
#include <QGroupBox>

class CGroupBox : public QGroupBox{

public:
    CGroupBox(QWidget *parent = 0);
    CGroupBox(const QString &title,QWidget *parent = 0);

private:
    void set_style();

};

#endif // CGROUPBOX_H
