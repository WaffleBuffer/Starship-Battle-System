#ifndef DAMAGE_H
#define DAMAGE_H

#include "../utils/myobject.h"
#include "../utils/constants.cpp"

#include <vector>

class WeaponAttack;

class Damage: public MyObject
{
public:
    Damage(const int & baseValue, constants::ShipDirection faceTargeted);
    ~Damage();
    int getBaseValue() const;

    int getCurrentValue() const;

    void setCurrentValue(int value);

    constants::ShipDirection getFaceTargeted() const;

    std::vector<WeaponAttack *> *getOrigins() const;
    void addOrigin(WeaponAttack *origin);

private:
    int baseValue;
    int currentValue;
    constants::ShipDirection faceTargeted;
    std::vector<WeaponAttack *> *origins;
};

#endif // DAMAGE_H
