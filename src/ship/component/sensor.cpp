#include "sensor.h"

Sensor::Sensor(const std::string &name, const std::string &description, IShip *ship, const int &maxLevel)
    :AbstractComponent(name, description, ship), maxLevel(maxLevel){
    this->currentLevel = 0;
}

std::string Sensor::toString()
{
    std::string res = "";
    res += std::to_string(this->currentLevel) + " / " + std::to_string(this->maxLevel);
    return res;
}
