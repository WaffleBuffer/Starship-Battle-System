#ifndef DAMAGEABLE_H
#define DAMAGEABLE_H

/**
 * @file damageable.h
 */

class Damage;

/**
 * @brief The Damageable class. A damageable object. Abstract
 */
class Damageable
{
public:
    /**
     * @brief Damageable The constructor.
     */
    Damageable();
    virtual ~Damageable() {}
    /**
     * @brief getDamaged Take damage.
     * @param damage The damage to take.
     */
    virtual void getDamaged(Damage *damage) = 0;
};

#endif // DAMAGEABLE_H
