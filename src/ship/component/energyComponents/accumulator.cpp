#include "accumulator.h"
#include "../../../exception/shipexception.h"

Accumulator::Accumulator(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :EnergyProvidable(name, description, ship, maxEnergy){

}

void Accumulator::provideEnergy(const int &energy)
{
    if(energy < 0) {
        throw new ShipException("Negative energy provided to Accumulator", this->getShip());
    }
    this->currentEnergy += energy;
    if(this->currentEnergy > this->getMaxEnergy()) {
        this->currentEnergy = this->currentEnergy;
    }
}

unsigned int Accumulator::collectEnergy(const int &amount)
{
    if(amount < 0) {
        throw new ShipException("Negative energy desired to collect from Accumulator", this->getShip());
    }
    unsigned int energy = 0;
    if((unsigned int)amount > this->currentEnergy) {
        energy = this->currentEnergy;
        this->currentEnergy = 0;
        return energy;
    }
    else {
        energy = amount;
        this->currentEnergy -= amount;
        return energy;
    }
}
