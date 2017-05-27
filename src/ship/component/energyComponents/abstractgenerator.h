#ifndef ABSTRACTGENERATOR_H
#define ABSTRACTGENERATOR_H

/**
 * @file abstractgenerator.h
 */

#include "../abstractcomponent.h"

/**
 * @brief The AbstractGenerator class. An abstract generator.
 */
class AbstractGenerator: public AbstractComponent
{
public:
    /**
     * @brief AbstractGenerator The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship of the generator.
     */
    AbstractGenerator(const std::string & name, const std::string & description, IShip *ship);
    virtual ~AbstractGenerator();
    /**
     * @brief generateEnergy Generate the energy.
     * @return The energy generated.
     */
    virtual int generateEnergy() = 0;
private:
};

#endif // ABSTRACTGENERATOR_H
