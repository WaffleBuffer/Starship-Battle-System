#include "xmlexception.h"

XMLException::XMLException()
    :std::exception(), msg(std::string()){
}

XMLException::XMLException(const std::string &msg)
    :std::exception(), msg(msg){
}

XMLException::XMLException(const char* msg)
    :std::exception(), msg(msg){

}

const char *XMLException::what() const throw()
{
    return this->msg.c_str();
}
