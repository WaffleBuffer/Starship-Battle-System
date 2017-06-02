#include "generatorstage.h"

#include "stagegenerator.h"
#include "../../../utils/utils.cpp"
#include "stabilizator.h"
#include "../../../exception/xmlexception.h"
#include "stoppedgeneratorstage.h"
#include <string.h>

const char* GeneratorStage::rootName = "generator_stage";

GeneratorStage::GeneratorStage(const constants::StageGeneratorStage & stage, DiceExpression *energyDelivered, StageGenerator *generator){
    this->stage = stage;
    this->energyDelivered = energyDelivered;
    this->generator = generator;
}

GeneratorStage::GeneratorStage(GeneratorStage *model, StageGenerator *generator)
    :stage(model->getStage()), energyDelivered(model->energyDelivered), generator(generator){

}

GeneratorStage::~GeneratorStage()
{
    delete(this->energyDelivered);
}

int GeneratorStage::generateEnergy()
{
    int energy = this->energyDelivered->roll();
    return energy;
}

constants::StageGeneratorStage GeneratorStage::getStage()
{
    return this->stage;
}

std::string GeneratorStage::toString()
{
    std::string res = "";
    res += utils::stageGeneratorStagesToStr(this->stage) + " " + this->energyDelivered->toString();
    return res;
}

void GeneratorStage::stabilize()
{
    for(size_t i = 0; i < this->generator->getStabilizators()->size(); ++i) {
        Stabilizator *stab = this->generator->getStabilizators()->at(i);
        stab->stabilize();
    }
}

void GeneratorStage::saveXML(pugi::xml_node &root)
{
    pugi::xml_node thisRoot = root.append_child(GeneratorStage::getRootName());
    thisRoot.append_attribute("stage").set_value(utils::stageGeneratorStagesToStr(this->stage).c_str());
    thisRoot.append_attribute("dice").set_value(this->energyDelivered->toString().c_str());
}

GeneratorStage *GeneratorStage::loadFromXML(const pugi::xml_node &root, StageGenerator *generator)
{
    if(strcmp(root.name(), GeneratorStage::getRootName()) == 0) {

        constants::StageGeneratorStage genStage = utils::strToStageGeneratorStage(root.attribute("stage").as_string());
        DiceExpression *energy = new DiceExpression(root.attribute("dice").as_string());
        GeneratorStage *stage = new GeneratorStage(genStage, energy, generator);
        generator->addStage(stage);
        return stage;
    }
    else if(strcmp(root.name(), StoppedGeneratorStage::getRootName()) == 0) {
        return StoppedGeneratorStage::loadFromXML(root, generator);
    }
    else {
        throw XMLException("Wrong node to load for GeneratorStage : " + std::string(root.name()));
    }
}

const char *GeneratorStage::getRootName()
{
    return rootName;
}
