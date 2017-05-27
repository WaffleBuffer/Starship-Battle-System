#ifndef VEPGENERATOR_H
#define VEPGENERATOR_H

/**
 * @file vepgenerator.h
 */

#include "abstractgenerator.h"

/**
 * @brief The VEPGenerator class. A Void Exctrator Point (V.E.P.) generator.
 */
class VEPGenerator: public AbstractGenerator
{
public:
    /**
     * @brief VEPGenerator The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     * @param energyDelivered The energy delivered by the V.E.P. generator.
     */
    VEPGenerator(const std::string & name, const std::string & description, IShip *ship, const int & energyDelivered);
    /**
     * @brief generateEnergy Generator some energy.
     * @return The energy generated.
     */
    int generateEnergy() override;
private:
    /**
     * @brief energyDelivered The amount of energy generated.
     */
    int energyDelivered;
};

#endif // VEPGENERATOR_H
