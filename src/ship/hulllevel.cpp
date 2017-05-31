#include "hulllevel.h"

#include "../exception/xmlexception.h"
#include "../thirdParty/pugixml-1.8/src/pugixml.hpp"
#include <string.h>

const char* HullLevel::rootName = "hull_level";

HullLevel::HullLevel(const int &hullQuality)
    :XMLSavable(HullLevel::getRootName()), hullQuality(hullQuality){

}

HullLevel::~HullLevel()
{

}

std::string HullLevel::toString()
{
    std::string res = "";
    res += std::to_string(this->hullQuality);
    return res;
}

int HullLevel::getHullQuality() const
{
    return hullQuality;
}

const char *HullLevel::getRootName()
{
    return rootName;
}

void HullLevel::saveXML(pugi::xml_node &root)
{
    pugi::xml_node thisRoot = root.append_child(HullLevel::getRootName());
    thisRoot.append_attribute("hullQuality").set_value(this->hullQuality);
}

HullLevel *HullLevel::loadFromXML(const pugi::xml_node &root)
{
    if(strcmp(root.name(), HullLevel::getRootName()) != 0)
        throw XMLException("Wrong node to load for HullLevel : " + std::string(root.name()));

    HullLevel *hullLevel = new HullLevel(root.attribute("hullQuality").as_int());
    return hullLevel;
}
