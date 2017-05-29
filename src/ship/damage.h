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
     * @brief getBaseValue Get the base damage value. The base number of D6 to try to destroy a structure point.
     * @return  The base damage value.
     */
    int getBaseValue() const;

    /**
     * @brief getCurrentValue The current damage value. The current number of D6 to try to destroy a structure point.
     * @return The current damage value.
     */
    int getCurrentValue() const;

    /**
     * @brief setCurrentValue Set the current damage value. The current number of D6 to try to destroy a structure point.
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

    /**
     * @brief rollDamage Roll the damage. Use it when the current value can't be modified any more.
     */
    void rollDamage();

    /**
     * @brief getRolls Get the values rolled.
     * @return The values rolled.
     */
    std::vector<int> *getRolls() const;

    /**
     * @brief getHasCritical Get if the roll has a critical hit (at least one pair of 1).
     * @return Get if the roll has a critical hit.
     */
    bool getHasCritical() const;

    /**
     * @brief getMaxRollValue Get the higher value rolled.
     * @return The higher value rolled.
     */
    int getMaxRollValue() const;

private:
    /**
     * @brief baseValue The base number of D6 to try to destroy a structure point.
     */
    int baseValue;
    /**
     * @brief currentValue The current number of D6 to try to destroy a structure point.
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

    /**
     * @brief rolls The rolls of the damage. the rolls must be generated after all possible modification to the currentValue.
     */
    std::vector<int> *rolls;

    /**
     * @brief hasCritical Has this damage rolled critical hit.
     */
    bool hasCritical;

    /**
     * @brief maxRollValue The higher value rolled.
     */
    int maxRollValue;
};

#endif // DAMAGE_H
