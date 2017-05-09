#include "shipexception.h"

#include "../ship/iship.h"

ShipException::ShipException()
    :std::exception(), msg(std::string()), ship(nullptr){
}

ShipException::ShipException(const std::string &msg, IShip *ship)
    :std::exception(), msg(msg), ship(ship){
}

ShipException::ShipException(const char* msg, IShip *ship)
    :std::exception(), msg(msg), ship(ship){

}

const char *ShipException::what() const throw()
{
    std::string msg = std::string();
    if (this->ship != nullptr) {
        msg += this->ship->toString() + "\n";
    }

    msg += this->msg;
    return msg.c_str();
}
