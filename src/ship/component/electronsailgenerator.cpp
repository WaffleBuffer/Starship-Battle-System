#include "electronsailgenerator.h"

#include "../iship.h"

ElectronSailGenerator::ElectronSailGenerator(const std::string &name, const std::string &description, IShip *ship, const int &mutliplier)
    :AbstractGenerator(name, description, ship){

    this->multiplier = mutliplier;
}

int ElectronSailGenerator::generateEnergy()
{
    return this->getShip()->getInertia() * this->multiplier;
}
