#ifndef SHIP_H
#define SHIP_H

/**
 * @file ship.h
 */

#include "abstractship.h"

class NavThruster;

/**
 * @brief The Ship class. The concrete class. For now AbstractShip has nothing virtual except XML handling.
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

    /**
     * @brief Ship Default constructor. Be carefull while using this as nothing is initialized.
     */
    Ship();

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    void saveXML(pugi::xml_node &root) override;

    /**
     * @brief loadFromXML Create a Ship from an XML node
     * @param root The xml node that should contain the Ship informations.
     * @return The created AbstractShip.
     */
    static Ship*loadFromXML(const pugi::xml_node &root);

    /**
     * @brief getRootName Get the Ship XML root name.
     * @return The Ship XML root name.
     */
    static const char *getRootName();

private:

    /**
     * @brief rootName The name of the XML root for an Ship
     */
    static const char* rootName;
};

#endif // SHIP_H
