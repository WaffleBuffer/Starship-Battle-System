#ifndef ROTATIONTHRUSTER_H
#define ROTATIONTHRUSTER_H

#include "energyprovidable.h"
#include "../../utils/constants.cpp"

class IShip;

class RotationThruster: public EnergyProvidable
{
public:
    RotationThruster(const std::string & name, const std::string &description, IShip *ship, const int & maxEnergy);
    RotationThruster(RotationThruster *model);

    void provideEnergy(const int & energy) override;
    int getDirection();
    void setDirection(const int &direction);
private:
    int direction;
};

#endif // ROTATIONTHRUSTER_H
