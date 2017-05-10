#include "ship.h"

Ship::Ship(const std::string &name, const std::string &description, AbstractHull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster, NavThruster *backThruster,
           TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster, TranslationThruster *backTThruster, RotationThruster *clockWiseThruster,
           RotationThruster *counterClockWiseThruster)
    :AbstractShip(name, description, hull, armor, sensor, forwardThruster, backThruster,
                  leftTThruster, frontTThruster, rightTThruster, backTThruster,
                  clockWiseThruster, counterClockWiseThruster){

}
