#ifndef GENERATORSTAGE_H
#define GENERATORSTAGE_H

#include "../../../utils/constants.cpp"
#include "../../../diceExpression/diceexpression.h"

#include <string>

class StageGenerator;

class GeneratorStage
{
public:
    GeneratorStage(const constants::StageGeneratorStage & stage, DiceExpression *energyDelivered, StageGenerator *generator);
    GeneratorStage(GeneratorStage *model, StageGenerator *generator);
    virtual ~GeneratorStage();
    int generateEnergy();
    constants::StageGeneratorStage getStage();
    std::string toString();
    virtual void stabilize();
protected:
    constants::StageGeneratorStage stage;
    DiceExpression *energyDelivered;
    StageGenerator *generator;
};

#endif // GENERATORSTAGE_H
