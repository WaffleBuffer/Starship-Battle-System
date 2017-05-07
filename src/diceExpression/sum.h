#ifndef SUM_H
#define SUM_H

#include "binaryoperator.h"

class Sum: public BinaryOperator
{
public:
    Sum(SubExpression *left, SubExpression *right);
    int roll() override;
    int getMaxValue() override;
};

#endif // SUM_H
