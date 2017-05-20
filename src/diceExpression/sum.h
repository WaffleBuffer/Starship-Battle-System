#ifndef SUM_H
#define SUM_H

/**
 * @file sum.h
 */

#include "binaryoperator.h"

/**
 * @brief The Sum class.[see BinaryOperator](@ref BinaryOperator).
 */
class Sum: public BinaryOperator
{
public:
    /**
     * @brief Sum The constructor.
     * @param left The left operand.
     * @param right The right operand
     */
    Sum(SubExpression *left, SubExpression *right);
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
};

#endif // SUM_H
