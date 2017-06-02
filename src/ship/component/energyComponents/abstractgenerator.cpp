#include "abstractgenerator.h"

#include "electronsailgenerator.h"
#include "stagegenerator.h"
#include "vepgenerator.h"
#include "../../../exception/xmlexception.h"
#include <string.h>

AbstractGenerator::AbstractGenerator(const std::string &name, const std::string &description, IShip *ship)
    :AbstractComponent(name, description, ship){

}

AbstractGenerator::~AbstractGenerator()
{

}

AbstractGenerator *AbstractGenerator::createGenFromXML(pugi::xml_node node, IShip *ship)
{
    if(strcmp(node.name(), ElectronSailGenerator::getRootName()) == 0) {
        return(ElectronSailGenerator::loadFromXML(ship, node));
    }
    else if(strcmp(node.name(), StageGenerator::getRootName()) == 0) {
        return(StageGenerator::loadFromXML(ship, node));
    }
    else if(strcmp(node.name(), VEPGenerator::getRootName()) == 0) {
        return(VEPGenerator::loadFromXML(ship, node));
    }
    else {
        throw XMLException("Uknown xml node name to create a generator : " + std::string(node.name()));
    }

    return nullptr;
}
