#include "stagegenerator.h"

#include "../iship.h"
#include "../../utils/myobject.h"
#include "../damage.h"
#include "../../utils/weaponattack.h"
#include "weapons/torpedo.h"

StageGenerator::StageGenerator(const std::string & name, const std::string & description, IShip *ship)
    :AbstractGenerator(name, description, ship){

    this->stages = new std::vector<GeneratorStage*>();
    this->currentStage = nullptr;
    this->currentStageIndex = 0;
}

StageGenerator::StageGenerator(StageGenerator *model)
    :AbstractGenerator(model->getName(), model->getDescription(), nullptr), currentStage(nullptr), currentStageIndex(0), stages(new std::vector<GeneratorStage*>()){

    for(size_t i = 0; i < model->stages->size(); ++i) {
        GeneratorStage *stage = new GeneratorStage(model->stages->at(i), this);
        this->addStage(stage);
    }
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
    }
    else {
        this->currentStage = this->stages->at(currentStageIndex + nbDestabilizationLvl);
    }
}
