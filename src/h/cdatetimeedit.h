#ifndef CDATETIMEEDIT_H
#define CDATETIMEEDIT_H

#include <QObject>
#include <QDateEdit>

class CDateTimeEdit : public QDateTimeEdit{

public:
    CDateTimeEdit(QWidget *parent = 0);

private:
    void set_style();

};

#endif // CDATETIMEEDIT_H
