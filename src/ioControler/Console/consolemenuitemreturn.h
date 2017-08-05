#ifndef CONSOLEMENUITEMRETURN_H
#define CONSOLEMENUITEMRETURN_H

#include "consolemenuitem.h"

class ConsoleMenuItemReturn: public ConsoleMenuItem
{
public:
    /**
     * @brief ConsoleMenuItem The constructor.
     * @param title The title of this menu item.
     * @param inputWaited The input waited to trigger this menu item.
     */
    ConsoleMenuItemReturn(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu);

    /**
     * @brief action The methode used when the menu item is triggered. Here it will just end the menu.
     * @param args The argument provided with the input (if there are some). Useless here.
     */
    virtual void action(std::vector<std::string> *args = nullptr);
private:

};

#endif // CONSOLEMENUITEMRETURN_H
