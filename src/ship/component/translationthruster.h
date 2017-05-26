#ifndef TRANSLATIONTHRUSTER_H
#define TRANSLATIONTHRUSTER_H

#include "energyprovidable.h"
#include "../../utils/constants.cpp"

class IShip;

class TranslationThruster: public EnergyProvidable {
public:
    TranslationThruster(const std::string & name, const std::string & description, IShip *ship, const int & maxEnergy);
    TranslationThruster(TranslationThruster *model);

    void provideEnergy(const int & energy) override;
    constants::ShipDirection getFacingDirection();
    void setFacingDirection(constants::ShipDirection facingDirection);
private:
    constants::ShipDirection facingDirection;
};

#endif // TRANSLATIONTHRUSTER_H
