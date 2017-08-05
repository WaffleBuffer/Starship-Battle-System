#include "consolemenu.h"
#include "consolemenuitem.h"

ConsoleMenu::ConsoleMenu(const std::string &title)
    :menuItems(new std::vector<ConsoleMenuItem*>()), title(title), isOver(false){

}

ConsoleMenu::~ConsoleMenu()
{
    for(size_t i = 0; i < this->menuItems->size(); ++i) {
        delete(this->menuItems->at(i));
    }
    delete(this->menuItems);
}

std::vector<ConsoleMenuItem *> *ConsoleMenu::getMenuItems() const
{
    return menuItems;
}

bool ConsoleMenu::checkInput(const std::string &input, std::vector<std::string> *args)
{
    for (size_t i = 0; i < this->menuItems->size(); ++i) {
        if(this->menuItems->at(i)->checkInput(input)) {
            this->menuItems->at(i)->action(args);
            return true;
        }
    }
    return false;
}

std::string ConsoleMenu::toString()
{
    std::string res = this->title + "\n";
    for (size_t i = 0; i < this->menuItems->size(); ++i) {
        res += this->menuItems->at(i)->toString() + "\n";
    }
    return res;
}

bool ConsoleMenu::getIsOver() const
{
    return isOver;
}

void ConsoleMenu::setIsOver(bool value)
{
    isOver = value;
}
