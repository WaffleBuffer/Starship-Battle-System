#include "ship.h"

Ship::Ship(const std::string &name, const std::string &description, AbstractHull *hull, Sensor *sensor, NavThruster *forwardThruster, NavThruster *backThruster,
           TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster, TranslationThruster *backTThruster, RotationThruster *clockWiseThruster,
           RotationThruster *counterClockWiseThruster)
    :AbstractShip(name, description, hull, sensor, forwardThruster, backThruster,
                  leftTThruster, frontTThruster, rightTThruster, backTThruster,
                  clockWiseThruster, counterClockWiseThruster){

}
