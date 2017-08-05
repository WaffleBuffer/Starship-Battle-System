#include "consolemenuitem.h"

ConsoleMenuItem::ConsoleMenuItem(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu)
    :title(title), inputWaited(inputWaited), menu(menu){

}

ConsoleMenuItem::~ConsoleMenuItem()
{

}

std::string ConsoleMenuItem::toString()
{
    std::string res = this->title + " : " + this->inputWaited;
    return res;
}

bool ConsoleMenuItem::checkInput(const std::string &input)
{
    return input == this->inputWaited;
}

ConsoleMenu *ConsoleMenuItem::getMenu() const
{
    return menu;
}
