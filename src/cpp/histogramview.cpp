#include "src/h/histogramview.h"

ChistogramView::ChistogramView(QWidget *parent) : CFrame(parent) {
    data = {2,2,2,2};
    colors = {
        QColor("#B22222"), QColor("#FF4500"),QColor("#FFD700"),QColor("#7CFC00")
    };
    labels = {"Critical","High","Medium","Low"};
}

void ChistogramView::set_data(int criticalCount,int highCount,
                              int mediumCount,int lowCount){
    data.clear();
    data = {criticalCount,highCount,mediumCount,lowCount};
}

void ChistogramView::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    pen.setColor(Qt::black);
    painter.setPen(pen);
    int width = this->width();
    int height = this->height();
    int barWidth = width / (data.size() * 2);
    int maxDataValue = *std::max_element(data.begin(), data.end());
    for (int i = 0; i < data.size(); ++i) {
        int barHeight = (data[i] * height) / maxDataValue;
        painter.setBrush(QBrush(colors[i]));
        painter.drawRect(i * barWidth * 2 + 20, height - barHeight - 30, barWidth, barHeight);
        painter.setPen(Qt::black);
        QFont font = painter.font();
        font.setPointSize(10);
        painter.setFont(font);
        painter.drawText(i * barWidth * 2 + 40, height - 10, labels[i] + " - " + QVariant(data[i]).toString());
    }
    painter.setPen(QPen(Qt::black, 2));
    painter.drawLine(0, height - 30, width, height - 30);
    painter.drawLine(0, 0, 0, height - 30);
    event->accept();
}
