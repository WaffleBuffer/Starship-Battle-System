#ifndef DAMAGE_H
#define DAMAGE_H

/**
 * @file damage.h
 */

#include "../utils/myobject.h"
#include "../utils/constants.cpp"

#include <vector>

class WeaponAttack;

/**
 * @brief The Damage class. Represent a damage from one component.
 */
class Damage: public MyObject
{
public:
    /**
     * @brief Damage The constructor.
     * @param baseValue The base value of the attack.
     * @param faceTargeted The targeted face of the target.
     */
    Damage(const int & baseValue, constants::ShipDirection faceTargeted);
    ~Damage();
    /**
     * @brief getBaseValue Get the base damage value.
     * @return  The base damage value.
     */
    int getBaseValue() const;

    /**
     * @brief getCurrentValue The current damage value.
     * @return The current damage value.
     */
    int getCurrentValue() const;

    /**
     * @brief setCurrentValue Set the current damage value.
     * @param value The value to set.
     */
    void setCurrentValue(int value);

    /**
     * @brief getFaceTargeted Get the targeted face on the taget.
     * @return The targeted face.
     */
    constants::ShipDirection getFaceTargeted() const;

    /**
     * @brief getOrigins Get the attacking weapons objects.
     * @return The weapon attack objects.
     */
    std::vector<WeaponAttack *> *getOrigins() const;
    /**
     * @brief addOrigin Add another weapon attack.
     * @param origin The weapon attack to add.
     */
    void addOrigin(WeaponAttack *origin);

private:
    /**
     * @brief baseValue The base damage value.
     */
    int baseValue;
    /**
     * @brief currentValue The current damage value.
     */
    int currentValue;
    /**
     * @brief faceTargeted The targeted face on the target.
     */
    constants::ShipDirection faceTargeted;
    /**
     * @brief origins the attack objects.
     */
    std::vector<WeaponAttack *> *origins;
};

#endif // DAMAGE_H
