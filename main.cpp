#include "mainwindow.h"
#include <QApplication>

#include "src/diceExpression/diceexpression.h"

#include <string>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
    srand (time(NULL));

    // Testing dice expression
    string simpleConst = "D10 + D6";
    DiceExpression expr(simpleConst);

    cout << expr.roll() << endl;
    cout << expr.getMaxValue() << endl;

    return 0;

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
}
