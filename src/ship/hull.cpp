#include "hull.h"

#include "hulllevel.h"
#include "iship.h"
#include "damage.h"
#include "../exception/xmlexception.h"
#include "../thirdParty/pugixml-1.8/src/pugixml.hpp"
#include <string.h>

const char* Hull::rootName = "hull";

Hull::Hull(IShip *ship, std::vector<HullLevel *> *hullLevels)
    :AbstractComponent("", "", ship), hullLevels(hullLevels), currentLevel(hullLevels->at(0)), currentLevelIndex(0){
}

Hull::~Hull()
{
    for(size_t i = 0; i < this->hullLevels->size(); ++i) {
        delete(this->hullLevels->at(i));
    }
    delete(this->hullLevels);
}

std::string Hull::toString()
{
    std::string res = "";
    for(size_t i = 0; i < this->hullLevels->size(); ++i) {
        if(this->currentLevelIndex == i) {
            res += " [(" + std::to_string(this->hullLevels->size() - i) + ", " + this->hullLevels->at(i)->toString() + ")] |";
        }
        else {
            res += " (" + std::to_string(this->hullLevels->size() - i) + ", " + this->hullLevels->at(i)->toString() + ") |";
        }

    }
    return res;
}

void Hull::notify(Observable *origin, MyObject *arg)
{
    IShip *ship = dynamic_cast<IShip*> (origin);
    if(ship == NULL) {
        return;
    }
    Damage *damage = dynamic_cast<Damage*>(arg);
    if(damage == NULL) {
        return;
    }

    if(damage->getMaxRollValue() >= this->currentLevel->getHullQuality()) {
        this->deteriorateHull();
    }
}

void Hull::deteriorateHull()
{
    if(this->currentLevelIndex == this->hullLevels->size() - 1) {
        this->getShip()->destroy();
    }
    else {
        this->currentLevelIndex++;
        this->currentLevel = this->hullLevels->at(this->currentLevelIndex);
    }
}

void Hull::saveXML(pugi::xml_node &root)
{
    pugi::xml_node thisRoot = root.append_child(Hull::getRootName());
    AbstractComponent::saveAbstractXML(thisRoot, this);
    thisRoot.append_attribute("currentlevelindex").set_value(this->currentLevelIndex);

    for(size_t i = 0; i < this->hullLevels->size(); ++i) {
        this->hullLevels->at(i)->saveXML(thisRoot);
    }
}

Hull *Hull::loadFromXML(IShip *ship, const pugi::xml_node &root)
{
    if(strcmp(root.name(), Hull::getRootName()) != 0)
        throw XMLException("Wrong node to load for Hull : " + std::string(root.name()));

    std::vector<HullLevel *> *hullLevels = new std::vector<HullLevel *>();
    for(pugi::xml_node node = root.child(HullLevel::getRootName()); node; node = node.next_sibling()) {
        hullLevels->push_back(HullLevel::loadFromXML(node));
    }

    Hull *hull = new Hull(ship, hullLevels);
    AbstractComponent::loadAbstractFromXML(ship, root, hull);
    hull->currentLevelIndex = root.attribute("currentlevelindex").as_uint();
    hull->currentLevel = hull->hullLevels->at(hull->currentLevelIndex);

    return hull;
}

const char *Hull::getRootName()
{
    return rootName;
}
