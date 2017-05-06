#ifndef CONSTEXPRESSION_H
#define CONSTEXPRESSION_H

#include "subexpression.h"

class ConstExpression: public SubExpression
{
public:
    ConstExpression(const unsigned & value);
    virtual int roll();
    virtual int getMaxValue();
private:
    unsigned value;
};

#endif // CONSTEXPRESSION_H
