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

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    void saveXML(pugi::xml_node &root) override;

    /**
     * @brief loadFromXML Create a NavThruster from an XML node
     * @param root The xml node that should contain the NavThruster informations.
     * @param ship The ship that will use this NavThruster.
     * @return The created NavThruster.
     */
    static NavThruster*loadFromXML(IShip *ship, const pugi::xml_node &root);

    /**
     * @brief getRootName Get the NavThruster XML root name.
     * @return The NavThruster XML root name.
     */
    static const char *getRootName();

    /**
     * @brief toString Get the string representation.
     * @return The string representation.
     */
    std::string toString() override;

private:
    /**
     * @brief facingDirection The facing direction of this thruster (so the opposite of the moving direction).
     */
    constants::ShipDirection facingDirection;

    /**
     * @brief rootName The name of the XML root for a NavThruster
     */
    static const char* rootName;
};

#endif // NAVTHRUSTER_H
