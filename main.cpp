#include "JCDemoCalc.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    JCDemoCalc w;
    w.show();

    return a.exec();
}
