#ifndef GENERATORSTAGE_H
#define GENERATORSTAGE_H

#include "../../utils/constants.cpp"
#include "../../diceExpression/diceexpression.h"
#include "stagegenerator.h"

class GeneratorStage
{
public:
    GeneratorStage(const constants::StageGeneratorStages & stage, DiceExpression *energyDelivered, StageGenerator *generator);
protected:
    constants::StageGeneratorStages stage;
    DiceExpression *energyDelivered;
    StageGenerator *generator;
};

#endif // GENERATORSTAGE_H
