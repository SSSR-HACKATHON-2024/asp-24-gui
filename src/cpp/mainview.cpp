#include "src/h/mainview.h"

CmainView::CmainView(QWidget *parent) : CFrame(parent){
//    if (!db.open()){
//        qDebug() << db.lastError().text();
//    }
    mainBox = new QVBoxLayout();
    statBox = new QVBoxLayout();
    formIp = new QFormLayout();
    gbStat = new CGroupBox("Наличие уязвимостей");
    tabs = new CTabWidget();
    stat = new CstatView();
    scan = new CscanView();
   // stat
    statBox->addWidget(stat);
    gbStat->setLayout(statBox);
    tabs->addTab(gbStat,QIcon(":/icons/programIcons/icons8-system-task-96.ico"),"Статистика");
   // scan
    tabs->addTab(scan,QIcon(":/icons/programIcons/free-icon-eye-scanner-2027594.ico"),"Сканирование");
   // main
    mainBox->addLayout(formIp);
    mainBox->addWidget(tabs);
    setLayout(mainBox);
    resize(600,600);
    setWindowTitle("АСП-24");
    setFixedSize(1300,800);
    setWindowIcon(QIcon(":/icons/programIcons/icons8-vulnerability-96.ico"));
   // connets
}

CmainView::~CmainView(){
    if (db.isOpen()) db.close();
    delete scan;
    delete stat;
}
