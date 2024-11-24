#include "src/h/clabel.h"

CLabel::CLabel(QWidget *parent){
    set_style();
    setParent(parent);
}

CLabel::CLabel(const QString &text, QWidget *parent){
    set_style();
    setText(text);
    setParent(parent);
}

void CLabel::set_style(){
    setStyleSheet("color: #444;"
                  "font-size: 16px;"
                  "font: bold;");
}
