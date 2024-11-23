#ifndef CTABWIDGET_H
#define CTABWIDGET_H

#include <QObject>
#include <QTabWidget>

class CTabWidget : public QTabWidget{

public:
    CTabWidget(QWidget *parent = 0);

private:
    void set_style();

};

#endif // CTABWIDGET_H
