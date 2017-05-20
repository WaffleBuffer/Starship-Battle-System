#ifndef CONSTEXPRESSION_H
#define CONSTEXPRESSION_H

/**
 * @file constexpression.h
 */

#include "subexpression.h"

/**
 * @brief The ConstExpression class. Represent a constant.
 */
class ConstExpression: public SubExpression
{
public:
    /**
     * @brief ConstExpression The constructor.
     * @param value The constant value
     * @param name The string representation of the constant
     */
    ConstExpression(const unsigned & value, const std::string & name);
    /**
     * @brief roll [see SubExpression](@ref SubExpression). Get the constant value
     * @return The constant value
     */
    int roll() override;
    /**
     * @brief getMaxValue [see SubExpression](@ref SubExpression). Get the constant value
     * @return The constant value
     */
    int getMaxValue() override;
    /**
     * @brief toString [see SubExpression](@ref SubExpression). Get the string representation of this expression.
     * @return The string representation of this expression.
     */
    std::string toString() override;
private:
    /**
     * @brief value The constant value.
     */
    unsigned value;
    /**
     * @brief name The string representation.
     */
    std::string name;
};

#endif // CONSTEXPRESSION_H
