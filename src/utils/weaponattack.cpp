#include "weaponattack.h"

WeaponAttack::WeaponAttack(IWeapon *weapon, const int &distance)
    :weapon(weapon), distance(distance){

}

IWeapon *WeaponAttack::getWeapon()
{
    return this->weapon;
}

int WeaponAttack::getDistance()
{
    return this->distance;
}
