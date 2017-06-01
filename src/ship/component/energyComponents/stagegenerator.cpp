#include "stagegenerator.h"

#include "../../iship.h"
#include "../../../utils/myobject.h"
#include "../../damage.h"
#include "../../../utils/weaponattack.h"
#include "../weapons/torpedo.h"
#include "stabilizator.h"
#include "../../../exception/shipexception.h"

StageGenerator::StageGenerator(const std::string & name, const std::string & description, IShip *ship)
    :AbstractGenerator(name, description, ship), stabilizators(new std::vector<Stabilizator*>()){

    this->stages = new std::vector<GeneratorStage*>();
    this->currentStage = nullptr;
    this->currentStageIndex = 0;
}

StageGenerator::StageGenerator(StageGenerator *model)
    :AbstractGenerator(model->getName(), model->getDescription(), nullptr), currentStage(nullptr), currentStageIndex(0), stages(new std::vector<GeneratorStage*>()),
    stabilizators(new std::vector<Stabilizator*>()){

    for(size_t i = 0; i < model->stages->size(); ++i) {
        GeneratorStage *stage = new GeneratorStage(model->stages->at(i), this);
        this->addStage(stage);
    }
    for(size_t i = 0; i < model->stabilizators->size(); ++i) {
        Stabilizator *stabilizator = new Stabilizator(model->stabilizators->at(i));
        this->addStabilizator(stabilizator);
    }
}

StageGenerator::~StageGenerator()
{
    for(size_t i = 0; i < this->stages->size(); ++i) {
        delete(this->stages->at(i));
    }
    delete(this->stages);

    for(size_t i = 0; i < this->stabilizators->size(); ++i) {
        delete(this->stabilizators->at(i));
    }
    delete(this->stabilizators);
}

int StageGenerator::generateEnergy()
{
    int energy = 0;

    if(this->currentStage != nullptr) {
        energy = this->currentStage->generateEnergy();
    }
    return energy;
}

std::string StageGenerator::toString()
{
    std::string res = "";
    res += this->getName() + " : " + this->currentStage->toString() + "\n";
    for(size_t i = 0; i < this->stabilizators->size(); ++i) {
        res += "    " + this->stabilizators->at(i)->toString() + "\n";
    }

    return res;
}

void StageGenerator::addStage(GeneratorStage *stage)
{
    this->stages->push_back(stage);
    if(this->currentStage == nullptr) {
        this->currentStage = stage;
    }
}

void StageGenerator::getDamaged(Damage *damage)
{

    int nbDestabilizationLvl = 0;

    // Check if hit by a torpedo
    for(size_t i = 0; i < damage->getOrigins()->size(); ++i) {
        WeaponAttack *weaponAt = damage->getOrigins()->at(i);
        Torpedo *torp = dynamic_cast<Torpedo*>(weaponAt->getWeapon());
        // We've been hit by a torpedo
        if(torp != NULL) {
            nbDestabilizationLvl++;
        }
    }

    nbDestabilizationLvl += damage->getCurrentValue() / 3;

    // Destabilization
    if(currentStageIndex + nbDestabilizationLvl > this->stages->size() - 1) {
        this->currentStage = this->stages->at(this->stages->size() - 1);
        this->currentStageIndex = this->stages->size() - 1;
    }
    else {
        this->currentStage = this->stages->at(currentStageIndex + nbDestabilizationLvl);
        this->currentStageIndex = currentStageIndex + nbDestabilizationLvl;
    }
}

void StageGenerator::addStabilizator(Stabilizator *stabilizator)
{
    this->stabilizators->push_back(stabilizator);
    stabilizator->setGenerator(this);
    stabilizator->setShip(this->getShip());
}

GeneratorStage *StageGenerator::getCurrentStage()
{
    return this->currentStage;
}

size_t StageGenerator::getCurrentStageIndex()
{
    return this->currentStageIndex;
}

std::vector<Stabilizator *> *StageGenerator::getStabilizators()
{
    return this->stabilizators;
}

std::vector<GeneratorStage *> *StageGenerator::getStages()
{
    return this->stages;
}

void StageGenerator::setCurrentStage(const int &levelDiff)
{
    if(((int)this->currentStageIndex + levelDiff) < 0 || this->currentStageIndex + levelDiff > this->stages->size()) {
        throw new ShipException("Invalid level difference to set current stage", this->getShip());
    }
    else {
        this->currentStage = this->stages->at(this->currentStageIndex + levelDiff);
        this->currentStageIndex += levelDiff;
    }
}

void StageGenerator::stabilize()
{
    this->currentStage->stabilize();
}
