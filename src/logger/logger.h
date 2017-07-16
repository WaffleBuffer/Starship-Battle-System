#ifndef LOGGER_H
#define LOGGER_H

/**
 * @file logger.h
 */

#include <vector>

class LogEntry;

/**
 * @brief The Logger class The log controller.
 */
class Logger
{
public:
    /**
     * @brief Logger The constructor.
     */
    Logger();
    ~Logger();
    /**
     * @brief getEntries Get all the entries of this logger.
     * @return All the entries of this logger.
     */
    std::vector<LogEntry *> *getEntries() const;
    /**
     * @brief addEntry Add a new entry.
     * @param entry The entry to add.
     */
    void addEntry(LogEntry *entry);
private:
    /**
     * @brief entries All the entries of this logger.
     */
    std::vector<LogEntry*> *entries;
};

#endif // LOGGER_H
