#ifndef SHIPEXCEPTION_H
#define SHIPEXCEPTION_H

#include <stdexcept>
#include <string>

class IShip;

class ShipException: public std::exception
{
public:
    ShipException();
    ShipException(const std::string & msg, IShip *ship);
    ShipException(const char* msg, IShip *ship);
    virtual ~ShipException() {}
    virtual const char* what() const throw();
private:
    const std::string msg;
    IShip *ship;
};

#endif // SHIPEXCEPTION_H
