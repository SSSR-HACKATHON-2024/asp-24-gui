#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QObject>
#include <QtWidgets>
#include "cwidgets.h"
#include "src/h/scanview.h"
#include "src/h/statview.h"
#include "src/h/db.h"

class CmainView : public CFrame{
    Q_OBJECT

public:
    CmainView(QWidget *parent = 0);
    ~CmainView();

private:
   // v,h boxes
    QVBoxLayout *mainBox;
    QVBoxLayout *statBox;
   // group boxes
    QGroupBox *gbStat;
   // form layout
    QFormLayout *formIp;
   // labels
   // line edits
   // buttons, spin boxes
   // other
    QTabWidget *tabs;
    CstatView *stat;
    CscanView *scan;
};

#endif // MAINVIEW_H
