#ifndef STOPEDGENERATORSTAGE_H
#define STOPEDGENERATORSTAGE_H

/**
 * @file stoppedgeneratorstage.h
 */

#include "generatorstage.h"
#include "stagegenerator.h"
#include "../../../diceExpression/diceexpression.h"

/**
 * @brief The StoppedGeneratorStage class. A special stage that doesn't generate energy and
 *        that don't need a stabilizator to stabilize (done on a roll).
 */
class StoppedGeneratorStage: public GeneratorStage
{
public:
    /**
     * @brief StoppedGeneratorStage The constructor.
     * @param generator The generator using this stage. It must be added to the generator in last.
     * @param reactivationRoll The roll used when trying to stabilize the generator at this stage.
     * @param scoreToReactivate The score the reactivationRoll must do in order to stabilize the generator at this stage.
     */
    StoppedGeneratorStage(StageGenerator *generator, DiceExpression *reactivationRoll, int scoreToReactivate);
    /**
     * @brief stabilize Do the roll to try to stabilize the generator using this stage.
     */
    void stabilize() override;
private:
    /**
     * @brief reactivationRoll The roll used when trying to stabilize the generator at this stage.
     */
    DiceExpression *reactivationRoll;
    /**
     * @brief scoreToReactivate The score the reactivationRoll must do in order to stabilize the generator at this stage.
     */
    int scoreToReactivate;
};

#endif // STOPEDGENERATORSTAGE_H
