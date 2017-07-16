#include "consolemenuitem.h"

ConsoleMenuItem::ConsoleMenuItem(const std::string &title, const std::string &inputWaited)
    :title(title), inputWaited(inputWaited){

}

ConsoleMenuItem::~ConsoleMenuItem()
{

}

std::string ConsoleMenuItem::toString()
{
    std::string res = this->title + " : " + this->inputWaited;
    return res;
}
