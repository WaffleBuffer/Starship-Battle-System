#include "stopedgeneratorstage.h"

StopedGeneratorStage::StopedGeneratorStage(StageGenerator *generator, DiceExpression *reactivationRoll, int scoreToReactivate)
    :GeneratorStage(constants::STOPPED, new DiceExpression("0"), generator){
    this->reactivationRoll = reactivationRoll;
    this->scoreToReactivate = scoreToReactivate;
}
