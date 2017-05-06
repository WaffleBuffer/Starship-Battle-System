#include "sum.h"

Sum::Sum(SubExpression *left, SubExpression *right)
{
    this->name = "+";
    this->left = left;
    this->right = right;
}

int Sum::roll() {
    return this->left->roll() + this->right->roll();
}

int Sum::getMaxValue() {
    return this->left->getMaxValue() + this->right->getMaxValue();
}
