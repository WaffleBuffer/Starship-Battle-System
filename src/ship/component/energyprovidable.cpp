#include "energyprovidable.h"

EnergyProvidable::EnergyProvidable(const int &maxEnergy)
    :maxEnergy(maxEnergy)
{

}

int EnergyProvidable::getMaxEnergy() {
    return this->maxEnergy;
}
