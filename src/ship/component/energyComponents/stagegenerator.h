#ifndef STAGEGENERATOR_H
#define STAGEGENERATOR_H

#include "abstractgenerator.h"
#include "generatorstage.h"
#include "../../damageable.h"

#include <vector>

class Stabilizator;

class StageGenerator: public AbstractGenerator, public Damageable
{
public:
    StageGenerator(const std::string &name, const std::string &description, IShip *ship);
    StageGenerator(StageGenerator *model);
    ~StageGenerator();

    int generateEnergy() override;
    std::string toString() override;

    void addStage(GeneratorStage *stage);
    void getDamaged(Damage *damage) override;
    void addStabilizator(Stabilizator *stabilizator);
    GeneratorStage *getCurrentStage();
    size_t getCurrentStageIndex();
    std::vector<Stabilizator *> *getStabilizators();
    std::vector<GeneratorStage*> *getStages();
    void setCurrentStage(const int &levelDiff);
    void stabilize();
private:
    GeneratorStage* currentStage;
    size_t currentStageIndex;
    std::vector<GeneratorStage*> *stages;
    std::vector<Stabilizator*> *stabilizators;
};

#endif // STAGEGENERATOR_H
