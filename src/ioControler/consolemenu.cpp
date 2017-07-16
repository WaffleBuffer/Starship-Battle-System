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
