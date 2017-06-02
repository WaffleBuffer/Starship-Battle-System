#include "abstractcomponent.h"

#include "../../utils/utils.cpp"

AbstractComponent::AbstractComponent(const std::string & name, const std::string & description, IShip *ship) {
    this->name = name;
    this->description = description;
    this->ship = ship;
}

AbstractComponent::~AbstractComponent() {

}

std::string AbstractComponent::getName() {
    return this->name;
}

std::string AbstractComponent::getDescription() {
    return this->description;
}

IShip *AbstractComponent::getShip() {
    return this->ship;
}

void AbstractComponent::setShip(IShip *ship)
{
    this->ship = ship;
}

std::string AbstractComponent::toString()
{
    std::string res = this->getName() + " " + this->getDescription();
    return res;
}

void AbstractComponent::setPart(const constants::shipParts &value)
{
    part = value;
}

void AbstractComponent::saveAbstractXML(pugi::xml_node &root, AbstractComponent *componentToLoad)
{
    root.append_attribute("name").set_value(componentToLoad->getName().c_str());
    root.append_attribute("description").set_value(componentToLoad->getDescription().c_str());
    std::string str = utils::partToStr(componentToLoad->part);
    root.append_attribute("part").set_value(str.c_str());
}

void AbstractComponent::loadAbstractFromXML(IShip *ship, const pugi::xml_node &root, AbstractComponent *componentToLoad)
{
    componentToLoad->name = std::string(root.attribute("name").as_string());
    componentToLoad->description = std::string(root.attribute("description").as_string());
    std::string partStr(root.attribute("part").as_string());
    componentToLoad->part = utils::strToPart(partStr);
    componentToLoad->setShip(ship);
}

constants::shipParts AbstractComponent::getShipPart()
{
    return this->part;
}
