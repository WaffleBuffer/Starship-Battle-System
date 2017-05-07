#include "thruster.h"
#include "abstractcomponent.h"

Thruster::Thruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :AbstractComponent(name, description, ship){
    this->maxEnergy = maxEnergy;
}

Thruster::Thruster(Thruster *model)
    :AbstractComponent(model->getName(), model->getDescription(), model->getShip()){
    this->maxEnergy = model->getMaxEnergy();
}

int Thruster::getMaxEnergy() {
    return this->maxEnergy;
}
