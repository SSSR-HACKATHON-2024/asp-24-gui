#include "src/h/cdatetimeedit.h"

CDateTimeEdit::CDateTimeEdit(QWidget *parent){
    set_style();
    setParent(parent);
}

void CDateTimeEdit::set_style(){
    setStyleSheet("QDateTimeEdit{"
                  "background-color: #f5f5f5;"
                  "border: 1px solid #cccccc;"
                  "border-radius: 4px;"
                  "padding: 5px;"
                  "font-family: Arial, sans-serif;"
                  "font-size: 14px;"
                  "color: #333333;}"
                  "QDateTimeEdit:focus{"
                  "border-color: #4d90fe;}");
}
