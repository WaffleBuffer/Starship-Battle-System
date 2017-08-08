#ifndef CONSOLEMENUITEMMOVE_H
#define CONSOLEMENUITEMMOVE_H

#include "consolemenuitem.h"

#include <string>

class ConsoleMenu;
class MoveOrder;

class ConsoleMenuItemMove: public ConsoleMenuItem
{
public:
    /**
     * @brief ConsoleMenuItemMove The constructor.
     * @param title The title of this menu item.
     * @param inputWaited The input waited to trigger this menu item.
     * @param order The order corresponding of this menu item.
     */
    ConsoleMenuItemMove(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu,
                        MoveOrder *order);

    /**
     * @brief action The methode used when the menu item is triggered.
     * @param args The argument provided with the input (if there are some).
     */
    virtual void action(std::vector<std::string> *args = nullptr) override;

private:
    /**
     * @brief order The order corresponding of this menu item.
     */
    MoveOrder *order;
};

#endif // CONSOLEMENUITEMMOVE_H
