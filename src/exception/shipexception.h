#ifndef SHIPEXCEPTION_H
#define SHIPEXCEPTION_H

/**
 * @file shipexception
 */

#include "basicexception.h"
#include <string>

class IShip;

/**
 * @brief The ShipException class. An exception caused by a particular ship.
 */
class ShipException: public BasicException
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
     * @brief ship The ship involved.
     */
    IShip *ship;
};

#endif // SHIPEXCEPTION_H
