#include "generatorstage.h"

#include "stagegenerator.h"
#include "../../../utils/utils.cpp"
#include "stabilizator.h"

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
    res += utils::StageGeneratorStagesToStr(this->stage) + " " + this->energyDelivered->toString();
    return res;
}

void GeneratorStage::stabilize()
{
    for(size_t i = 0; i < this->generator->getStabilizators()->size(); ++i) {
        Stabilizator *stab = this->generator->getStabilizators()->at(i);
        stab->stabilize();
    }
}
