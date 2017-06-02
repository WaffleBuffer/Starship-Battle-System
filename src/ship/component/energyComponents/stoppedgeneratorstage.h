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
    /**
     * @brief getRootName Get the StoppedGeneratorStage XML root name.
     * @return The StoppedGeneratorStage XML root name.
     */
    static const char *getRootName();

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    void saveXML(pugi::xml_node &root);

    /**
     * @brief loadFromXML Create a StoppedGeneratorStage from an XML node
     * @param root The xml node that should contain the StoppedGeneratorStage informations.
     * @return The created StoppedGeneratorStage.
     */
    static StoppedGeneratorStage*loadFromXML(const pugi::xml_node &root, StageGenerator *generator);

private:
    /**
     * @brief reactivationRoll The roll used when trying to stabilize the generator at this stage.
     */
    DiceExpression *reactivationRoll;
    /**
     * @brief scoreToReactivate The score the reactivationRoll must do in order to stabilize the generator at this stage.
     */
    int scoreToReactivate;

    /**
     * @brief rootName The name of the XML root for a StoppedGeneratorStage.
     */
    static const char* rootName;
};

#endif // STOPEDGENERATORSTAGE_H
