#include "dice.h"

Dice::Dice(const std::string & name, const int & diceValue)
{
    this->name = name;
    this->diceNumber = 1;
    this->diceValue = diceValue;
    this->maxValue = diceValue;
}

int Dice::roll()
{
    int value = 0;

    for(int i = 0; i < this->diceNumber; ++i) {
        value += rand() % this->diceValue + 1;
    }
    this->lastValue = value;
    return value;
}

int Dice::getMaxValue()
{
    return this->maxValue;
}

std::string Dice::toString() {
    return this->name;
}

int Dice::getLastValue() {
    return this->lastValue;
}

void Dice::setDiceNumer(const int & diceNumber)
{
    this->diceNumber = diceNumber;
    this->maxValue = diceNumber * this->diceValue;
}
