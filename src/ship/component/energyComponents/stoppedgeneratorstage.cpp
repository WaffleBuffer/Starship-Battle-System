#include "stoppedgeneratorstage.h"

#include "../../../exception/xmlexception.h"
#include "stoppedgeneratorstage.h"
#include <string.h>

const char* StoppedGeneratorStage::rootName = "stoppedgenerator_stage";

StoppedGeneratorStage::StoppedGeneratorStage(StageGenerator *generator, DiceExpression *reactivationRoll, int scoreToReactivate)
    :GeneratorStage(constants::STOPPED, new DiceExpression("0"), generator){
    this->reactivationRoll = reactivationRoll;
    this->scoreToReactivate = scoreToReactivate;
}

void StoppedGeneratorStage::stabilize()
{
    int rollRes = this->reactivationRoll->roll();
    if(rollRes >= this->scoreToReactivate) {
        this->generator->setCurrentStage(-1);
    }
}

const char *StoppedGeneratorStage::getRootName()
{
    return rootName;
}

void StoppedGeneratorStage::saveXML(pugi::xml_node &root)
{
    pugi::xml_node thisRoot = root.append_child(StoppedGeneratorStage::getRootName());
    thisRoot.append_attribute("dice").set_value(this->reactivationRoll->toString().c_str());
    thisRoot.append_attribute("score").set_value(std::to_string(this->scoreToReactivate).c_str());
}

StoppedGeneratorStage *StoppedGeneratorStage::loadFromXML(const pugi::xml_node &root, StageGenerator *generator)
{
    if(strcmp(root.name(), StoppedGeneratorStage::getRootName()) != 0) {
        throw XMLException("Wrong node to load for StoppedGeneratorStage : " + std::string(root.name()));
    }
    DiceExpression *reactivation = new DiceExpression(root.attribute("dice").as_string());
    int score = root.attribute("score").as_int();
    StoppedGeneratorStage *stage = new StoppedGeneratorStage(generator, reactivation, score);
    generator->addStage(stage);
    return stage;
}

