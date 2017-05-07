#ifndef SUBEXPRESSION_H
#define SUBEXPRESSION_H

#include <string>

class SubExpression
{
public:
    virtual ~SubExpression() {}
    virtual int roll() = 0;
    virtual int getMaxValue() = 0;
    virtual std::string toString() = 0;
private:

};

#endif // SUBEXPRESSION_H
