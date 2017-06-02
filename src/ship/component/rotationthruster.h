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

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    void saveXML(pugi::xml_node &root) override;

    /**
     * @brief loadFromXML Create a RotationThruster from an XML node
     * @param root The xml node that should contain the RotationThruster informations.
     * @param ship The ship that will use this RotationThruster.
     * @return The created RotationThruster.
     */
    static RotationThruster*loadFromXML(IShip *ship, const pugi::xml_node &root);

    /**
     * @brief getRootName Get the RotationThruster XML root name.
     * @return The RotationThruster XML root name.
     */
    static const char *getRootName();

    /**
     * @brief toString Get the string representation.
     * @return The string representation.
     */
    std::string toString() override;

private:
    /**
     * @brief direction The angle offset for the next rotation. Use positive value to rotate to the right and negative to rotate to the left.
     */
    int direction;

    /**
     * @brief rootName The name of the XML root for a RotationThruster
     */
    static const char* rootName;
};

#endif // ROTATIONTHRUSTER_H
