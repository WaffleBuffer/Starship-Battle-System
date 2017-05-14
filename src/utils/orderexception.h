#ifndef ORDEREXCEPTION_H
#define ORDEREXCEPTION_H

#include <stdexcept>
#include <string>

class ShipOrder;

class OrderException: public std::exception
{
public:
    OrderException();
    OrderException(const std::string & msg, ShipOrder *order);
    OrderException(const char* msg, ShipOrder *order);
    virtual ~OrderException() {}
    virtual const char* what() const throw();
private:
    const std::string msg;
    ShipOrder *order;
};

#endif // ORDEREXCEPTION_H
