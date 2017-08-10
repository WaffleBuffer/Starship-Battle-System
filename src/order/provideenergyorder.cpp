#include "provideenergyorder.h"

#include "../ship/component/energyprovidable.h"
#include "../ship/shipControl/shipcontrol.h"
#include "../exception/orderexception.h"
#include "../exception/shipexception.h"

ProvideEnergyOrder::ProvideEnergyOrder(IShip *ship, EnergyProvidable *componentProvided, const int & energy)
    :ShipOrder(ship), energy(energy), componentProvided(componentProvided){

    if(this->getControl() == nullptr) {
        throw new ShipException("No ship control", this->getShip());
    }
    if(energy < 0) {
        throw new OrderException("Negativ energy asked");
    }
    if((unsigned int)this->energy > this->getControl()->getCurrentAvailableEnergy()) {
        throw new OrderException("Not enough energy to create this order");
    }

}

void ProvideEnergyOrder::applyOrder()
{
    this->componentProvided->provideEnergy(this->energy);
    // Already done at ioController level
    //this->getControl()->setCurrentAvailableEnergy(this->getControl()->getCurrentAvailableEnergy() - this->energy);
}

std::string ProvideEnergyOrder::toString()
{
    std::string msg = "Order to provide " + std::to_string(energy) + " to " + componentProvided->getName();
    return msg;
}

EnergyProvidable *ProvideEnergyOrder::getComponentProvided() const
{
    return componentProvided;
}

int ProvideEnergyOrder::getEnergy() const
{
    return energy;
}

void ProvideEnergyOrder::setEnergy(int value)
{
    energy = value;
}
