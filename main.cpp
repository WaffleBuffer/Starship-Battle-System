#include "mainwindow.h"
#include <QApplication>

#include "src/diceExpression/diceexpression.h"
#include "src/ship/ship.h"
#include "src/ship/basichull.h"
#include "src/ship/component/stagegenerator.h"
#include "src/ship/component/stopedgeneratorstage.h"
#include "src/ship/component/sensor.h"

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

    IShip *ship;

    Thruster *thrusterMK1 = new Thruster("thruster MK1", "first sublight speed space thruster", nullptr, 3);

    cout << "Building ship..." << endl;

    cout << "Building hull..." << endl;
    AbstractHull *hull = new BasicHull(40);

    cout << "Building thrusters..." << endl;
    Thruster *fThruster = new Thruster(thrusterMK1);
    fThruster->setShip(ship);
    Thruster *bThruster = new Thruster(thrusterMK1);
    bThruster->setShip(ship);
    Thruster *fTThruster = new Thruster(thrusterMK1);
    fTThruster->setShip(ship);
    Thruster *rTThruster = new Thruster(thrusterMK1);
    rTThruster->setShip(ship);
    Thruster *bTThruster = new Thruster(thrusterMK1);
    bTThruster->setShip(ship);
    Thruster *lTThruster = new Thruster(thrusterMK1);
    lTThruster->setShip(ship);
    Thruster *cTThruster = new Thruster(thrusterMK1);
    cTThruster->setShip(ship);
    Thruster *cCTThruster = new Thruster(thrusterMK1);
    cCTThruster->setShip(ship);


    cout << "Building sensors..." << endl;
    Sensor *sensor = new Sensor("Sensor Mk1", "Simple array of sensors", ship, 5);


    ship = new Ship("UES Test", "First Union of Earth prototype of Starship", hull, sensor, fThruster, bThruster, lTThruster, fTThruster, rTThruster, bTThruster,
                    cTThruster, cCTThruster);

    cout << "Building energy generator..." << endl;
    StageGenerator *generator = new StageGenerator("Stage Generator MK1", "First generation of stage generators", ship);
    generator->addStage(new GeneratorStage(constants::NORMAL, new DiceExpression("D10"), generator));
    generator->addStage(new StoppedGeneratorStage(generator, new DiceExpression("D6 + 2"), 4));
    ship->addGenerator(generator);

    cout << "powering ship..." << endl;
    ship->generateEnergy();

    string shipString = ship->toString();
    cout << "ship : " << endl << shipString << endl;

    return 0;

    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/
}
