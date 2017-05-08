#ifndef TRANSLATIONTHRUSTER_H
#define TRANSLATIONTHRUSTER_H

#include "abstractcomponent.h"
#include "energyprovidable.h"
#include "../../utils/constants.cpp"

class IShip;

class TranslationThruster: public AbstractComponent, public EnergyProvidable {
public:
    TranslationThruster(const std::string & name, const std::string & description, IShip *ship, const int & maxEnergy);
    TranslationThruster(TranslationThruster *model);

    void provideEnergy(const int & energy) override;
    constants::Direction getFacingDirection();
    void setFacingDirection(constants::Direction facingDirection);
private:
    constants::Direction facingDirection;
};

#endif // TRANSLATIONTHRUSTER_H
