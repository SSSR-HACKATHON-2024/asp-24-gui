#include "ctabwidget.h"

CTabWidget::CTabWidget(QWidget *parent){
    setParent(parent);
    set_style();
}

void CTabWidget::set_style(){
    setStyleSheet("QTabWidget{"
                  "background-color: #f0f0f0;"
                  "border: 1px solid #d0d0d0;"
                  "border-radius: 8px;}"
                  "QTabWidget::pane{"
                  "border: none;"
                  "padding: 2px;}"
                  "QTabBar::tab{"
                  "background-color: #ffffff;"
                  "border: 1px solid #d0d0d0;"
                  "border-radius: 8px;"
                  "padding: 5px;"
                  "margin-right: 2px;"
                  "min-width: 85px;"
                  "text-align: right;"
                  "font-size: 14px;}"
                  "QTabBar::tab:hover{"
                  "background-color: #e1e1e1;}"
                  "QTabBar::tab:selected{"
                  "background-color: #8B008B;"
                  "color: white;"
                  "font-weight: bold;}"
                  "QTabBar::tab:selected:hover{"
                  "background-color: #f0f0f0;}"
                  "QTabWidget::tab-bar{"
                  "alignment: left;}");
}
