#include "orderexception.h"

#include "../order/shiporder.h"
#include <string>

OrderException::OrderException()
    :BasicException(std::string()), order(nullptr){

}

OrderException::OrderException(const std::string &msg, ShipOrder *order)
    :BasicException(msg), order(order){

}

OrderException::OrderException(const char *msg, ShipOrder *order)
    :BasicException(msg), order(order){
}

OrderException::OrderException(const std::string &msg)
    :BasicException(msg){

}

OrderException::OrderException(const char *msg)
    :BasicException(msg){

}

const char *OrderException::what() const throw()
{
    std::string msgToSend = "";
    if (this->order != nullptr) {
        msgToSend += "Order : \n" + this->order->toString() + "\n";
    }

    msgToSend += this->getMsg();
    return msgToSend.c_str();
}
