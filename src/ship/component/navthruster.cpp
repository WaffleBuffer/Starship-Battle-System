#include "navthruster.h"
#include "abstractcomponent.h"
#include "../iship.h"

NavThruster::NavThruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :AbstractComponent(name, description, ship), EnergyProvidable(maxEnergy){
}

NavThruster::NavThruster(NavThruster *model)
    :AbstractComponent(model->getName(), model->getDescription(), model->getShip()), EnergyProvidable(model->getMaxEnergy()){
}

void NavThruster::provideEnergy(const int &energy)
{
    int currentEnergy = (energy > this->getMaxEnergy() ? this->getMaxEnergy() : energy);

    this->getShip()->addInertia(this->facingDirection, currentEnergy);
}

constants::Direction NavThruster::getFacingDirection()
{
    return this->facingDirection;
}

void NavThruster::setFacingDirection(constants::Direction facingDirection)
{
    this->facingDirection = facingDirection;
}
