#include "consolemenuitemreturn.h"
#include "consolemenu.h"

ConsoleMenuItemReturn::ConsoleMenuItemReturn(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu)
    :ConsoleMenuItem(title, inputWaited, menu){

}

void ConsoleMenuItemReturn::action(std::vector<std::string> *args)
{
    this->getMenu()->setIsOver(true);
}
