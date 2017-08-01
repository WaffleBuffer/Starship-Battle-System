#include "consolemenu.h"
#include "consolemenuitem.h"

ConsoleMenu::ConsoleMenu(const std::string &title)
    :menuItems(new std::vector<ConsoleMenuItem*>()), title(title){

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

bool ConsoleMenu::checkInput(const std::string &input)
{
    for (size_t i = 0; i < this->menuItems->size(); ++i) {
        if(this->menuItems->at(i)->checkInput(input)) {
            std::vector<std::string> args;
            args.push_back(input);
            this->menuItems->at(i)->action(&args);
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
