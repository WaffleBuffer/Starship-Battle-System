#include "mainwindow.h"
#include <QApplication>

#include "src/diceExpression/diceexpression.h"
#include "src/ship/ship.h"
#include "src/ship/basichull.h"

#include <string>
#include <iostream>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
    srand (time(NULL));

    // Testing dice expression
    string simpleConst = "2D3 + 1 + D6";
    DiceExpression expr(simpleConst);

    cout << expr.toString() << endl;
    cout << expr.roll() << endl;
    cout << expr.getMaxValue() << endl;

    // Testing ship

    AbstractHull *hull = new BasicHull();
    Thruster *thrusterMK1 = new Thruster("thruster MK1", "first sublight speed space thruster", nullptr, 3);

    IShip *ship = new Ship("UES Test", "First Union of earth prototype of ship", hull, new Thruster(thrusterMK1),
               new Thruster(thrusterMK1), new Thruster(thrusterMK1), new Thruster(thrusterMK1),
            new Thruster(thrusterMK1), new Thruster(thrusterMK1), new Thruster(thrusterMK1), new Thruster(thrusterMK1));

    string shipString = ship->toString();
    cout << shipString << endl;

    return 0;

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
}
