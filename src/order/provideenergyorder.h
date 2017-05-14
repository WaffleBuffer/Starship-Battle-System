#ifndef PROVIDEENERGYORDER_H
#define PROVIDEENERGYORDER_H

#include "shiporder.h"

class EnergyProvidable;

class ProvideEnergyOrder: public ShipOrder
{
public:
    ProvideEnergyOrder(IShip *ship, EnergyProvidable *componentProvided, const int & energy);
    void applyOrder() override;
    std::string toString() override;
private:
    int energy;
    EnergyProvidable *componentProvided;
};

#endif // PROVIDEENERGYORDER_H
