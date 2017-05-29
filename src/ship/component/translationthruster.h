#ifndef TRANSLATIONTHRUSTER_H
#define TRANSLATIONTHRUSTER_H

/**
 * @file translationthruster.h
 */

#include "energyprovidable.h"
#include "../../utils/constants.cpp"

class IShip;

/**
 * @brief The TranslationThruster class. Some thruster capable of translating ship without modifying its inertia.
 */
class TranslationThruster: public EnergyProvidable {
public:
    /**
     * @brief TranslationThruster The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     * @param maxEnergy The maximum amount of energy that can be provided.
     */
    TranslationThruster(const std::string & name, const std::string & description, IShip *ship, const int & maxEnergy);
    /**
     * @brief TranslationThruster The copy cnstructor.
     * @param model The model to copy.
     */
    TranslationThruster(TranslationThruster *model);

    /**
     * @brief provideEnergy Provide some energy to start translation.
     * @param energy The energy to provide.
     */
    void provideEnergy(const int & energy) override;
    /**
     * @brief getFacingDirection Get the facing ship direction of this thruster (so the invert of the thrust direction).
     * @return The facing ship direction (so the invert of the thrust direction).
     */
    constants::ShipDirection getFacingDirection();
    /**
     * @brief setFacingDirection Set the facing ship direction of this thruster (so the invert of the thrust direction).
     * @param facingDirection The facing ship direction to set.
     */
    void setFacingDirection(constants::ShipDirection facingDirection);
private:
    /**
     * @brief facingDirection The the facing ship direction of this thruster (so the invert of the thrust direction).
     */
    constants::ShipDirection facingDirection;
};

#endif // TRANSLATIONTHRUSTER_H
