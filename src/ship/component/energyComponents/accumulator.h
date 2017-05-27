#ifndef ACCUMULATOR_H
#define ACCUMULATOR_H

/**
 * @file accumulator.h
 */

#include "../energyprovidable.h"

/**
 * @brief The Accumulator class. An energy storage.
 */
class Accumulator: public EnergyProvidable
{
public:
    /**
     * @brief Accumulator The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     * @param maxEnergy The maximum amount of energy that can be stored.
     */
    Accumulator(const std::string & name, const std::string & description, IShip *ship, const int &maxEnergy);
    /**
     * @brief provideEnergy Add some energy to this accumulator.
     * @param energy The energy amount. The surplus is lost.
     */
    void provideEnergy(const int & energy) override;
    /**
     * @brief collectEnergy Get some energy from this accumulator.
     * @param amount The amount of energy desired.
     * @return The actual amout get.
     */
    int collectEnergy(const int &amount);
private:
    /**
     * @brief currentEnergy The current amount of energy stored.
     */
    int currentEnergy;
};

#endif // ACCUMULATOR_H
