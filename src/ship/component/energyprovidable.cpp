#include "energyprovidable.h"

EnergyProvidable::EnergyProvidable(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :AbstractComponent(name, description, ship), maxEnergy(maxEnergy)
{

}

int EnergyProvidable::getMaxEnergy() {
    return this->maxEnergy;
}
