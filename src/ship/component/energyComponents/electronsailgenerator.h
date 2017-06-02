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

    /**
     * @brief loadFromXML Create a ElectronSailGenerator from an XML node
     * @param root The xml node that should contain the ElectronSailGenerator informations.
     * @param ship The ship that will use this ElectronSailGenerator.
     * @return The created ElectronSailGenerator.
     */
    static ElectronSailGenerator*loadFromXML(IShip *ship, const pugi::xml_node &root);

    /**
     * @brief getRootName Get the ElectronSailGenerator XML root name.
     * @return The ElectronSailGenerator XML root name.
     */
    static const char *getRootName();

private:
    /**
     * @brief multiplier Ship's speed time multiplier.
     */
    int multiplier;

    /**
     * @brief rootName The name of the XML root for a ElectronSailGenerator
     */
    static const char* rootName;
};

#endif // ELECTRONSAILGENERATOR_H
