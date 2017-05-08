#ifndef SHIP_H
#define SHIP_H

#include "abstractship.h"

class Ship: public AbstractShip
{
public:
    Ship(const std::string & name, const std::string & description, AbstractHull *hull, Sensor *sensor, Thruster *forwardThruster, Thruster *backThruster,
         Thruster *leftTThruster, Thruster *frontTThruster, Thruster *rightTThruster, Thruster *backTThruster, Thruster *clockWiseThruster,
         Thruster *counterClockWiseThruster);

private:
};

#endif // SHIP_H
