#ifndef MYTABLEWIDGET_H
#define MYTABLEWIDGET_H

#include <QObject>
#include <QTableWidget>

class CTableWidget : public QTableWidget{
    Q_OBJECT

public:
    CTableWidget(QWidget *parent = 0);
    void set_headers(const QStringList &headers);
    void insert_row(const QStringList &data);

private:
    void set_style();

};

#endif // MYTABLEWIDGET_H
