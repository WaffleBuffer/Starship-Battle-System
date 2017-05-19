#ifndef SHIP_H
#define SHIP_H

#include "abstractship.h"

class NavThruster;

class Ship: public AbstractShip
{
public:
    Ship(const std::string & name, const std::string & description, AbstractHull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster, NavThruster *backThruster,
         TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster, TranslationThruster *backTThruster,
         RotationThruster *rotationThruster, const int &baseAngle);

private:
};

#endif // SHIP_H
