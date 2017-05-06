#ifndef DICEEXPRESSION_H
#define DICEEXPRESSION_H

#include "subexpression.h"
#include "../utils/utils.cpp"
#include "constexpression.h"
#include "d6.h"
#include "d10.h"
#include "sum.h"

#include <string>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

class DiceExpression: public SubExpression
{
public:
    DiceExpression(const string & expression) throw();
    ~DiceExpression();
    virtual int roll();
    virtual int getMaxValue();
private:
    string expression;
    SubExpression *parsedExpression;
};

#endif // DICEEXPRESSION_H
