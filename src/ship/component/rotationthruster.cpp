#include "rotationthruster.h"
#include "../iship.h"
#include "../../utils/utils.cpp"

RotationThruster::RotationThruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :EnergyProvidable(name, description, ship, maxEnergy){

}

RotationThruster::RotationThruster(RotationThruster *model)
    :EnergyProvidable(model->getName(), model->getDescription(), model->getShip(), model->getMaxEnergy()){

}

void RotationThruster::provideEnergy(const int &energy)
{
    //int currentEnergy = (energy > this->getMaxEnergy() ? this->getMaxEnergy() : energy);

    this->getShip()->rotate(this->getDirection());
}

int RotationThruster::getDirection()
{
    return this->direction;
}

void RotationThruster::setDirection(const int &direction)
{
    this->direction = direction;
}
