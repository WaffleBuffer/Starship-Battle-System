#ifndef D6_H
#define D6_H

#include "dice.h"
#include <cstdlib>

class D6: public Dice
{
public:
    D6();
    virtual int roll();
    virtual int getMaxValue();
};

#endif // D6_H
