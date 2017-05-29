#include "hull.h"

#include "hulllevel.h"
#include "iship.h"
#include "damage.h"

Hull::Hull(IShip *ship, std::vector<HullLevel *> *hullLevels)
    :AbstractComponent("", "", ship), hullLevels(hullLevels), currentLevel(hullLevels->at(0)), currentLevelIndex(0){
}

Hull::~Hull()
{
    for(size_t i = 0; i < this->hullLevels->size(); ++i) {
        delete(this->hullLevels->at(i));
    }
    delete(this->hullLevels);
}

std::string Hull::toString()
{
    std::string res = "";
    for(size_t i = 0; i < this->hullLevels->size(); ++i) {
        if(this->currentLevelIndex == i) {
            res += " [(" + std::to_string(this->hullLevels->size() - i) + ", " + this->hullLevels->at(i)->toString() + ")] |";
        }
        else {
            res += " (" + std::to_string(this->hullLevels->size() - i) + ", " + this->hullLevels->at(i)->toString() + ") |";
        }

    }
    return res;
}

void Hull::notify(Observable *origin, MyObject *arg)
{
    IShip *ship = dynamic_cast<IShip*> (origin);
    if(ship == NULL) {
        return;
    }
    Damage *damage = dynamic_cast<Damage*>(arg);
    if(damage == NULL) {
        return;
    }

    if(damage->getMaxRollValue() >= this->currentLevel->getHullQuality()) {
        this->deteriorateHull();
    }
}

void Hull::deteriorateHull()
{
    if(this->currentLevelIndex == this->hullLevels->size() - 1) {
        this->getShip()->destroy();
    }
    else {
        this->currentLevelIndex++;
        this->currentLevel = this->hullLevels->at(this->currentLevelIndex);
    }
}
