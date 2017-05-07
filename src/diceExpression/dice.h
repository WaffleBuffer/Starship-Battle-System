#ifndef DICE_H
#define DICE_H

#include "subexpression.h"

#include <string>

class Dice: public SubExpression
{
public:
    Dice(const std::string & name, const int & diceValue);
    int roll() override;
    int getMaxValue() override;
    std::string toString() override;
    int getLastValue();
    void setDiceNumer(const int & diceNumber);
private:
    std::string name;
    int lastValue;
    int diceValue;
    int maxValue;
    int diceNumber;
};

#endif // DICE_H
