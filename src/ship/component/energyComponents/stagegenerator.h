#ifndef STAGEGENERATOR_H
#define STAGEGENERATOR_H

/**
 * @file stagegenerator.h
 */

#include "abstractgenerator.h"
#include "generatorstage.h"
#include "../../damageable.h"

#include <vector>

class Stabilizator;

/**
 * @brief The StageGenerator class. A generator with a current stage.
 */
class StageGenerator: public AbstractGenerator, public Damageable
{
public:
    /**
     * @brief StageGenerator The constructor.
     * @param name The name.
     * @param description The description.
     * @param ship The ship.
     */
    StageGenerator(const std::string &name, const std::string &description, IShip *ship);
    /**
     * @brief StageGenerator The copy constructor.
     * @param model The model to copy.
     */
    StageGenerator(StageGenerator *model);
    ~StageGenerator();

    /**
     * @brief generateEnergy Make the roll to generate the energy (depending of the current stage).
     * @return
     */
    int generateEnergy() override;
    /**
     * @brief toString Get the string representation.
     * @return The string representation.
     */
    std::string toString() override;

    /**
     * @brief addStage Add a new stage. The must be added in the order of destabilization (last: stopped stage).
     * @param stage The stage to add.
     */
    void addStage(GeneratorStage *stage);
    /**
     * @brief getDamaged Take some damage and destabilize.
     * @param damage The damage taken.
     */
    void getDamaged(Damage *damage) override;
    /**
     * @brief addStabilizator Add a stabilizator to this ship.
     * @param stabilizator The stabilizator to add.
     */
    void addStabilizator(Stabilizator *stabilizator);
    /**
     * @brief getCurrentStage Get the current stage.
     * @return The current stage.
     */
    GeneratorStage *getCurrentStage();
    /**
     * @brief getCurrentStageIndex Get the current stage index in the stages array.
     * @return The current stage index in the stages array.
     */
    size_t getCurrentStageIndex();
    /**
     * @brief getStabilizators Get the stabilizators.
     * @return The stabilizators.
     */
    std::vector<Stabilizator *> *getStabilizators();
    /**
     * @brief getStages Get the stages.
     * @return The stages.
     */
    std::vector<GeneratorStage*> *getStages();
    /**
     * @brief setCurrentStage Change the current stage by a certain level (+1, -1).
     * @param levelDiff The difference of stabilization level.
     */
    void setCurrentStage(const int &levelDiff);
    /**
     * @brief stabilize Try to stabilize this generator.
     */
    void stabilize();

    /**
     * @brief saveXML Save this object in an XML format.
     * @param root The root xml tag that should contain this object.
     */
    void saveXML(pugi::xml_node &root) override;

    /**
     * @brief loadFromXML Create a StageGenerator from an XML node
     * @param root The xml node that should contain the StageGenerator informations.
     * @param ship The ship that will use this StageGenerator.
     * @return The created StageGenerator.
     */
    static StageGenerator*loadFromXML(IShip *ship, const pugi::xml_node &root);

    /**
     * @brief getRootName Get the StageGenerator XML root name.
     * @return The StageGenerator XML root name.
     */
    static const char *getRootName();

private:
    /**
     * @brief currentStage The current stage.
     */
    GeneratorStage* currentStage;
    /**
     * @brief currentStageIndex The index of the current stage in the stages array.
     */
    size_t currentStageIndex;
    /**
     * @brief stages The stages array.
     */
    std::vector<GeneratorStage*> *stages;
    /**
     * @brief stabilizators The stabilizators array.
     */
    std::vector<Stabilizator*> *stabilizators;

    /**
     * @brief rootName The name of the XML root for a StageGenerator
     */
    static const char* rootName;
};

#endif // STAGEGENERATOR_H
