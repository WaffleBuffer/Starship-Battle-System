#ifndef ROTATIONTHRUSTER_H
#define ROTATIONTHRUSTER_H

/**
 * @file rotationthruster.h
 */

#include "energyprovidable.h"
#include "../../utils/constants.cpp"

class IShip;

/**
 * @brief The RotationThruster class. A thruster used to rotate the ship.
 */
class RotationThruster: public EnergyProvidable
{
public:
    /**
     * @brief RotationThruster The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     * @param maxEnergy The maximum amount of energy that can be provided.
     */
    RotationThruster(const std::string & name, const std::string &description, IShip *ship, const int & maxEnergy);
    /**
     * @brief RotationThruster The copy constructor.
     * @param model The model to copy.
     */
    RotationThruster(RotationThruster *model);

    /**
     * @brief provideEnergy Provide energy and rotate the ship.
     * @param energy The amount of energy provided.
     */
    void provideEnergy(const int & energy) override;
    /**
     * @brief getDirection Get the current angle offset of rotation.
     * @return The current angle offset of rotation.
     */
    int getDirection();
    /**
     * @brief setDirection Set the angle offset for the next rotation. Use positive value to rotate to the right and negative to rotate to the left.
     * @param direction The angle to set.
     */
    void setDirection(const int &direction);
private:
    /**
     * @brief direction The angle offset for the next rotation. Use positive value to rotate to the right and negative to rotate to the left.
     */
    int direction;
};

#endif // ROTATIONTHRUSTER_H
