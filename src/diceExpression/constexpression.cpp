#include "constexpression.h"

ConstExpression::ConstExpression(const unsigned & value, const std::string & name)
{
    this->value = value;
    this->name = name;
}

int ConstExpression::roll() {
    return this->value;
}

int ConstExpression::getMaxValue() {
    return this->value;
}

std::string ConstExpression::toString()
{
    return this->name;
}
