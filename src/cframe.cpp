#include "cframe.h"

CFrame::CFrame(QWidget *parent){
    set_style();
    setParent(parent);
}

void CFrame::set_style(){
    setStyleSheet("background-color: #f5f5f5;"
              "font-family: Segoe UI;"
              "font-size: 14px;"
              "color: #333;"
              "border-radius: 8px");
}
