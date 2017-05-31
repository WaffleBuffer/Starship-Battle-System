#ifndef SHIPEXCEPTION_H
#define SHIPEXCEPTION_H

/**
 * @file shipexception
 */

#include <stdexcept>
#include <string>

class IShip;

/**
 * @brief The ShipException class. An exception from a particular ship.
 */
class ShipException: public std::exception
{
public:
    /**
     * @brief ShipException Default constructor.
     */
    ShipException();
    /**
     * @brief ShipException The constructor
     * @param msg The error message.
     * @param ship The ship involved.
     */
    ShipException(const std::string & msg, IShip *ship);
    /**
     * @brief ShipException The constructor
     * @param msg The error message.
     * @param ship The ship involved.
     */
    ShipException(const char* msg, IShip *ship);
    virtual ~ShipException() {}
    /**
     * @brief what Get what happened.
     * @return The error message.
     */
    virtual const char* what() const throw();
private:
    /**
     * @brief msg The error message.
     */
    const std::string msg;
    /**
     * @brief ship The ship involved.
     */
    IShip *ship;
};

#endif // SHIPEXCEPTION_H
