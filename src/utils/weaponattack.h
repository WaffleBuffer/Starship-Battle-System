#ifndef WEAPONATTACK_H
#define WEAPONATTACK_H

/**
 * @file weaponattack.h
 */

class AbstractWeapon;

/**
 * @brief The WeaponAttack class. An attack from a weapon.
 */
class WeaponAttack
{
public:
    /**
     * @brief WeaponAttack The constructor.
     * @param weapon The attacking weapon.
     * @param distance The range of the attack.
     */
    WeaponAttack(AbstractWeapon *weapon, const int & distance);
    /**
     * @brief getWeapon Get the weapon
     * @return The weapon.
     */
    AbstractWeapon *getWeapon();
    /**
     * @brief getDistance Get the range of the attack.
     * @return The range of the attack.
     */
    int getDistance();
private:
    /**
     * @brief weapon The attacking weapon.
     */
    AbstractWeapon *weapon;
    /**
     * @brief distance The range of the weapon fireing.
     */
    int distance;
};

#endif // WEAPONATTACK_H
