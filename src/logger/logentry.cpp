#include "logentry.h"

LogEntry::LogEntry(std::string msg)
    :msg(msg){

    time_t t = time(0);
    this->logTime = localtime(&t);
}

LogEntry::~LogEntry()
{
    delete(this->logTime);
    // localtime alocate a time_t object statically so no need to delete it
    //delete(this->msg);
}

std::string LogEntry::toString()
{
    std::string msg = "(" + std::to_string(this->logTime->tm_hour) + ":" + std::to_string(this->logTime->tm_min) + ":" + std::to_string(this->logTime->tm_sec) + ") : ";
    msg += this->msg;
    return msg;
}
