#include "src/h/statview.h"


CstatView::CstatView(QWidget *parent) : CFrame(parent){
    mainBox = new QVBoxLayout();
    statHBox = new QHBoxLayout();
    formStatDevices = new QFormLayout();
    formStatDangerous = new QFormLayout();
    lbDevices = new QLabel("Устройств просканировано: ");
    lbDevices->setStyleSheet("color: #4B0082; font: bold;");
    lbDangerous = new QLabel("Уязвимых устройств: ");
    lbDangerous->setStyleSheet("color: #4B0082; font: bold;");
    leDevices = new CLabel("13732");
    leDangerous = new CLabel("72");
    histogram = new ChistogramView();
    histogram->set_data(17,100,27,31);
    formStatDevices->addRow(lbDevices,leDevices);
    formStatDangerous->addRow(lbDangerous,leDangerous);
    statHBox->addLayout(formStatDevices);
    statHBox->addLayout(formStatDangerous);
    mainBox->addLayout(statHBox);
    mainBox->addWidget(histogram);
    setLayout(mainBox);
}

CstatView::~CstatView(){
    delete histogram;
}
