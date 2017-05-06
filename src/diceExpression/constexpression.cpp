#include "constexpression.h"

ConstExpression::ConstExpression(const unsigned & value)
{
    this->value = value;
}

int ConstExpression::roll() {
    return this->value;
}

int ConstExpression::getMaxValue() {
    return this->value;
}
