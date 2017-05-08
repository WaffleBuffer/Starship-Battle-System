#ifndef ROTATIONTHRUSTER_H
#define ROTATIONTHRUSTER_H

#include "abstractcomponent.h"
#include "energyprovidable.h"
#include "../../utils/constants.cpp"

class IShip;

class RotationThruster: public AbstractComponent, public EnergyProvidable
{
public:
    RotationThruster(const std::string & name, const std::string & description, IShip *ship, const int & maxEnergy);
    RotationThruster(RotationThruster *model);

    void provideEnergy(const int & energy) override;
    constants::ClockDirection getDirection();
    void setDirection(constants::ClockDirection direction);
private:
    constants::ClockDirection direction;
};

#endif // ROTATIONTHRUSTER_H
