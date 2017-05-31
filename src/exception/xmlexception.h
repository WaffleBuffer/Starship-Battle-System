#ifndef XMLEXCEPTION_H
#define XMLEXCEPTION_H

/**
 * xmlexception.h
 */

#include <stdexcept>
#include <string>

class XMLException: public std::exception
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
    /**
     * @brief msg The error message.
     */
    const std::string msg;
};

#endif // XMLEXCEPTION_H
