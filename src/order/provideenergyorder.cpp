#include "provideenergyorder.h"

#include "../ship/component/energyprovidable.h"
#include "../ship/shipcontrol.h"
#include "../utils/orderexception.h"
#include "../utils/shipexception.h"

ProvideEnergyOrder::ProvideEnergyOrder(IShip *ship, EnergyProvidable *componentProvided, const int & energy)
    :ShipOrder(ship), energy(energy), componentProvided(componentProvided){

    if(this->getControl() == nullptr) {
        throw new ShipException("No ship control", this->getShip());
    }
    if(this->energy > this->getControl()->getCurrentAvailableEnergy()) {
        throw new OrderException("Not enough energy to create this order", nullptr);
    }

}

void ProvideEnergyOrder::applyOrder()
{
    this->componentProvided->provideEnergy(this->energy);
    this->getControl()->setCurrentAvailableEnergy(this->getControl()->getCurrentAvailableEnergy() - this->energy);
}

std::string ProvideEnergyOrder::toString()
{
    std::string msg = "Provide ";

    //msg += energy + " to " + componentProvided->getName();
    return msg;
}
