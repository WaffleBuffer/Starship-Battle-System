#include "sensor.h"

#include "../../exception/xmlexception.h"
#include "../iship.h"
#include <string.h>

const char* Sensor::rootName = "sensor";

Sensor::Sensor(const std::string &name, const std::string &description, IShip *ship, const int &maxLevel)
    :AbstractComponent(name, description, ship), maxLevel(maxLevel){
    this->currentLevel = 0;
}

std::string Sensor::toString()
{
    std::string res = "sensor : ";
    res += std::to_string(this->currentLevel) + " / " + std::to_string(this->maxLevel);
    return res;
}

void Sensor::saveXML(pugi::xml_node &root)
{
    pugi::xml_node thisRoot = root.append_child(Sensor::getRootName());
    AbstractComponent::saveAbstractXML(thisRoot, this);
    thisRoot.append_attribute("currentLevel").set_value(this->currentLevel);
    thisRoot.append_attribute("maxLevel").set_value(this->maxLevel);
}

Sensor *Sensor::loadFromXML(IShip *ship, const pugi::xml_node &root)
{
    if(strcmp(root.name(), Sensor::getRootName()) != 0)
        throw XMLException("Wrong node to load for sensor : " + std::string(root.name()));

    int currentLevel = root.attribute("currentLevel").as_int();
    int maxLevel = root.attribute("maxLevel").as_int();

    Sensor *sensor = new Sensor("", "", ship, maxLevel);
    sensor->currentLevel = currentLevel;
    AbstractComponent::loadAbstractFromXML(ship, root, sensor);

    ship->addSensors(sensor, sensor->getShipPart());

    return sensor;
}

const char *Sensor::getRootName()
{
    return rootName;
}
