#include "stabilizator.h"

#include "stagegenerator.h"
#include "../../../exception/shipexception.h"
#include "../../../exception/xmlexception.h"
#include <string.h>

const char* Stabilizator::rootName = "stabilizator";

Stabilizator::Stabilizator(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy, StageGenerator *generator)
    :EnergyProvidable(name, description, ship, maxEnergy), generator(generator){

}

Stabilizator::Stabilizator(Stabilizator *model)
    :EnergyProvidable(model->getName(), model->getDescription(), model->getShip(), model->getMaxEnergy()), generator(model->generator){

}

void Stabilizator::setGenerator(StageGenerator *generator)
{
    this->generator = generator;
}

void Stabilizator::provideEnergy(const int &energy)
{
    this->currentEnergy += energy;
    if(this->currentEnergy > this->getMaxEnergy()) {
        this->currentEnergy = this->currentEnergy;
    }
}

void Stabilizator::stabilize()
{
    if(this->generator == nullptr) {
        throw new ShipException("No generator attached", this->getShip());
    }
    int level = this->generator->getCurrentStageIndex() + 1;
    if(this->currentEnergy < level) {
        return;
    }
    else if(this->generator->getCurrentStageIndex() == 0){
        return;
    }
    else {
        this->generator->setCurrentStage(-1);
    }
}

void Stabilizator::saveXML(pugi::xml_node &root)
{
    pugi::xml_node node = root.append_child(Stabilizator::getRootName());
    EnergyProvidable::saveEnergyProvXML(node, this);
    node.append_attribute("energy").set_value(std::to_string(this->currentEnergy).c_str());
}

Stabilizator *Stabilizator::loadFromXML(IShip *ship, const pugi::xml_node &root)
{
    if(strcmp(root.name(), Stabilizator::getRootName()) != 0)
        throw XMLException("Wrong node to load for Stabilizator : " + std::string(root.name()));

    Stabilizator *stabilizator = new Stabilizator("", "", ship, 0, nullptr);
    EnergyProvidable::loadEnergyProvFromXML(ship, root, stabilizator);
    int energy = root.attribute("energy").as_int();
    stabilizator->currentEnergy = energy;
    return stabilizator;
}

const char *Stabilizator::getRootName()
{
    return rootName;
}
