#include "stoppedgeneratorstage.h"

StoppedGeneratorStage::StoppedGeneratorStage(StageGenerator *generator, DiceExpression *reactivationRoll, int scoreToReactivate)
    :GeneratorStage(constants::STOPPED, new DiceExpression("0"), generator){
    this->reactivationRoll = reactivationRoll;
    this->scoreToReactivate = scoreToReactivate;
}
