#ifndef STATVIEW_H
#define STATVIEW_H
#include <QObject>
#include <QtWidgets>
#include "src/h/cwidgets.h"
#include "src/h/histogramview.h"

class CstatView : public CFrame{
    Q_OBJECT

public:
    CstatView(QWidget *parent = 0);
    ~CstatView();

private:
   // v,h boxes
    QVBoxLayout *mainBox;
    QHBoxLayout *statHBox;
   // form layout
    QFormLayout *formStatDevices;
    QFormLayout *formStatDangerous;
   // labels
    QLabel *lbDevices;
    QLabel *lbDangerous;
    QLabel *leDevices;
    QLabel *leDangerous;
   // line edits
   // other
    ChistogramView *histogram;

};

#endif // STATVIEW_H
