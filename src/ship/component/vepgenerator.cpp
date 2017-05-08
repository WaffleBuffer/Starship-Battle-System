#include "vepgenerator.h"

VEPGenerator::VEPGenerator(const std::string &name, const std::string &description, IShip *ship, const int &energyDelivered)
    :AbstractGenerator(name, description, ship){
    this->energyDelivered = energyDelivered;
}

int VEPGenerator::generateEnergy()
{
    return this->energyDelivered;
}
