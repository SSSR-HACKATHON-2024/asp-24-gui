#include "src/h/cpushbutton.h"

CPushButton::CPushButton(QWidget *parent){
    set_style();
    setParent(parent);
}

CPushButton::CPushButton(const QString &text, QWidget *parent){
    set_style();
    setText(text);
    setParent(parent);
}

void CPushButton::set_style(){
    setStyleSheet("QPushButton {"
                  "background-color: #4169e1;"
                  "color: white;"
                  "border: 2px solid #ffffff;"
                  "border-radius: 10px;"
                  "padding: 10px 20px;"
                  "font-size: 16px;"
                  "font-weight: bold;"
                  "text-align: center;"
                  "min-width: 120px;}"
                  "QPushButton:hover{"
                  "background-color: #00008b;"
                  "border: 2px solid #00008b}"
                  "QPushButton:pressed{"
                  "background-color: #191970;"
                  "border: 2px solid #191970;}");
}
