#ifndef SUM_H
#define SUM_H

#include "binaryoperator.h"

class Sum: public BinaryOperator
{
public:
    Sum(SubExpression *left, SubExpression *right);
    virtual int roll();
    virtual int getMaxValue();
};

#endif // SUM_H
