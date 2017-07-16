#include "basicexception.h"

BasicException::BasicException()
    :std::exception(), msg(std::string()){

}

BasicException::BasicException(const std::string &msg)
    :std::exception(), msg(msg){

}

BasicException::BasicException(const char *msg)
    :std::exception(), msg(std::string(msg)){

}

BasicException::~BasicException()
{

}

const char *BasicException::what() const throw()
{
    std::string msgToSend = "";
    msgToSend += this->msg;
    return msgToSend.c_str();
}

std::string BasicException::getMsg() const
{
    return msg;
}
