#include "rotationthruster.h"
#include "../iship.h"
#include "../../utils/utils.cpp"

RotationThruster::RotationThruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :EnergyProvidable(name, description, ship, maxEnergy){

}

RotationThruster::RotationThruster(RotationThruster *model)
    :EnergyProvidable(model->getName(), model->getDescription(), model->getShip(), model->getMaxEnergy()){

}

void RotationThruster::provideEnergy(const int &energy)
{
    int currentEnergy = (energy > this->getMaxEnergy() ? this->getMaxEnergy() : energy);

    constants::Direction newDirection;
    for(int i = 0; i < currentEnergy; ++i) {
        switch (this->getDirection()) {
        case constants::CLOCKWISE:
            newDirection = utils::getClockwiseDirection(this->getShip()->getDirection());
            break;
        case constants::COUNTER_CLOCKWISE:
            newDirection = utils::getCounterClockwiseDirection(this->getShip()->getDirection());
            break;
        }

        this->getShip()->reorientate(newDirection);
    }
}

constants::ClockDirection RotationThruster::getDirection()
{
    return this->direction;
}

void RotationThruster::setDirection(constants::ClockDirection direction)
{
    this->direction = direction;
}
