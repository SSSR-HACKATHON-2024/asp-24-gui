#include "cgroupbox.h"

CGroupBox::CGroupBox(QWidget *parent){
    set_style();
    setParent(parent);
}

CGroupBox::CGroupBox(const QString &title, QWidget *parent){
    set_style();
    setTitle(title);
    setParent(parent);
}

void CGroupBox::set_style(){
    setStyleSheet("QGroupBox{"
                  "border: 2px solid #4169e1;"
                  "border-radius: 10px;"
                  "padding: 15px;"
                  "margin-bottom: 20px;"
                  "background-color: #f5f5f5;"
                  "font: bold;"
                  "font-size: 16px;}"
                  "QGroupBox::title{"
                  "subcontrol-origin: margin;"
                  "subcontrol-position: top center;"
                  "padding: 5px;"
                  "background-color: #4169e1;"
                  "color: white;"
                  "font-size: 16px;"
                  "font-weight: bold;"
                  "border-radius: 5px;}");
}
