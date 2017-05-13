#include "weaponattack.h"

WeaponAttack::WeaponAttack(AbstractWeapon *weapon, const int &distance)
    :weapon(weapon), distance(distance){

}

AbstractWeapon *WeaponAttack::getWeapon()
{
    return this->weapon;
}

int WeaponAttack::getDistance()
{
    return this->distance;
}
