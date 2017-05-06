#ifndef ENERGYCOMPONENT_H
#define ENERGYCOMPONENT_H

#include "abstractcomponent.h"

class EnergyComponent: public AbstractComponent
{
public:
    EnergyComponent();
private:
    int maxEnergy;
    int currentEnergy;
};

#endif // ENERGYCOMPONENT_H
