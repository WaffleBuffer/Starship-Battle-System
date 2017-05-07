#ifndef ENERGYCOMPONENT_H
#define ENERGYCOMPONENT_H

#include "abstractcomponent.h"

class EnergyComponent: public AbstractComponent
{
public:
    EnergyComponent(const std::string & name, const std::string & description, IShip *ship,
                    const int & maxEnergy);
private:
    int maxEnergy;
    int currentEnergy;
};

#endif // ENERGYCOMPONENT_H
