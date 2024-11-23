#ifndef CLABEL_H
#define CLABEL_H

#include <QObject>
#include <QLabel>

class CLabel : public QLabel{

public:
    CLabel(QWidget *parent = 0);
    CLabel(const QString &text,QWidget *parent = 0);

private:
    void set_style();

};

#endif // CLABEL_H
