#ifndef DICEEXPRESSION_H
#define DICEEXPRESSION_H

/**
 * @file diceexpression.h
 */

#include "subexpression.h"
#include "../utils/utils.cpp"
#include "constexpression.h"
#include "sum.h"
#include "dice.h"

#include <string>
#include <sstream>
#include <cstdlib>
#include <stdexcept>

/**
 * @brief The DiceExpression class. Represent a formula with dice wich is like "2D12 + 3".
 *        Note the space between each element.
 *        Currently supported: - any dice : "4D7"
 *                             - any constant : "48"
 *                             - sum : "1 + 2"
 *        [see SubExpression](@ref SubExpression).
 */
class DiceExpression: public SubExpression
{
public:
    /**
     * @brief DiceExpression The constructor.
     * @param expression The string expression : "5 + 2D6"
     */
    DiceExpression(const std::string & expression) throw();
    ~DiceExpression();
    /**
     * @brief roll [see SubExpression](@ref SubExpression). Get a possible value of the expression.
     * @return The rolled value.
     */
    int roll() override;
    /**
     * @brief getMaxValue [see SubExpression](@ref SubExpression). Get the maximum possible value.
     * @return The maximum possible value
     */
    int getMaxValue() override;
    /**
     * @brief toString [see SubExpression](@ref SubExpression). Get the string representation of this expression.
     * @return The string representation of this expression.
     */
    std::string toString() override;
private:
    /**
     * @brief expression The string expression
     */
    std::string expression;
    /**
     * @brief parsedExpression The parsed expression.
     */
    SubExpression *parsedExpression;
};

#endif // DICEEXPRESSION_H
