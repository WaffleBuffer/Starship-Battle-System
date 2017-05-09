#include "provideenergyorder.h"

#include "../ship/component/energyprovidable.h"
#include "../ship/shipcontrol.h"
#include "../utils/shipexception.h"

ProvideEnergyOrder::ProvideEnergyOrder(IShip *ship, EnergyProvidable *componentProvided, const int & energy)
    :ShipOrder(ship), energy(energy), componentProvided(componentProvided){

    if(this->energy > this->getControl()->getCurrentAvailableEnergy()) {
        throw new ShipException("Not enough energy to create this order", ship);
    }
}

void ProvideEnergyOrder::applyOrder()
{
    this->componentProvided->provideEnergy(this->energy);
    this->getControl()->setCurrentAvailableEnergy(this->getControl()->getCurrentAvailableEnergy() - this->energy);
}
