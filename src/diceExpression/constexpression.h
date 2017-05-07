#ifndef CONSTEXPRESSION_H
#define CONSTEXPRESSION_H

#include "subexpression.h"

class ConstExpression: public SubExpression
{
public:
    ConstExpression(const unsigned & value, const std::string & name);
    int roll() override;
    int getMaxValue() override;
    std::string toString() override;
private:
    unsigned value;
    std::string name;
};

#endif // CONSTEXPRESSION_H
