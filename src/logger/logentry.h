#ifndef LOGENTRY_H
#define LOGENTRY_H

/**
 * @file logentry.h
 */

#include <ctime>
#include <string>

/**
 * @brief The LogEntry class An entry in the game log.
 */
class LogEntry
{
public:
    /**
     * @brief LogEntry The constructor.
     * @param msg The message of the log.
     */
    LogEntry(std::string msg);
    ~LogEntry();
    /**
     * @brief toString Get the string representation of the log entry.
     * @return The string representation of the log entry.
     */
    std::string toString();
private:
    /**
     * @brief msg The message of the log.
     */
    std::string msg;
    /**
     * @brief logTime The date when the log was created.
     */
    struct tm *logTime;
};

#endif // LOGENTRY_H
