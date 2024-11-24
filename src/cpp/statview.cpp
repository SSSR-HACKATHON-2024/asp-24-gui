#include "src/h/statview.h"


CstatView::CstatView(QWidget *parent) : CFrame(parent){
    mainBox = new QVBoxLayout();
    statHBox = new QHBoxLayout();
    leftInfoBox = new QVBoxLayout();
    rightInfoBox = new QVBoxLayout();
    topCveBox = new QVBoxLayout();
    gbTopCve = new CGroupBox("Топ-3 уязвимости");
    formCveCount = new QFormLayout();
    formStatDevices = new QFormLayout();
    formStatDangerous = new QFormLayout();
    lbCveCount = new CLabel("Количество баз CVE: ");
    lbDevices = new CLabel("Устройств просканировано: ");
    lbDangerous = new CLabel("Уязвимых устройств: ");
    leCveCount = new CLabel("123");
    leDevices = new CLabel("13732");
    leDangerous = new CLabel("72");
    histogram = new ChistogramView();
    //histogram->set_data(17,100,27,31);
    tableCve = new CTableWidget();
   // left box
    leftInfoBox->addWidget(histogram);
   // right box
    tableCve->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableCve->set_headers({"CVE","Описание","Критичность"});
    topCveBox->addWidget(tableCve);
    gbTopCve->setLayout(topCveBox);
    formCveCount->addRow(lbCveCount,leCveCount);
    formStatDevices->addRow(lbDevices,leDevices);
    formStatDangerous->addRow(lbDangerous,leDangerous);
    rightInfoBox->addLayout(formCveCount);
    rightInfoBox->addLayout(formStatDevices);
    rightInfoBox->addLayout(formStatDangerous);
    rightInfoBox->addWidget(gbTopCve);
   // main
    //statHBox->addWidget(histogram);
    //statHBox->addStretch();
    //mainBox->addLayout(statHBox);
    //mainBox->addStretch();
    mainBox->addLayout(rightInfoBox);
    //mainBox->addLayout(leftInfoBox);
    //mainBox->addStretch();
    setLayout(mainBox);
    read_right_part();
   // other
    timer = new QTimer();
    connect(timer,&QTimer::timeout,this,&CstatView::on_timer_alarm);
    timer->start(60000 * 5);
   // connects
    connect(tableCve,&CTableWidget::doubleClicked,this,&CstatView::on_tableCveDoubleClicked);
}

CstatView::~CstatView(){
    delete histogram;
}

void CstatView::read_right_part(){
    if (!db.open()){
        DBExceptionHandler(db.lastError().text());
        return;
    }
    QSqlQuery queryAllCve;
    QString queryAllCveStr = "SELECT COUNT(*) FROM cve_table;";
    if (!queryAllCve.exec(queryAllCveStr)){
        DBExceptionHandler(queryAllCve.lastError().text());
        db.close();
        return;
    }
    qlonglong allCveCnt = 0;
    QSqlRecord queryAllCveRec = queryAllCve.record();
    while(queryAllCve.next()){
        allCveCnt = queryAllCve.value(queryAllCveRec.indexOf("count")).toLongLong();
    }
    leCveCount->setText(QVariant(allCveCnt).toString());
    QSqlQuery queryDeviceScanned;
    QString queryDevicesScannedStr = "SELECT COUNT(*) FROM analytics WHERE scan_id = (SELECT scan_id FROM analytics ORDER BY datetime DESC LIMIT 1);";
    if (!queryDeviceScanned.exec(queryDevicesScannedStr)){
        DBExceptionHandler(queryDeviceScanned.lastError().text());
        db.close();
        return;
    }
    qlonglong devicesScannedCnt = 0;
    QSqlRecord queryDeviceScannedRec = queryDeviceScanned.record();
    while(queryDeviceScanned.next()){
        devicesScannedCnt = queryDeviceScanned.value(queryDeviceScannedRec.indexOf("count")).toLongLong();
    }
    leDevices->setText(QVariant(devicesScannedCnt).toString());
    QSqlQuery queryDevicesDangerous;
    QString queryDevicesDangeroursStr = "SELECT COUNT(*) FROM analytics WHERE scan_id = (SELECT scan_id FROM analytics ORDER BY datetime DESC LIMIT 1) AND cve_info != 'NULL';";
    if (!queryDevicesDangerous.exec(queryDevicesDangeroursStr)){
        DBExceptionHandler(queryDevicesDangerous.lastError().text());
        db.close();
        return;
    }
    QSqlRecord queryDevicesDangerousRec = queryDevicesDangerous.record();
    qlonglong devicesDangerousCnt = 0;
    while(queryDevicesDangerous.next()){
        devicesDangerousCnt = queryDevicesDangerous.value(queryDevicesDangerousRec.indexOf("count")).toInt();
    }
    leDangerous->setText(QVariant(devicesDangerousCnt).toString());
    QSqlQuery queryTopCve;
    QString queryTopCveStr = "SELECT id,cve_id,description,cvss FROM cve_table WHERE cve_table.cve_id IN (SELECT analytics.cve_info from analytics) ORDER BY cvss DESC LIMIT 3;";
    if (!queryTopCve.exec(queryTopCveStr)){
        DBExceptionHandler(queryTopCve.lastError().text());
        db.close();
        return;
    }
    tableCve->clear();
    tableCve->setRowCount(0);
    tableCve->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableCve->set_headers({"CVE","Описание","Критичность"});
    QSqlRecord queryTopCveRec = queryTopCve.record();
    while(queryTopCve.next()){
        QString cveName = queryTopCve.value(queryTopCveRec.indexOf("cve_id")).toString();
        QString cveDescription = queryTopCve.value(queryTopCveRec.indexOf("description")).toString();
        double cveCvss = queryTopCve.value(queryTopCveRec.indexOf("cvss")).toDouble();
        tableCve->insert_row({cveName,cveDescription,QVariant(cveCvss).toString()});
    }
    db.close();
}

void CstatView::read_left_part(){
    if (!db.open()){
        DBExceptionHandler(db.lastError().text());
        return;
    }
    QSqlQuery query;
}

void CstatView::on_tableCveDoubleClicked(QModelIndex index){
    if (!index.isValid()) return;
    QString description = tableCve->model()->index(index.row(),1).data().toString();
    QMessageBox::information(this,"Описание",description);
}

void CstatView::on_timer_alarm(){
    read_right_part();
}
