#ifndef BINARYOPERATOR_H
#define BINARYOPERATOR_H
/**
 * @file binaryoperator.h
 */

#include "subexpression.h"

#include <string>

/**
 * @brief The BinaryOperator class.[see SubExpression](@ref SubExpression). Binary operator between two [SubExpression](@ref SubExpression).
 *        This class is abstract.
 */
class BinaryOperator: public SubExpression
{
public:
    /**
     * @brief ~BinaryOperator
     */
    virtual ~BinaryOperator();
    /**
     * @brief toString [see SubExpression](@ref SubExpression). Get the string representation of this expression.
     * @return The string representation of this expression.
     */
    std::string toString() override;
    /**
     * @brief setRight Set the right operand.
     * @param right The right operand to set.
     */
    void setRight(SubExpression *right);
protected:
    /**
     * @brief name The string representation of the operator
     */
    std::string name;
    /**
     * @brief left The left operand.
     */
    SubExpression *left;
    /**
     * @brief right The right operand.
     */
    SubExpression *right;
};

#endif // BINARYOPERATOR_H
