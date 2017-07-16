#include "shipexception.h"

#include "../ship/iship.h"

ShipException::ShipException()
    :BasicException(std::string()), ship(nullptr){
}

ShipException::ShipException(const std::string &msg, IShip *ship)
    :BasicException(msg), ship(ship){
}

ShipException::ShipException(const char* msg, IShip *ship)
    :BasicException(std::string(msg)), ship(ship){

}

const char *ShipException::what() const throw()
{
    std::string msgToSend = "";
    if (this->ship != nullptr) {
        msgToSend += "Ship status : \n" + this->ship->toString() + "\n";
    }

    msgToSend += this->getMsg();
    return msgToSend.c_str();
}
