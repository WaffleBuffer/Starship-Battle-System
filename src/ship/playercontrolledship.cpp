#include "playercontrolledship.h"
#include "../utils/vectorialmovement.h"
#include "../exception/xmlexception.h"
#include "shipControl/playershipcontrol.h"
#include "../ioControler/iocontroller.h"
#include <string.h>

const char* PlayerControlledShip::rootName = "ship";

PlayerControlledShip::PlayerControlledShip(const std::string &name, const std::string &description, Hull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster,
           NavThruster *backThruster, TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster,
           TranslationThruster *backTThruster, RotationThruster *clockWiseThruster, const int &baseAngle, IoController *ioController)
    :AbstractShip(name, description, hull, armor, sensor, forwardThruster, backThruster,
                  leftTThruster, frontTThruster, rightTThruster, backTThruster,
                  clockWiseThruster, new VectorialMovement(this, baseAngle)){

    this->control = new PlayerShipControl(this, ioController);
}

void PlayerControlledShip::saveXML(pugi::xml_node &root)
{
    pugi::xml_node thisRoot = root.append_child(PlayerControlledShip::getRootName());
    AbstractShip::saveAbstractXML(thisRoot, this);
}

PlayerControlledShip::PlayerControlledShip()
{

}

PlayerControlledShip *PlayerControlledShip::loadFromXML(const pugi::xml_node &root)
{
    if(strcmp(root.name(), PlayerControlledShip::getRootName()) != 0)
        throw XMLException("Wrong node to load for Ship : " + std::string(root.name()));

    PlayerControlledShip *ship = new PlayerControlledShip();
    AbstractShip::loadAbstractFromXML(root, ship);
    return ship;
}

const char *PlayerControlledShip::getRootName()
{
    return PlayerControlledShip::rootName;
}

ShipControl *PlayerControlledShip::getControl()
{
    return this->control;
}

