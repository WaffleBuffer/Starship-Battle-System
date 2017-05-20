#ifndef DICE_H
#define DICE_H

/**
 * @file dice.h
 */

#include "subexpression.h"

#include <string>

/**
 * @brief The Dice class A dice in a [SubExpression](@ref SubExpression)
 */
class Dice: public SubExpression
{
public:
    /**
     * @brief Dice The constructor.
     * @param name The string representation.
     * @param diceValue The maximum value of the dice
     */
    Dice(const std::string & name, const int & diceValue);
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
    /**
     * @brief getLastValue Get the last rolled value.
     * @return The last rolled value
     */
    int getLastValue();
    /**
     * @brief setDiceNumer Set the number of dice per roll.
     * @param diceNumber The number of dice per roll.
     */
    void setDiceNumer(const int & diceNumber);
private:
    /**
     * @brief name The string representation
     */
    std::string name;
    /**
     * @brief lastValue The last value rolled.
     */
    int lastValue;
    /**
     * @brief diceValue The maximum value of one dice
     */
    int diceValue;
    /**
     * @brief maxValue The maximum value that can be rolled.
     */
    int maxValue;
    /**
     * @brief diceNumber The number of dice per roll.
     */
    int diceNumber;
};

#endif // DICE_H
