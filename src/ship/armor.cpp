#include "armor.h"

#include "../ship/damage.h"
#include "iship.h"

Armor::Armor(const int &bowMax, const int &starMax, const int &sternMax, const int &portMax)
    :AbstractComponent("", "", nullptr), bowMax(bowMax), bowCurrentValue(bowMax), starBoardMax(starMax), starBoardCurrentValue(starMax),
     sternMax(sternMax), sternCurrentValue(sternMax), portMax(portMax), portCurrentValue(portMax){

}

void Armor::notify(Observable *origin, MyObject *arg)
{
    IShip *ship = dynamic_cast<IShip*> (origin);
    if(ship == NULL) {
        return;
    }
    Damage *damageTaken = dynamic_cast<Damage*>(arg);
    if(damageTaken == NULL) {
        return;
    }

    switch (damageTaken->getFaceTargeted()) {
    case constants::BOW:
        damageTaken->setCurrentValue(damageTaken->getCurrentValue() - this->bowCurrentValue);
        // In new rules there is no more armor degradation
        /*if(this->bowCurrentValue > 0)
            this->bowCurrentValue--;*/
        break;
    case constants::STARBOARD:
        damageTaken->setCurrentValue(damageTaken->getCurrentValue() - this->starBoardCurrentValue);
        /*if(this->starBoardCurrentValue > 0)
            this->starBoardCurrentValue--;*/
        break;
    case constants::STERN:
        damageTaken->setCurrentValue(damageTaken->getCurrentValue() - this->sternCurrentValue);
        /*if(this->sternCurrentValue > 0)
            this->sternCurrentValue--;*/
        break;
    case constants::PORT:
        damageTaken->setCurrentValue(damageTaken->getCurrentValue() - this->portCurrentValue);
        /*if(this->portCurrentValue > 0)
            this->portCurrentValue--;*/
        break;
    }

}

std::string Armor::toString()
{
    std::string res = "";
    res += "{" + std::to_string(this->bowCurrentValue) + ", " + std::to_string(this->starBoardCurrentValue) +
           ", " + std::to_string(this->sternCurrentValue) + ", " + std::to_string(this->portCurrentValue) + "}";
    return res;
}
