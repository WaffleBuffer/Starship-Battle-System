#ifndef DICE_H
#define DICE_H

#include "subexpression.h"

#include <string>

using namespace std;

class Dice: public SubExpression
{
public:
    Dice();
    string getName();
    int getLastValue();
protected:
    string name;
    int lastValue;
};

#endif // DICE_H
