#include "accumulator.h"

Accumulator::Accumulator(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :EnergyProvidable(name, description, ship, maxEnergy){

}

void Accumulator::provideEnergy(const int &energy)
{
    this->currentEnergy += energy;
    if(this->currentEnergy > this->getMaxEnergy()) {
        this->currentEnergy = this->currentEnergy;
    }
}

int Accumulator::collectEnergy(const int &amount)
{
    int energy = 0;
    if(amount > this->currentEnergy) {
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
