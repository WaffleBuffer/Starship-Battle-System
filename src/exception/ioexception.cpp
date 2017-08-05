#include "ioexception.h"

IOException::IOException(const bool &isFatal)
    :BasicException(), isFatal(isFatal){

}

IOException::IOException(const std::string &msg, const bool &isFatal)
    :BasicException(msg), isFatal(isFatal){

}

IOException::IOException(const char *msg, const bool &isFatal)
    :BasicException(msg), isFatal(isFatal){

}

bool IOException::getIsFatal() const
{
    return isFatal;
}
