#include "ship.h"

#include "../utils/vectorialmovement.h"
#include "../exception/xmlexception.h"
#include <string.h>

const char* Ship::rootName = "ship";

Ship::Ship(const std::string &name, const std::string &description, Hull *hull, Armor *armor, Sensor *sensor, NavThruster *forwardThruster,
           NavThruster *backThruster, TranslationThruster *leftTThruster, TranslationThruster *frontTThruster, TranslationThruster *rightTThruster,
           TranslationThruster *backTThruster, RotationThruster *clockWiseThruster, const int &baseAngle)
    :AbstractShip(name, description, hull, armor, sensor, forwardThruster, backThruster,
                  leftTThruster, frontTThruster, rightTThruster, backTThruster,
                  clockWiseThruster, new VectorialMovement(this, baseAngle)){

}

Ship::Ship(){

}

void Ship::saveXML(pugi::xml_node &root)
{
    pugi::xml_node thisRoot = root.append_child(Ship::getRootName());
    AbstractShip::saveAbstractXML(thisRoot, this);
}

Ship *Ship::loadFromXML(const pugi::xml_node &root)
{
    if(strcmp(root.name(), Ship::getRootName()) != 0)
        throw XMLException("Wrong node to load for Ship : " + std::string(root.name()));

    Ship *ship = new Ship();
    AbstractShip::loadAbstractFromXML(root, ship);
    return ship;
}

const char *Ship::getRootName()
{
    return Ship::rootName;
}
