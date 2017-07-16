#ifndef CONSOLEMENUITEM_H
#define CONSOLEMENUITEM_H

/**
 * @file consolemenuitem.h
 */

#include <string>
#include <vector>

/**
 * @brief The ConsoleMenuItem class A basic menu item for the console game.
 *                                  You should use this class with a lambda expression to implement pure virtual methods (like Java ActionListener).
 */
class ConsoleMenuItem
{
public:
    /**
     * @brief ConsoleMenuItem The constructor.
     * @param title The title of this menu item.
     * @param inputWaited The input waited to trigger this menu item.
     */
    ConsoleMenuItem(const std::string &title, const std::string &inputWaited);
    virtual ~ConsoleMenuItem();
    /**
     * @brief action The methode used when the menu item is triggered. Use a lambda expression to implement it or use inheritance with a concrete class.
     * @param args The argument provided with the input (if there are some).
     */
    virtual action(std::vector<std::string> *args = nullptr) = 0;
    /**
     * @brief toString Get the displayed string representing this menu item.
     * @return The string representing this menu item.
     */
    std::string toString();
private:
    /**
     * @brief title The title of this menu item.
     */
    std::string title;
    /**
     * @brief inputWaited The input waited to trigger this menu item.
     */
    std::string inputWaited;
};

#endif // CONSOLEMENUITEM_H
