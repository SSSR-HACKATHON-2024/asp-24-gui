#include <QApplication>
#include "mainview.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    CmainView window;
    window.show();
    return a.exec();
}
