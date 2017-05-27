#ifndef ELECTRONSAILGENERATOR_H
#define ELECTRONSAILGENERATOR_H

/**
 * @file electrosailgenerator.h
 */

#include "abstractgenerator.h"

/**
 * @brief The ElectronSailGenerator class. A sail that generate energy depending on the ship speed.
 */
class ElectronSailGenerator: public AbstractGenerator
{
public:
    /**
     * @brief ElectronSailGenerator The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     * @param mutliplier Ship's speed time multiplier.
     */
    ElectronSailGenerator(const std::string & name, const std::string & description, IShip *ship,
                          const int & mutliplier);
    /**
     * @brief generateEnergy Generate the energy. Ship's speed time multiplier.
     * @return The energy generated. Ship's speed time multiplier.
     */
    int generateEnergy();
private:
    /**
     * @brief multiplier Ship's speed time multiplier.
     */
    int multiplier;
};

#endif // ELECTRONSAILGENERATOR_H
