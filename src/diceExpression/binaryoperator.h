#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H

#include "subexpression.h"

#include <string>

class BinaryOperator: public SubExpression
{
public:
    ~BinaryOperator();
    std::string toString() override;
    void setRight(SubExpression *right);
protected:
    std::string name;
    SubExpression *left;
    SubExpression *right;
};

#endif // BINARYOPERATOR_H
