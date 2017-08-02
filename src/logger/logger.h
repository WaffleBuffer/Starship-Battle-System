#ifndef LOGGER_H
#define LOGGER_H

/**
 * @file logger.h
 */

#include "../utils/observable.h"
#include <vector>

class LogEntry;
class Observer;

/**
 * @brief The Logger class The log controller.
 */
class Logger: public Observable
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
    /**
     * @brief getObservers Get the observers.
     * @return The observers.
     */
    std::vector<Observer *> *getObservers() const;

private:
    /**
     * @brief entries All the entries of this logger.
     */
    std::vector<LogEntry*> *entries;

    /**
     * @brief observers The observers of this logger.
     */
    std::vector<Observer*> *observers;
};

#endif // LOGGER_H
