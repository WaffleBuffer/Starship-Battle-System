#ifndef SUBEXPRESSION_H
#define SUBEXPRESSION_H

/**
 * @file subexpression.h
 */

#include <string>

/**
 * @brief A SubExpression is used in [DiceExpression](@ref DiceExpression). This class is pure virtual.
 */
class SubExpression
{
public:
    /**
     * @brief ~SubExpression
     */
    virtual ~SubExpression() {}
    /**
     * @brief roll Get a possible value of the expression.
     * @return The rolled value.
     */
    virtual int roll() = 0;
    /**
     * @brief getMaxValue Get the maximum possible value.
     * @return The maximum possible value
     */
    virtual int getMaxValue() = 0;
    /**
     * @brief toString Get the string representation of this expression.
     * @return The string representation of this expression.
     */
    virtual std::string toString() = 0;
private:

};

#endif // SUBEXPRESSION_H
