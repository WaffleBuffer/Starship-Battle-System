#ifndef STABILIZATOR_H
#define STABILIZATOR_H

/**
 * @file stabilizator.h
 */

#include "../energyprovidable.h"

class StageGenerator;

/**
 * @brief The Stabilizator class. Used to stabilize a stage generator.
 */
class Stabilizator: public EnergyProvidable
{
public:
    /**
     * @brief Stabilizator The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     * @param maxEnergy The maximum amount of energy that can be stored.
     * @param generator The generator using this stabilizator.
     */
    Stabilizator(const std::string & name, const std::string & description, IShip *ship, const int &maxEnergy, StageGenerator *generator);
    /**
     * @brief Stabilizator The copy constructor.
     * @param model The model to use.
     */
    Stabilizator(Stabilizator *model);
    /**
     * @brief setGenerator Set the generator using this stabilizator.
     * @param generator The generator to set.
     */
    void setGenerator(StageGenerator *generator);
    /**
     * @brief provideEnergy Add some energy to store. Any surplus will be lost.
     * @param energy The energy to store.
     */
    void provideEnergy(const int & energy) override;
    /**
     * @brief stabilize Use the energy to store the generator.
     */
    void stabilize();
private:
    /**
     * @brief generator The generator using this stabilizator.
     */
    StageGenerator *generator;
    /**
     * @brief currentEnergy The current amount of energy stored.
     */
    int currentEnergy;
};

#endif // STABILIZATOR_H
