#include "orderexception.h"

#include "../order/shiporder.h"
#include <string>

OrderException::OrderException()
    :std::exception(), msg(std::string()), order(nullptr){

}

OrderException::OrderException(const std::string &msg, ShipOrder *order)
    :std::exception(), msg(msg), order(order){

}

OrderException::OrderException(const char *msg, ShipOrder *order)
    :std::exception(), msg(msg), order(order){
}

const char *OrderException::what() const throw()
{
    std::string msgToSend = "";
    if (this->order != nullptr) {
        msgToSend += "Order : \n" + this->order->toString() + "\n";
    }

    msgToSend += this->msg;
    return msgToSend.c_str();
}
