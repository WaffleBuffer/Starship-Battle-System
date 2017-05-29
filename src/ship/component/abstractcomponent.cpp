#include "abstractcomponent.h"

AbstractComponent::AbstractComponent(const std::string & name, const std::string & description, IShip *ship)
{
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
