#ifndef NAVTHRUSTER_H
#define NAVTHRUSTER_H

#include "energyprovidable.h"
#include "../../utils/constants.cpp"

class IShip;

class NavThruster: public EnergyProvidable {
public:
    NavThruster(const std::string & name, const std::string & description, IShip *ship, const int & maxEnergy);
    NavThruster(NavThruster *model);

    void provideEnergy(const int & energy) override;
    constants::ShipDirection getFacingDirection();
    void setFacingDirection(constants::ShipDirection facingDirection);
private:
    constants::ShipDirection facingDirection;
};

#endif // NAVTHRUSTER_H
