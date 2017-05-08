#include "stagegenerator.h"

StageGenerator::StageGenerator(const std::string & name, const std::string & description, IShip *ship)
    :AbstractGenerator(name, description, ship){

    this->stages = new std::vector<GeneratorStage*>;
    this->currentStage = nullptr;
}

StageGenerator::~StageGenerator()
{
    for(size_t i = 0; i < this->stages->size(); ++i) {
        delete(this->stages->at(i));
    }

    delete(this->stages);
}

int StageGenerator::generateEnergy()
{
    int energy = 0;

    if(this->currentStage != nullptr) {
        energy = this->currentStage->generateEnergy();
    }
    return energy;
}

string StageGenerator::toString()
{
    std::string res = "";
    res += this->getName() + " : " + this->currentStage->toString();

    return res;
}

void StageGenerator::addStage(GeneratorStage *stage)
{
    this->stages->push_back(stage);
    if(this->currentStage == nullptr) {
        this->currentStage = stage;
    }
}
