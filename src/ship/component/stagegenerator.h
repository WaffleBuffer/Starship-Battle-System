#ifndef STAGEGENERATOR_H
#define STAGEGENERATOR_H

#include "abstractgenerator.h"
#include "generatorstage.h"

#include <vector>

class StageGenerator: public AbstractGenerator
{
public:
    StageGenerator(const std::string &name, const std::string &description, IShip *ship);
    ~StageGenerator();

    int generateEnergy() override;
    std::string toString() override;

    void addStage(GeneratorStage *stage);

private:
    GeneratorStage* currentStage;
    std::vector<GeneratorStage*> *stages;
};

#endif // STAGEGENERATOR_H
