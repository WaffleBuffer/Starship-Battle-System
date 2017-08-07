#ifndef SHIP_H
#define SHIP_H

/**
 * @file ship.h
 */

#include "abstractship.h"

class NavThruster;
class PlayerShipControl;
class IoController;

/**
 * @brief The Ship class. The concrete class. For now AbstractShip has nothing virtual except XML handling.
 */
class PlayerControlledShip: public AbstractShip
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
    PlayerControlledShip(const std::string & name, const std::string & description, Hull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster, NavThruster *backThruster,
         TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster, TranslationThruster *backTThruster,
         RotationThruster *rotationThruster, const int &baseAngle, IoController *ioController);

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
    static PlayerControlledShip*loadFromXML(const pugi::xml_node &root);

    /**
     * @brief getRootName Get the Ship XML root name.
     * @return The Ship XML root name.
     */
    static const char *getRootName();

    /**
     * @brief getControl Get the ship's control.
     * @return The ship's control.
     */
    virtual ShipControl *getControl() override;
private:

    /**
     * @brief rootName The name of the XML root for an Ship
     */
    static const char* rootName;

    /**
     * @brief control The ship's control.
     */
    PlayerShipControl *control;
    /**
     * @brief PlayerControlledShip Default constructor used in load from XML.
     */
    PlayerControlledShip();
};

#endif // SHIP_H
