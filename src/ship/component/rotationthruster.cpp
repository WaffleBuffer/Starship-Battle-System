#include "rotationthruster.h"
#include "../iship.h"
#include "../../utils/utils.cpp"
#include "../../exception/xmlexception.h"
#include "../../exception/shipexception.h"

#include <string.h>

const char* RotationThruster::rootName = "rotation_thruster";

RotationThruster::RotationThruster(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy)
    :EnergyProvidable(name, description, ship, maxEnergy), direction(0){

}

RotationThruster::RotationThruster(RotationThruster *model)
    :EnergyProvidable(model->getName(), model->getDescription(), model->getShip(), model->getMaxEnergy()),
    direction(model->getDirection()){

}

void RotationThruster::provideEnergy(const int &energy)
{
    if(energy < 0) {
        throw new ShipException("Negative energy provided to RotationThruster", this->getShip());
    }
    if((unsigned int)energy > this->getMaxEnergy()) {
        throw new ShipException("Too much energy provided to rotation thruster", this->getShip());
    }
    /*unsigned int currentEnergy = 0;
    energy < 0 ? currentEnergy = 0 : currentEnergy = energy;*/

    // TODO ask for ioController to get a rotation angle
    //this->getShip()->rotate(this->getDirection());
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
        throw XMLException("Wrong node to load for RotationThruster : " + std::string(root.name()));

    RotationThruster *thruster = new RotationThruster("", "", ship, 0);
    EnergyProvidable::loadEnergyProvFromXML(ship, root, thruster);
    thruster->setDirection(root.attribute("direction").as_int());

    return thruster;
}

const char *RotationThruster::getRootName()
{
    return rootName;
}

std::string RotationThruster::toString()
{
    std::string res = "Rotation : ";
    res += std::to_string(this->getMaxEnergy()) + ", dir : " + std::to_string(this->getDirection());
    return res;
}
