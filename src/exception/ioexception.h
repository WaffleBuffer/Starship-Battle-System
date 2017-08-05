#ifndef IOEXCEPTION_H
#define IOEXCEPTION_H

#include "basicexception.h"

/**
 * @brief The IOException class. An exception generaly caused by the interaction with the user. Also it is generaly not a fatal exception.
 */
class IOException: public BasicException
{
public:
    /**
     * @brief IOException Default constructor.
     * @param isFatal Is the exception fatal
     */
    IOException(const bool &isFatal);
    /**
     * @brief IOException Constructor.
     * @param msg The error message
     * @param isFatal Is the exception fatal
     */
    IOException(const std::string & msg, const bool &isFatal);
    /**
     * @brief IOException Constructor.
     * @param msg The error message
     * @param isFatal Is the exception fatal
     */
    IOException(const char * msg, const bool &isFatal);
    bool getIsFatal() const;

private:
    /**
     * @brief isFatal Is the exception fatal
     */
    bool isFatal;
};

#endif // IOEXCEPTION_H
