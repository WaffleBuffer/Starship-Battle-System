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

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    void saveXML(pugi::xml_node &root) override;

    /**
     * @brief loadFromXML Create a TranslationThruster from an XML node
     * @param root The xml node that should contain the TranslationThruster informations.
     * @param ship The ship that will use this TranslationThruster.
     * @return The created TranslationThruster.
     */
     static TranslationThruster*loadFromXML(IShip *ship, const pugi::xml_node &root);

    /**
     * @brief getRootName Get the TranslationThruster XML root name.
     * @return The TranslationThruster XML root name.
     */
    static const char *getRootName();

    /**
     * @brief toString Get the string representation.
     * @return The string representation.
     */
    std::string toString() override;
private:
    /**
     * @brief facingDirection The the facing ship direction of this thruster (so the invert of the thrust direction).
     */
    constants::ShipDirection facingDirection;

    /**
     * @brief rootName The name of the XML root for a TranslationThruster
     */
    static const char* rootName;
};

#endif // TRANSLATIONTHRUSTER_H
