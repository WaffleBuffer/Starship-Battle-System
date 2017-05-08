#include "translationthruster.h"

#include "abstractcomponent.h"
#include "../iship.h"

TranslationThruster::TranslationThruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :AbstractComponent(name, description, ship), EnergyProvidable(maxEnergy){
}

TranslationThruster::TranslationThruster(TranslationThruster *model)
    :AbstractComponent(model->getName(), model->getDescription(), model->getShip()), EnergyProvidable(model->getMaxEnergy()){
}

void TranslationThruster::provideEnergy(const int &energy)
{
    int currentEnergy = (energy > this->getMaxEnergy() ? this->getMaxEnergy() : energy);

    this->getShip()->translate(this->facingDirection, currentEnergy);
}

constants::Direction TranslationThruster::getFacingDirection()
{
    return this->facingDirection;
}

void TranslationThruster::setFacingDirection(constants::Direction facingDirection)
{
    this->facingDirection = facingDirection;
}
