#ifndef DICEEXPRESSION_H
#define DICEEXPRESSION_H

#include "subexpression.h"
#include "../utils/utils.cpp"
#include "constexpression.h"
#include "sum.h"
#include "dice.h"

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
    int roll() override;
    int getMaxValue() override;
    std::string toString() override;
private:
    string expression;
    SubExpression *parsedExpression;
};

#endif // DICEEXPRESSION_H
