#include "src/h/ctablewidget.h"

CTableWidget::CTableWidget(QWidget *parent) : QTableWidget(parent){
    set_style();
}

void CTableWidget::set_headers(const QStringList &headers){
    setColumnCount(headers.size());
    setHorizontalHeaderLabels(headers);
}

void CTableWidget::insert_row(const QStringList &data){
    int row = rowCount();
    insertRow(row);
    int column = 0;
    for (auto& value : data){
        setItem(row,column++,new QTableWidgetItem(value));
    }
}

void CTableWidget::set_style(){
    setStyleSheet("QHeaderView::section{"
                             "background-color: QLinearGradient(x1: 1,y1: 0,x2: 0,y2: 1, stop: 0 #FFDEAD,stop: 0.4999 #FFF8DC,stop: 0.5 #FFE4C4,stop: 1 #FFEBCD);"
                             "color: black;}");
    QFont font("Segoe UI",14);
    setFont(font);
}
