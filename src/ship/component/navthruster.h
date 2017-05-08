#ifndef NAVTHRUSTER_H
#define NAVTHRUSTER_H

#include "abstractcomponent.h"
#include "energyprovidable.h"
#include "../../utils/constants.cpp"

class IShip;

class NavThruster: public AbstractComponent, public EnergyProvidable {
public:
    NavThruster(const std::string & name, const std::string & description, IShip *ship, const int & maxEnergy);
    NavThruster(NavThruster *model);

    void provideEnergy(const int & energy) override;
    constants::Direction getFacingDirection();
    void setFacingDirection(constants::Direction facingDirection);
private:
    constants::Direction facingDirection;
};

#endif // NAVTHRUSTER_H
