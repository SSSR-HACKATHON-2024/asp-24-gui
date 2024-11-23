#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QObject>
#include <QtWidgets>
#include "cwidgets.h"
#include "tasksview.h"

class CmainView : public CFrame{
    Q_OBJECT

public:
    CmainView(QWidget *parent = 0);
    ~CmainView();

private:
   // v,h boxes
    QVBoxLayout *mainBox;
   // group boxes
    QGroupBox *gbTest;
   // form layout
    QFormLayout *formIp;
   // labels
   // line edits
   // buttons, spin boxes
   // other
    QTabWidget *tabs;
    CtasksView *tasks;
};

#endif // MAINVIEW_H
