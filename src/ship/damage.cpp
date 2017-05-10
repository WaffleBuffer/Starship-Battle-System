#include "damage.h"

#include "../utils/weaponattack.h"

Damage::Damage(const int & baseValue, constants::ShipDirection faceTargeted)
    :baseValue(baseValue), currentValue(baseValue), faceTargeted(faceTargeted), origins(new std::vector<WeaponAttack *>()){

}

Damage::~Damage()
{
    delete(this->origins);
}

int Damage::getBaseValue() const
{
    return baseValue;
}

int Damage::getCurrentValue() const
{
    return currentValue;
}

void Damage::setCurrentValue(int value)
{
    currentValue = value;
}

constants::ShipDirection Damage::getFaceTargeted() const
{
    return faceTargeted;
}

std::vector<WeaponAttack *> *Damage::getOrigins() const
{
    return origins;
}

void Damage::addOrigin(WeaponAttack *origin)
{
    this->origins->push_back(origin);
}
