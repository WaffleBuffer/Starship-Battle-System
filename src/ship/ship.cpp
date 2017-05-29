#include "ship.h"

#include "../utils/vectorialmovement.h"

Ship::Ship(const std::string &name, const std::string &description, Hull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster,
           NavThruster *backThruster, TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster,
           TranslationThruster *backTThruster, RotationThruster *clockWiseThruster, const int &baseAngle)
    :AbstractShip(name, description, hull, armor, sensor, forwardThruster, backThruster,
                  leftTThruster, frontTThruster, rightTThruster, backTThruster,
                  clockWiseThruster, new VectorialMovement(this, baseAngle)){

}
