#include "xmlexception.h"

XMLException::XMLException()
    :BasicException(){
}

XMLException::XMLException(const std::string &msg)
    :BasicException(msg){
}

XMLException::XMLException(const char* msg)
    :BasicException(std::string(msg)){

}

const char *XMLException::what() const throw()
{
    return this->getMsg().c_str();
}
