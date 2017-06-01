#include "rotationthruster.h"
#include "../iship.h"
#include "../../utils/utils.cpp"
#include "../../exception/xmlexception.h"
#include <string.h>

const char* RotationThruster::rootName = "rotation_thruster";

RotationThruster::RotationThruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :EnergyProvidable(name, description, ship, maxEnergy){

}

RotationThruster::RotationThruster(RotationThruster *model)
    :EnergyProvidable(model->getName(), model->getDescription(), model->getShip(), model->getMaxEnergy()){

}

void RotationThruster::provideEnergy(const int &energy)
{
    //int currentEnergy = (energy > this->getMaxEnergy() ? this->getMaxEnergy() : energy);

    this->getShip()->rotate(this->getDirection());
}

int RotationThruster::getDirection()
{
    return this->direction;
}

void RotationThruster::setDirection(const int &direction)
{
    this->direction = direction;
}

void RotationThruster::saveXML(pugi::xml_node &root)
{
    pugi::xml_node node = root.append_child(RotationThruster::getRootName());
    EnergyProvidable::saveEnergyProvXML(node, this);
    node.append_attribute("direction").set_value(std::to_string(this->getDirection()).c_str());
}

RotationThruster *RotationThruster::loadFromXML(IShip *ship, const pugi::xml_node &root)
{
    if(strcmp(root.name(), RotationThruster::getRootName()) != 0)
        throw XMLException("Wrong node to load for navThruster : " + std::string(root.name()));

    RotationThruster *thruster = new RotationThruster("", "", ship, 0);
    EnergyProvidable::loadEnergyProvFromXML(ship, root, thruster);
    thruster->setDirection(root.attribute("direction").as_int());

    return thruster;
}

const char *RotationThruster::getRootName()
{
    return rootName;
}
