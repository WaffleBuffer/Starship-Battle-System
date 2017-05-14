#ifndef STABILIZATOR_H
#define STABILIZATOR_H

#include "../energyprovidable.h"

class StageGenerator;

class Stabilizator: public EnergyProvidable
{
public:
    Stabilizator(const std::string & name, const std::string & description, IShip *ship, const int &maxEnergy, StageGenerator *generator);
    Stabilizator(Stabilizator *model);
    void setGenerator(StageGenerator *generator);
    void provideEnergy(const int & energy) override;
    void stabilize();
private:
    StageGenerator *generator;
    int currentEnergy;
};

#endif // STABILIZATOR_H
