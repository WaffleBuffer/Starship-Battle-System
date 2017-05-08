#ifndef STOPEDGENERATORSTAGE_H
#define STOPEDGENERATORSTAGE_H

#include "generatorstage.h"
#include "stagegenerator.h"
#include "../../diceExpression/diceexpression.h"

class StoppedGeneratorStage: public GeneratorStage
{
public:
    StoppedGeneratorStage(StageGenerator *generator, DiceExpression *reactivationRoll, int scoreToReactivate);
private:
    DiceExpression *reactivationRoll;
    int scoreToReactivate;
};

#endif // STOPEDGENERATORSTAGE_H
