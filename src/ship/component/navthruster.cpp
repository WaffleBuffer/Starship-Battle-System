#include "navthruster.h"
#include "abstractcomponent.h"
#include "../iship.h"
#include "../../utils/utils.cpp"

NavThruster::NavThruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :EnergyProvidable(name, description, ship, maxEnergy){
}

NavThruster::NavThruster(NavThruster *model)
    :EnergyProvidable(model->getName(), model->getDescription(), model->getShip(), model->getMaxEnergy()){
}

void NavThruster::provideEnergy(const int &energy)
{
    int currentEnergy = (energy > this->getMaxEnergy() ? this->getMaxEnergy() : energy);

    this->getShip()->addInertia(utils::getInvertDir(this->facingDirection), currentEnergy);
}

constants::Direction NavThruster::getFacingDirection()
{
    return this->facingDirection;
}

void NavThruster::setFacingDirection(constants::Direction facingDirection)
{
    this->facingDirection = facingDirection;
}
