#include "navthruster.h"
#include "abstractcomponent.h"
#include "../iship.h"
#include "../../utils/utils.cpp"
#include "../../exception/xmlexception.h"
#include <string.h>

const char* NavThruster::rootName = "nav_thruster";

NavThruster::NavThruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :EnergyProvidable(name, description, ship, maxEnergy){
}

NavThruster::NavThruster(NavThruster *model)
    :EnergyProvidable(model->getName(), model->getDescription(), model->getShip(), model->getMaxEnergy()){
}

void NavThruster::provideEnergy(const int &energy)
{
    int currentEnergy = (energy > this->getMaxEnergy() ? this->getMaxEnergy() : energy);

    this->getShip()->addInertia(utils::getInvertShipDir(this->facingDirection), currentEnergy);
}

constants::ShipDirection NavThruster::getFacingDirection()
{
    return this->facingDirection;
}

void NavThruster::setFacingDirection(constants::ShipDirection facingDirection)
{
    this->facingDirection = facingDirection;
}

void NavThruster::saveXML(pugi::xml_node &root)
{
    pugi::xml_node node = root.append_child(NavThruster::getRootName());
    EnergyProvidable::saveEnergyProvXML(node, this);
    std::string str(utils::shipDirectionToStr(this->getFacingDirection()));
    node.append_attribute("facing_direction").set_value(str.c_str());
}

NavThruster *NavThruster::loadFromXML(IShip *ship, const pugi::xml_node &root)
{
    if(strcmp(root.name(), NavThruster::getRootName()) != 0)
        throw XMLException("Wrong node to load for navThruster : " + std::string(root.name()));

    NavThruster *thruster = new NavThruster("", "", ship, 0);
    EnergyProvidable::loadEnergyProvFromXML(ship, root, thruster);
    thruster->setFacingDirection(utils::strToShipDir(std::string(root.attribute("facing_direction").as_string())));

    return thruster;
}

const char *NavThruster::getRootName()
{
    return rootName;
}

std::string NavThruster::toString()
{
    std::string res = "Nav : ";
    res += utils::shipDirectionToStr(this->getFacingDirection()) + ", " + std::to_string(this->getMaxEnergy());
    return res;
}
