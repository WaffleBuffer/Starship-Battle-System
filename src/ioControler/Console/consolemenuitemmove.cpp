#include "consolemenuitemmove.h"
#include "../../order/moveorder.h"

#include <iostream>

ConsoleMenuItemMove::ConsoleMenuItemMove(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, MoveOrder *order)
    :ConsoleMenuItem(title, inputWaited, menu), order(order){

}

void ConsoleMenuItemMove::action(std::vector<std::string> *args)
{
    if(args == nullptr || args->size() == 0) {
        std::cout << "Need to provide an argument" << std::endl;
        return;
    }

    // TODO : check input

    // TODO : accept case

    // TODO : cancel case

    // TODO : if correct input, delete this menu item from menu

    // TODO : check if no menu item, end menu.
}
