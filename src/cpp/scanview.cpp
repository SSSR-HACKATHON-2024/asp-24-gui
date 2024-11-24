#include "src/h/scanview.h"

CscanView::CscanView(QWidget *parent) : CFrame(parent){
    mainBox = new QVBoxLayout();
    wayBox = new QVBoxLayout();
    fullBox = new QVBoxLayout();
    tableHistoryBox = new QVBoxLayout();
    tableActualBox = new QVBoxLayout();
    ipHBox = new QHBoxLayout();
    radioHBox = new QHBoxLayout();
    tablesHBox = new QHBoxLayout();
    gbWay = new CGroupBox("Способ сканирования");
    gbFull = new CGroupBox("Содержательность сканирования");
    gbTableHistory = new CGroupBox("Прошлое сканирование");
    gbTableActual = new CGroupBox("Актуальное сканирование");
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
    tableHistory = new CTableWidget();
    tableActual = new CTableWidget();
    radioFullFast->setChecked(true);
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
   // tables
    tableHistoryBox->addWidget(tableHistory);
    tableActualBox->addWidget(tableActual);
    gbTableHistory->setLayout(tableHistoryBox);
    gbTableActual->setLayout(tableActualBox);
    tablesHBox->addWidget(gbTableHistory);
    //tablesHBox->addStretch();
    tablesHBox->addWidget(gbTableActual);
   // main
    mainBox->addLayout(formIp);
    mainBox->addWidget(lbExample);
    mainBox->addLayout(radioHBox);
    mainBox->addLayout(ipHBox);
    mainBox->addLayout(tablesHBox);
    setLayout(mainBox);
   // connects
    connect(pbScan,&QPushButton::clicked,this,&CscanView::on_pbScan_clicked);
    connect(pbOpenFile,&QPushButton::clicked,this,&CscanView::on_pbOpenFile_clicked);
}

bool CscanView::valid_ip(const QString &ip){
    QHostAddress address(ip);
    return address.protocol() == QAbstractSocket::IPv4Protocol;
}

void CscanView::on_pbScan_clicked(){
    bool agressive = radioWayAgressive->isChecked();
    bool full = radioFullFull->isChecked();
    QString fullData = leIp->text();
    QStringList dataPart = fullData.split(',');
    if (agressive){
        if (full){

        }
        else{
            QProcess *newProcess = new QProcess();
            QString programPath = "/opt/asp-24/asp24s.py";
            newProcess->start(programPath,QStringList() << "-a -q 192.168.70.107");
        }
    }
    else{
        if (full){

        }
        else{

        }
    }
}

void CscanView::on_pbOpenFile_clicked(){
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
