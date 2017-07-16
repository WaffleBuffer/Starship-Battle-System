#ifndef XMLEXCEPTION_H
#define XMLEXCEPTION_H

/**
 * xmlexception.h
 */

#include "basicexception.h"
#include <string>

class XMLException: public BasicException
{
public:
    /**
     * @brief xmlException Default constructor.
     */
    XMLException();
    /**
     * @brief xmlException The constructor
     * @param msg The error message.
     */
    XMLException(const std::string & msg);
    /**
     * @brief xmlException The constructor
     * @param msg The error message.
     */
    XMLException(const char* msg);
    virtual ~XMLException() {}
    /**
     * @brief what Get what happened.
     * @return The error message.
     */
    virtual const char* what() const throw();

private:
};

#endif // XMLEXCEPTION_H
