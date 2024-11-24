#ifndef HISTOGRAMVIEW_H
#define HISTOGRAMVIEW_H

#include <QtWidgets>

class ChistogramView : public QWidget {
    Q_OBJECT

public:
    ChistogramView(QWidget *parent = 0);
    void set_data(int criticalCount,int highCount,
                  int mediumCount,int lowCount);

private:
    QVector <int> data;
    QVector <QString> labels;
    QVector <QColor> colors;

protected:
    void paintEvent(QPaintEvent *event) override;

};

#endif // HISTOGRAMVIEW_H
