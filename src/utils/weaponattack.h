#ifndef WEAPONATTACK_H
#define WEAPONATTACK_H

class IWeapon;

class WeaponAttack
{
public:
    WeaponAttack(IWeapon *weapon, const int & distance);
    IWeapon *getWeapon();
    int getDistance();
private:
    IWeapon *weapon;
    int distance;
};

#endif // WEAPONATTACK_H
