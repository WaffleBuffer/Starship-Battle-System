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

    /**
     * @brief loadFromXML Create a VEPGenerator from an XML node
     * @param root The xml node that should contain the VEPGenerator informations.
     * @param ship The ship that will use this VEPGenerator.
     * @return The created VEPGenerator.
     */
    static VEPGenerator*loadFromXML(IShip *ship, const pugi::xml_node &root);

    /**
     * @brief getRootName Get the VEPGenerator XML root name.
     * @return The VEPGenerator XML root name.
     */
    static const char *getRootName();

private:
    /**
     * @brief energyDelivered The amount of energy generated.
     */
    int energyDelivered;

    /**
     * @brief rootName The name of the XML root for a VEPGenerator
     */
    static const char* rootName;
};

#endif // VEPGENERATOR_H
