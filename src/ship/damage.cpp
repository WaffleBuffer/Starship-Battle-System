#include "damage.h"

#include "../utils/weaponattack.h"
#include "../diceExpression/diceexpression.h"
#include "../utils/constants.cpp"

Damage::Damage(const int & baseValue, constants::ShipDirection faceTargeted)
    :baseValue(baseValue), currentValue(baseValue), faceTargeted(faceTargeted), origins(new std::vector<WeaponAttack *>()), rolls(new std::vector<int>()){

}

Damage::~Damage()
{
    delete(this->origins);
    delete(this->rolls);
}

int Damage::getBaseValue() const
{
    return baseValue;
}

int Damage::getCurrentValue() const
{
    return currentValue;
}

void Damage::setCurrentValue(int value)
{
    currentValue = value;
}

constants::ShipDirection Damage::getFaceTargeted() const
{
    return faceTargeted;
}

std::vector<WeaponAttack *> *Damage::getOrigins() const
{
    return origins;
}

void Damage::addOrigin(WeaponAttack *origin)
{
    this->origins->push_back(origin);
}

void Damage::rollDamage()
{
    DiceExpression dice("D6");
    int roll;
    int nbCritical;
    int maxRoll = 0;
    for(size_t i = this->currentValue; i > 0; --i) {
        roll = dice.roll();
        this->rolls->push_back(roll);
        if(roll < constants::criticalDamageRoll) {
            nbCritical++;
        }
        if(roll > maxRoll) {
            maxRoll = roll;
        }
    }

    this->maxRollValue = maxRoll;

    if(nbCritical >= constants::criticalDamageThreshold) {
        this->hasCritical = true;
    }
}

std::vector<int> *Damage::getRolls() const
{
    return rolls;
}

bool Damage::getHasCritical() const
{
    return hasCritical;
}

int Damage::getMaxRollValue() const
{
    return maxRollValue;
}
