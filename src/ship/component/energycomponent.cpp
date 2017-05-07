#include "energycomponent.h"

EnergyComponent::EnergyComponent(const std::string & name, const std::string & description, IShip *ship,
                                 const int & maxEnergy)
    : AbstractComponent(name, description, ship){
    this->maxEnergy = maxEnergy;
    this->currentEnergy = 0;
}
