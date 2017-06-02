#ifndef GENERATORSTAGE_H
#define GENERATORSTAGE_H

/**
 * @file generatorstage.h
 */

#include "../../../utils/constants.cpp"
#include "../../../diceExpression/diceexpression.h"
#include "../../../thirdParty/pugixml-1.8/src/pugixml.hpp"

#include <string>

class StageGenerator;

/**
 * @brief The GeneratorStage class. A stage of a stage generator.
 */
class GeneratorStage
{
public:
    /**
     * @brief GeneratorStage The constructor.
     * @param stage The actual stage type.
     * @param energyDelivered The amount of energy generated.
     * @param generator The generator of this stage.
     */
    GeneratorStage(const constants::StageGeneratorStage & stage, DiceExpression *energyDelivered, StageGenerator *generator);
    /**
     * @brief GeneratorStage The copy constructor (used to construct from models).
     * @param model The model.
     * @param generator The generator using this stage.
     */
    GeneratorStage(GeneratorStage *model, StageGenerator *generator);
    virtual ~GeneratorStage();
    /**
     * @brief generateEnergy Generate the energy
     * @return The energy generated.
     */
    int generateEnergy();
    /**
     * @brief getStage Get the stage type.
     * @return The stage type.
     */
    constants::StageGeneratorStage getStage();
    /**
     * @brief toString Get the string representation.
     * @return The string representation.
     */
    std::string toString();
    /**
     * @brief stabilize Try to stabilize the generator using stabilizators.
     */
    virtual void stabilize();

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    virtual void saveXML(pugi::xml_node &root);

    /**
     * @brief loadFromXML Create a GeneratorStage from an XML node
     * @param root The xml node that should contain the GeneratorStage informations.
     * @return The created GeneratorStage.
     */
    static GeneratorStage*loadFromXML(const pugi::xml_node &root, StageGenerator *generator);
    /**
     * @brief getRootName Get the GeneratorStage XML root name.
     * @return The GeneratorStage XML root name.
     */
    static const char *getRootName();

protected:
    /**
     * @brief stage The stage type.
     */
    constants::StageGeneratorStage stage;
    /**
     * @brief energyDelivered The roll of delivered energy.
     */
    DiceExpression *energyDelivered;
    /**
     * @brief generator The generator using this stage.
     */
    StageGenerator *generator;

    /**
     * @brief rootName The name of the XML root for a GeneratorStage.
     */
    static const char* rootName;
};

#endif // GENERATORSTAGE_H
