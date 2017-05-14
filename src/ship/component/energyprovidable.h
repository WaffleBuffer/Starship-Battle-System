#ifndef ENERGYPROVIDABLE_H
#define ENERGYPROVIDABLE_H

#include "abstractcomponent.h"

class EnergyProvidable: public AbstractComponent
{
public:
    EnergyProvidable(const std::string & name, const std::string & description, IShip *ship, const int & maxEnergy);
    virtual ~EnergyProvidable() {}
    virtual void provideEnergy(const int & energy) = 0;
    int getMaxEnergy();
private:
    const int maxEnergy;
};

#endif // ENERGYPROVIDABLE_H
