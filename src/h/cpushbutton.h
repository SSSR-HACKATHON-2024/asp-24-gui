#ifndef CPUSHBUTTON_H
#define CPUSHBUTTON_H

#include <QObject>
#include <QPushButton>

class CPushButton : public QPushButton{

public:
    CPushButton(QWidget *parent = 0);
    CPushButton(const QString &text,QWidget *parent = 0);

private:
    void set_style();
};

#endif // CPUSHBUTTON_H
