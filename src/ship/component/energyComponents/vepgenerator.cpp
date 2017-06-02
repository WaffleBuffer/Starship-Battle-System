#include "vepgenerator.h"

#include "../../../exception/xmlexception.h"
#include <string.h>

const char* VEPGenerator::rootName = "vep_generator";

VEPGenerator::VEPGenerator(const std::string &name, const std::string &description, IShip *ship, const int &energyDelivered)
    :AbstractGenerator(name, description, ship){
    this->energyDelivered = energyDelivered;
}

int VEPGenerator::generateEnergy()
{
    return this->energyDelivered;
}

VEPGenerator *VEPGenerator::loadFromXML(IShip *ship, const pugi::xml_node &root)
{
    if(strcmp(root.name(), VEPGenerator::getRootName()) != 0)
        throw XMLException("Wrong node to load for VEPGenerator : " + std::string(root.name()));

    throw XMLException("XML loading for VEPGenerator not yet implemented");
}

const char *VEPGenerator::getRootName()
{
    return rootName;
}
