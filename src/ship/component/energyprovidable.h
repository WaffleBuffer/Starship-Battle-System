#ifndef ENERGYPROVIDABLE_H
#define ENERGYPROVIDABLE_H


class EnergyProvidable
{
public:
    EnergyProvidable(const int & maxEnergy);
    virtual ~EnergyProvidable() {}
    virtual void provideEnergy(const int & energy) = 0;
    int getMaxEnergy();
private:
    const int maxEnergy;
};

#endif // ENERGYPROVIDABLE_H
