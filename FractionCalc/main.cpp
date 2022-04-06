#include "fractioncalc.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FractionCalc w;
    w.show();
    return a.exec();
}
