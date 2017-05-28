#ifndef NAVTHRUSTER_H
#define NAVTHRUSTER_H

/**
 * @file navthruster.h
 */

#include "energyprovidable.h"
#include "../../utils/constants.cpp"

class IShip;

/**
 * @brief The NavThruster class. The thruster used to add some inertia (and move).
 */
class NavThruster: public EnergyProvidable {
public:
    /**
     * @brief NavThruster The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     * @param maxEnergy The maximum amount of energy units that can be provided.
     */
    NavThruster(const std::string & name, const std::string & description, IShip *ship, const int & maxEnergy);
    /**
     * @brief NavThruster The copy constructor.
     * @param model The model to copy.
     */
    NavThruster(NavThruster *model);

    /**
     * @brief provideEnergy Provide some energy and activate the thruster.
     * @param energy
     */
    void provideEnergy(const int & energy) override;
    /**
     * @brief getFacingDirection Get the facing direction of this thruster (so the opposite of the moving direction).
     * @return The facing direction.
     */
    constants::ShipDirection getFacingDirection();
    /**
     * @brief setFacingDirection Set the facing direction of this thruster (so the opposite of the moving direction).
     * @param facingDirection The facing direction to set.
     */
    void setFacingDirection(constants::ShipDirection facingDirection);
private:
    /**
     * @brief facingDirection The facing direction of this thruster (so the opposite of the moving direction).
     */
    constants::ShipDirection facingDirection;
};

#endif // NAVTHRUSTER_H
