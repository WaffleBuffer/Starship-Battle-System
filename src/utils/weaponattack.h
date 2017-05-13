#ifndef WEAPONATTACK_H
#define WEAPONATTACK_H

class AbstractWeapon;

class WeaponAttack
{
public:
    WeaponAttack(AbstractWeapon *weapon, const int & distance);
    AbstractWeapon *getWeapon();
    int getDistance();
private:
    AbstractWeapon *weapon;
    int distance;
};

#endif // WEAPONATTACK_H
