#include "stabilizator.h"

#include "stagegenerator.h"
#include "../../../utils/shipexception.h"

Stabilizator::Stabilizator(const std::string &name, const std::string &description, IShip *ship, const int &maxEnergy, StageGenerator *generator)
    :EnergyProvidable(name, description, ship, maxEnergy), generator(generator){

}

Stabilizator::Stabilizator(Stabilizator *model)
    :EnergyProvidable(model->getName(), model->getDescription(), model->getShip(), model->getMaxEnergy()), generator(model->generator){

}

void Stabilizator::setGenerator(StageGenerator *generator)
{
    this->generator = generator;
}

void Stabilizator::provideEnergy(const int &energy)
{
    this->currentEnergy += energy;
    if(this->currentEnergy > this->getMaxEnergy()) {
        this->currentEnergy = this->currentEnergy;
    }
}

void Stabilizator::stabilize()
{
    if(this->generator == nullptr) {
        throw new ShipException("No generator attached", this->getShip());
    }
    int level = this->generator->getCurrentStageIndex() + 1;
    if(this->currentEnergy < level) {
        return;
    }
    else if(this->generator->getCurrentStageIndex() == 0){
        return;
    }
    else {
        this->generator->setCurrentStage(-1);
    }
}
