#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H

#include "subexpression.h"

#include <string>

using namespace std;

class BinaryOperator: public SubExpression
{
public:
    ~BinaryOperator();
    string getName();
    void setRight(SubExpression *right);
protected:
    string name;
    SubExpression *left;
    SubExpression *right;
};

#endif // BINARYOPERATOR_H
