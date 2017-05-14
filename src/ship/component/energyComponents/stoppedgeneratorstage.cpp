#include "stoppedgeneratorstage.h"

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
