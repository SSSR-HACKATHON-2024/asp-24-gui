#include "tasksview.h"

CtasksView::CtasksView(QWidget *parent) : CFrame(parent){
    mainBox = new QVBoxLayout();
    tableActualBox = new QVBoxLayout();
    tableCreatedBox = new QVBoxLayout();
    wayBox = new QVBoxLayout();
    fullBox = new QVBoxLayout();
    ipHBox = new QHBoxLayout();
    tasksBox = new QHBoxLayout();
    radioHBox = new QHBoxLayout();
    gbTableActual = new CGroupBox("Статус задач");
    gbTableCreated = new CGroupBox("Список задач");
    gbWay = new CGroupBox("Способ сканирования");
    gbFull = new CGroupBox("Содержательность сканирования");
    formIp = new QFormLayout();
    formRadioWay = new QFormLayout();
    formRadioFull = new QFormLayout();
    lbIp = new CLabel("Введите адрес/подсеть: ");
    lbExample = new CLabel("Пример ввода ip: a1.b1.c1.d1 (a1.b1.c1.d1/port), разрешено перечисление через запятую");
    lbWayAgressive = new CLabel("Агрессивное: ");
    lbWaySecretive = new CLabel("Секретное: ");
    lbFullFull = new CLabel("Полное: ");
    lbFullFast = new CLabel("Быстрое: ");
    leIp = new CLineEdit("");
    pbScan = new CPushButton("Начать сканирование");
    pbOpenFile = new CPushButton();
    pbOpenFile->setFixedWidth(10);
    pbOpenFile->setIcon(QIcon(":/icons/programIcons/download-file.ico"));
    pbOpenFile->setIconSize(QSize(30,18));
    radioWayAgressive = new QRadioButton();
    radioWayAgressive->setChecked(true);
    radioWaySecretive = new QRadioButton();
    radioFullFull = new QRadioButton();
    radioFullFast = new QRadioButton();
    radioFullFast->setChecked(true);
    tableActualTasks = new CTableWidget();
    tableCreatedTasks = new CTableWidget();
   // scan
    formIp->addRow(lbIp,leIp);
    formRadioWay->addRow(lbWayAgressive,radioWayAgressive);
    formRadioWay->addRow(lbWaySecretive,radioWaySecretive);
    formRadioFull->addRow(lbFullFull,radioFullFull);
    formRadioFull->addRow(lbFullFast,radioFullFast);
    wayBox->addLayout(formRadioWay);
    fullBox->addLayout(formRadioFull);
    gbWay->setLayout(wayBox);
    gbFull->setLayout(fullBox);
    radioHBox->addWidget(gbWay);
    radioHBox->addWidget(gbFull);
    ipHBox->setAlignment(Qt::AlignRight);
    ipHBox->addWidget(pbScan);
    ipHBox->addWidget(pbOpenFile);
   // tasks
    tableActualTasks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableCreatedTasks->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableActualTasks->set_headers({"Задача","Диапазон","Статус"});
    tableCreatedTasks->set_headers({"Задача","Диапазон","Время"});
    tableActualBox->addWidget(tableActualTasks);
    tableCreatedBox->addWidget(tableCreatedTasks);
    gbTableActual->setLayout(tableActualBox);
    gbTableCreated->setLayout(tableCreatedBox);
    tasksBox->addWidget(gbTableActual);
    tasksBox->addWidget(gbTableCreated);
   // main
    mainBox->addLayout(formIp);
    mainBox->addWidget(lbExample);
    mainBox->addLayout(radioHBox);
    mainBox->addLayout(ipHBox);
    mainBox->addLayout(tasksBox);
    setLayout(mainBox);
   // connects
    connect(pbScan,&QPushButton::clicked,this,&CtasksView::on_pbScan_clicked);
    connect(pbOpenFile,&QPushButton::clicked,this,&CtasksView::on_pbOpenFile_clicked);
}

bool CtasksView::valid_ip(const QString &ip){
    QHostAddress address(ip);
    return address.protocol() == QAbstractSocket::IPv4Protocol;
}

void CtasksView::on_pbScan_clicked(){
    bool agressive = radioWayAgressive->isChecked();
    bool full = radioFullFull->isChecked();
    QString fullData = leIp->text();
    QStringList dataPart = fullData.split(',');
    if (agressive){
        if (full){

        }
        else{

        }
    }
    else{
        if (full){

        }
        else{

        }
    }
}

void CtasksView::on_pbOpenFile_clicked(){
    QString filePath = QFileDialog::getOpenFileName();
    if (filePath.isEmpty()) return;
    QFile reader(filePath);
    if (!reader.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QStringList baseIps,cidrs;
    while(!reader.atEnd()){
        QString line = reader.readLine();
        if (!line.isEmpty() && line.back() == '\n') line.remove(line.size() - 1,1);
        if (line.contains("/")){
            QString address;
            for (auto& ch : line){
                if (ch == '/') break;
                address += ch;
            }
            if (valid_ip(address))
                cidrs.push_back(line);
        }
        else if (valid_ip(line)) baseIps.push_back(line);
    }
    reader.close();
}
