#ifndef BASICEXCEPTON_H
#define BASICEXCEPTON_H

/**
 * @file basicexception.h
 */

#include <stdexcept>
#include <string>

/**
 * @brief The BasicException class. A basic std exception with a message.
 */
class BasicException: public std::exception
{
public:
    /**
     * @brief BasicExcepton Default constructor.
     */
    BasicException();
    /**
     * @brief BasicExcepton Constructor.
     * @param msg The error message
     */
    BasicException(const std::string & msg);
    /**
     * @brief BasicExcepton Constructor.
     * @param msg The error message
     */
    BasicException(const char * msg);
    virtual ~BasicException();
    /**
     * @brief what Get what happened message.
     * @return The error message.
     */
    virtual const char* what() const throw();
    /**
     * @brief getMsg Get the exception message.
     * @return The exception message.
     */
    std::string getMsg() const;

private:
    /**
     * @brief msg The error message.
     */
    const std::string msg;
};

#endif // BASICEXCEPTON_H
