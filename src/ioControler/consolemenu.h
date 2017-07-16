#ifndef CONSOLEMENU_H
#define CONSOLEMENU_H

/**
 * @file consolemenu.h
 */

#include <vector>
#include <string>

class ConsoleMenuItem;

/**
 * @brief The ConsoleMenu class A menu for the console game. It is just a group of menu item.
 */
class ConsoleMenu
{
public:
    /**
     * @brief ConsoleMenu The constructor.
     * @param title The title of this menu. If you can use the title of the precedent MenuItem.
     */
    ConsoleMenu(const std::string &title);
    ~ConsoleMenu();
private:
    /**
     * @brief menuItems The list of menu item.
     */
    std::vector<ConsoleMenuItem*> *menuItems;
    /**
     * @brief title The title of this menu. If you can use the title of the precedent MenuItem.
     */
    std::string title;
};

#endif // CONSOLEMENU_H
