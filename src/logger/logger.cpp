#include "logger.h"
#include "logentry.h"
#include "../utils/observer.h"

Logger::Logger()
    :entries(new std::vector<LogEntry*>()), observers(new std::vector<Observer*>()){

}

Logger::~Logger()
{
    for (size_t i = 0; i < this->entries->size(); ++i) {
        delete(this->entries->at(i));
    }
    delete(this->entries);

    delete(this->observers);
}

std::vector<LogEntry *> *Logger::getEntries() const
{
    return entries;
}

void Logger::addEntry(LogEntry *entry)
{
    this->entries->push_back(entry);
    for(size_t i = 0; i < this->observers->size(); ++i) {
        this->observers->at(i)->notify(this, entry);
    }
}

std::vector<Observer *> *Logger::getObservers() const
{
    return observers;
}
