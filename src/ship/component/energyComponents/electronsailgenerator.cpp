#include "electronsailgenerator.h"

#include "../../iship.h"
#include "../../../utils/vectorialmovement.h"
#include "../../../exception/xmlexception.h"
#include <string.h>

const char* ElectronSailGenerator::rootName = "sail_generator";

ElectronSailGenerator::ElectronSailGenerator(const std::string &name, const std::string &description, IShip *ship, const int &mutliplier)
    :AbstractGenerator(name, description, ship){

    this->multiplier = mutliplier;
}

int ElectronSailGenerator::generateEnergy()
{
    return this->getShip()->getMovement()->getDistance() * this->multiplier;
}

ElectronSailGenerator *ElectronSailGenerator::loadFromXML(IShip *ship, const pugi::xml_node &root)
{
    if(strcmp(root.name(), ElectronSailGenerator::getRootName()) != 0)
        throw XMLException("Wrong node to load for ElectronSailGenerator : " + std::string(root.name()));

    throw XMLException("XML loading for ElectronSailGenerator not yet implemented");
}

const char *ElectronSailGenerator::getRootName()
{
    return rootName;
}
