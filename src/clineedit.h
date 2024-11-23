#ifndef CLINEEDIT_H
#define CLINEEDIT_H

#include <QObject>
#include <QLineEdit>

class CLineEdit : public QLineEdit{
    Q_OBJECT

public:
    CLineEdit(QWidget *parent = 0);
    CLineEdit(const QString &text,QWidget *parent = 0);

private:
    void set_style();

};

#endif // CLINEEDIT_H
