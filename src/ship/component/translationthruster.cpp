#include "translationthruster.h"

#include "abstractcomponent.h"
#include "../iship.h"
#include "../../utils/utils.cpp"
#include "../../exception/xmlexception.h"
#include "../../exception/shipexception.h"

#include <string.h>

const char* TranslationThruster::rootName = "trans_thruster";

TranslationThruster::TranslationThruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :EnergyProvidable(name, description, ship, maxEnergy){
}

TranslationThruster::TranslationThruster(TranslationThruster *model)
    :EnergyProvidable(model->getName(), model->getDescription(), model->getShip(), model->getMaxEnergy()){
}

void TranslationThruster::provideEnergy(const int &energy)
{
    if(energy > this->getMaxEnergy()) {
        throw new ShipException("Too much energy provided to translation thruster", this->getShip());
    }
    unsigned int currentEnergy = 0;
    energy < 0 ? currentEnergy = 0 : currentEnergy = energy;

    this->getShip()->translate(this->facingDirection, currentEnergy);
}

constants::ShipDirection TranslationThruster::getFacingDirection()
{
    return this->facingDirection;
}

void TranslationThruster::setFacingDirection(constants::ShipDirection facingDirection)
{
    this->facingDirection = facingDirection;
}

void TranslationThruster::saveXML(pugi::xml_node &root)
{
    pugi::xml_node node = root.append_child(TranslationThruster::getRootName());
    EnergyProvidable::saveEnergyProvXML(node, this);
    node.append_attribute("facing_direction").set_value(utils::shipDirectionToStr(this->getFacingDirection()).c_str());
}

TranslationThruster *TranslationThruster::loadFromXML(IShip *ship, const pugi::xml_node &root)
{
    if(strcmp(root.name(), TranslationThruster::getRootName()) != 0)
        throw XMLException("Wrong node to load for translationThruster : " + std::string(root.name()));

    TranslationThruster *thruster = new TranslationThruster("", "", ship, 0);
    EnergyProvidable::loadEnergyProvFromXML(ship, root, thruster);
    thruster->setFacingDirection(utils::strToShipDir(root.attribute("facing_direction").as_string()));

    return thruster;
}

const char *TranslationThruster::getRootName()
{
    return rootName;
}

std::string TranslationThruster::toString()
{
    std::string res = "Trans : ";
    res += utils::shipDirectionToStr(this->getFacingDirection()) + ", " + std::to_string(this->getMaxEnergy());
    return res;
}
