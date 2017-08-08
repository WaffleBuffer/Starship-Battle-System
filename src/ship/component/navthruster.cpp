#include "navthruster.h"
#include "abstractcomponent.h"
#include "../iship.h"
#include "../../utils/utils.cpp"
#include "../../exception/xmlexception.h"
#include "../../exception/shipexception.h"
#include "../../order/moveorder.h"
#include "../shipControl/shipcontrol.h"

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
    if(energy < 0) {
        throw new ShipException("Negative energy on navThruster", this->getShip());
    }
    if((unsigned int)energy > this->getMaxEnergy()) {
        throw new ShipException("Too much energy provided to navthruster", this->getShip());
    }
    unsigned int currentEnergy = energy;

    MoveOrder *order = new MoveOrder(this->getShip(), utils::getInvertShipDir(this->getFacingDirection()), currentEnergy, true);
    this->getShip()->getControl()->addOrder(order);
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
