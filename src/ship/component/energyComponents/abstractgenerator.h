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

    /**
     * @brief createGenFromXML Create a generator from an XML node.
     * @param node The node that descriebe the generator.
     * @param ship The ship that will use this generator.
     * @return The created generator
     */
    static AbstractGenerator *createGenFromXML(pugi::xml_node node, IShip *ship);
private:
};

#endif // ABSTRACTGENERATOR_H
