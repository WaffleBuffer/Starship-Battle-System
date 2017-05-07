#include "generatorstage.h"

GeneratorStage::GeneratorStage(const constants::StageGeneratorStages & stage, DiceExpression *energyDelivered, StageGenerator *generator){
    this->stage = stage;
    this->energyDelivered = energyDelivered;
    this->generator = generator;
}
