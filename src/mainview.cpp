#include "mainview.h"

CmainView::CmainView(QWidget *parent) : CFrame(parent){
    mainBox = new QVBoxLayout();
    formIp = new QFormLayout();
    gbTest = new CGroupBox("Наличие уязвимостей");
    tabs = new CTabWidget();
    tasks = new CtasksView();
   // ip
    mainBox->addLayout(formIp);
    mainBox->addWidget(tabs);
    tabs->addTab(gbTest,QIcon(":/icons/programIcons/icons8-system-task-96.ico"),"Статистика");
    tabs->addTab(tasks,"Задачи");
    setLayout(mainBox);
    resize(600,600);
    setWindowTitle("АСП-24");
    setFixedSize(1200,800);
    setWindowIcon(QIcon(":/icons/programIcons/icons8-vulnerability-96.ico"));
   // connets
}

CmainView::~CmainView(){
    delete tasks;
}
