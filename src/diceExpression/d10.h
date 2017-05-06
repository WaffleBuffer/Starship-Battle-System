#ifndef D10_H
#define D10_H

#include "dice.h"
#include <cstdlib>

class D10: public Dice
{
public:
    D10();
    virtual int roll();
    virtual int getMaxValue();
};

#endif // D10_H
