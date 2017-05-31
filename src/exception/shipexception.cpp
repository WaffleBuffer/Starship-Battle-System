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
    std::string msgToSend = "";
    if (this->ship != nullptr) {
        msgToSend += "Ship status : \n" + this->ship->toString() + "\n";
    }

    msgToSend += this->msg;
    return msgToSend.c_str();
}
