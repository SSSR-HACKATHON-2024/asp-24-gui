#include "clineedit.h"

CLineEdit::CLineEdit(QWidget *parent){
    set_style();
    setParent(parent);
}

CLineEdit::CLineEdit(const QString &text, QWidget *parent){
    set_style();
    setText(text);
    setParent(parent);
}

void CLineEdit::set_style(){
    setStyleSheet("QLineEdit{"
                  "background-color: white;"
                  "border: 2px solid #ccc;"
                  "border-radius: 4px;"
                  "padding: 8px;"
                  "font-size: 18px;"
                  "color: #333;}"
                 "QLineEdit:focus{"
                 "border: 2px solid #0078d4;}");
}
