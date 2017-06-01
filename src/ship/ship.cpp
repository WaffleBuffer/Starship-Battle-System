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

void Ship::saveXML(pugi::xml_node &root)
{
    pugi::xml_node thisRoot = root.append_child(Hull::getRootName());
}

const char *Ship::getRootName()
{
    return this->rootName;
}
