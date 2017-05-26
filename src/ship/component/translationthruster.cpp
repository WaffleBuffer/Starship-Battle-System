#include "translationthruster.h"

#include "abstractcomponent.h"
#include "../iship.h"

TranslationThruster::TranslationThruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :EnergyProvidable(name, description, ship, maxEnergy){
}

TranslationThruster::TranslationThruster(TranslationThruster *model)
    :EnergyProvidable(model->getName(), model->getDescription(), model->getShip(), model->getMaxEnergy()){
}

void TranslationThruster::provideEnergy(const int &energy)
{
    int currentEnergy = (energy > this->getMaxEnergy() ? this->getMaxEnergy() : energy);

    this->getShip()->translate(this->facingDirection, currentEnergy);
}

constants::ShipDirection TranslationThruster::getFacingDirection()
{
    return this->facingDirection;
}

void TranslationThruster::setFacingDirection(constants::ShipDirection facingDirection)
{
    this->facingDirection = facingDirection;
}
