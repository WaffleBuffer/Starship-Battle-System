#include "ship.h"

Ship::Ship(const std::string &name, const std::string &description, AbstractHull *hull, Sensor *sensor, Thruster *forwardThruster, Thruster *backThruster, Thruster *leftTThruster, Thruster *frontTThruster, Thruster *rightTThruster, Thruster *backTThruster, Thruster *clockWiseThruster, Thruster *counterClockWiseThruster)
    :AbstractShip(name, description, hull, sensor, forwardThruster, backThruster,
                  leftTThruster, frontTThruster, rightTThruster, backTThruster,
                  clockWiseThruster, counterClockWiseThruster){

}
