#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

#include "../energyprovidable.h"

class Accumulator: public EnergyProvidable
{
public:
    Accumulator(const std::string & name, const std::string & description, IShip *ship, const int &maxEnergy);
    void provideEnergy(const int & energy) override;
    int collectEnergy(const int &amount);
private:
    int currentEnergy;
};

#endif // ACCUMULATOR_H
