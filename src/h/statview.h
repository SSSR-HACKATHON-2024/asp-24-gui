#ifndef STATVIEW_H
#define STATVIEW_H
#include <QObject>
#include <QtWidgets>
#include "src/h/cwidgets.h"
#include "src/h/histogramview.h"
#include "src/h/db.h"

class CstatView : public CFrame{
    Q_OBJECT

public:
    CstatView(QWidget *parent = 0);
    ~CstatView();

private:
   // v,h boxes
    QVBoxLayout *mainBox;
    QVBoxLayout *rightInfoBox;
    QVBoxLayout *leftInfoBox;
    QHBoxLayout *statHBox;
    QVBoxLayout *topCveBox;
   // group boxes
    QGroupBox *gbTopCve;
   // form layout
    QFormLayout *formCveCount;
    QFormLayout *formStatDevices;
    QFormLayout *formStatDangerous;
   // labels
    QLabel *lbCveCount;
    QLabel *lbDevices;
    QLabel *lbDangerous;
    QLabel *leCveCount;
    QLabel *leDevices;
    QLabel *leDangerous;
   // line edits
   // other
    CTableWidget *tableCve;
    ChistogramView *histogram;
    QTimer *timer;
   // methods
    void read_right_part();
    void read_left_part();

private slots:
    void on_tableCveDoubleClicked(QModelIndex index);
    void on_timer_alarm();

};

#endif // STATVIEW_H
