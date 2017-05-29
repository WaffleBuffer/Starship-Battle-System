#ifndef SHIP_H
#define SHIP_H

/**
 * @file ship.h
 */

#include "abstractship.h"

class NavThruster;

/**
 * @brief The Ship class. The concrete class. For now AbstractShip has nothing virtual.
 */
class Ship: public AbstractShip
{
public:
    /**
     * @brief Ship The constructor.
     * @param name The ship's name.
     * @param description The ship's description.
     * @param hull The ship's hull.
     * @param armor The ship's armor.
     * @param sensor The ship's basic sensors.
     * @param forwardThruster FT.
     * @param backThruster BT.
     * @param leftTThruster LTT.
     * @param frontTThruster FTT.
     * @param rightTThruster RTT.
     * @param backTThruster BTT.
     * @param rotationThruster RT.
     * @param movement The movement handler.
     */
    Ship(const std::string & name, const std::string & description, Hull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster, NavThruster *backThruster,
         TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster, TranslationThruster *backTThruster,
         RotationThruster *rotationThruster, const int &baseAngle);

private:
};

#endif // SHIP_H
