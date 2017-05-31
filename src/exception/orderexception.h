#ifndef ORDEREXCEPTION_H
#define ORDEREXCEPTION_H

/**
 * @file orderexception.h
 */

#include <stdexcept>
#include <string>

class ShipOrder;

/**
 * @brief The OrderException class. An exception of an order.
 */
class OrderException: public std::exception
{
public:
    /**
     * @brief OrderException Default constructor.
     */
    OrderException();
    /**
     * @brief OrderException Constructor.
     * @param msg The error message
     * @param order The order involved
     */
    OrderException(const std::string & msg, ShipOrder *order);
    /**
     * @brief OrderException Constructor.
     * @param msg The error message
     * @param order The order involved
     */
    OrderException(const char* msg, ShipOrder *order);
    virtual ~OrderException() {}
    /**
     * @brief what Get what happened message.
     * @return The error message.
     */
    virtual const char* what() const throw();
private:
    /**
     * @brief msg The error message.
     */
    const std::string msg;
    /**
     * @brief order The order involved.
     */
    ShipOrder *order;
};

#endif // ORDEREXCEPTION_H
