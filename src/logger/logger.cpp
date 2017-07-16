#include "logger.h"
#include "logentry.h"

Logger::Logger()
    :entries(new std::vector<LogEntry*>()){

}

Logger::~Logger()
{
    for (size_t i = 0; i < this->entries->size(); ++i) {
        delete(this->entries->at(i));
    }
    delete(this->entries);
}

std::vector<LogEntry *> *Logger::getEntries() const
{
    return entries;
}

void Logger::addEntry(LogEntry *entry)
{
    this->entries->push_back(entry);
}
