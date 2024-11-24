#ifndef CFRAME_H
#define CFRAME_H

#include <QObject>
#include <QFrame>

class CFrame : public QFrame{

public:
    CFrame(QWidget *parent = 0);

private:
    void set_style();

};

#endif // CFRAME_H
