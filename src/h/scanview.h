#ifndef SCANVIEW_H
#define SCANVIEW_H

#include <QObject>
#include <QtWidgets>
#include "src/h/cwidgets.h"
#include <QHostAddress>

class CscanView : public CFrame{
    Q_OBJECT

public:
    CscanView(QWidget *parent = 0);

private:
   // v,h boxes
    QVBoxLayout *mainBox;
    QVBoxLayout *wayBox;
    QVBoxLayout *fullBox;
    QVBoxLayout *tableHistoryBox;
    QVBoxLayout *tableActualBox;
    QHBoxLayout *ipHBox;
    QHBoxLayout *radioHBox;
    QHBoxLayout *tablesHBox;
   // group boxes
    QGroupBox *gbScanWay;
    QGroupBox *gbScanFull;
    QGroupBox *gbWay;
    QGroupBox *gbFull;
    QGroupBox *gbTableHistory;
    QGroupBox *gbTableActual;
   // form layouts
    QFormLayout *formIp;
    QFormLayout *formRadioWay;
    QFormLayout *formRadioFull;
   // labels
    QLabel *lbIp;
    QLabel *lbExample;
    QLabel *lbWayAgressive;
    QLabel *lbWaySecretive;
    QLabel *lbFullFull;
    QLabel *lbFullFast;
   // line edits
    QLineEdit *leIp;
   // buttons, spin boxes
    QPushButton *pbScan;
    QPushButton *pbOpenFile;
    QRadioButton *radioWayAgressive;
    QRadioButton *radioWaySecretive;
    QRadioButton *radioFullFull;
    QRadioButton *radioFullFast;
   // other
    CTableWidget *tableHistory;
    CTableWidget *tableActual;
   // methods
    bool valid_ip(const QString &ip);

private slots:
    void on_pbScan_clicked();
    void on_pbOpenFile_clicked();
};

#endif // SCANVIEW_H
