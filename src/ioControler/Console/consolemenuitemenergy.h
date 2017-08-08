#ifndef CONSOLEMENUITEMENERGY_H
#define CONSOLEMENUITEMENERGY_H

#include "consolemenuitem.h"

class EnergyProvidable;
class GameController;

/**
 * @brief The ConsoleMenuItemEnergy class. The console menu item for energy phase interaction.
 */
class ConsoleMenuItemEnergy: public ConsoleMenuItem
{
public:
    /**
     * @brief ConsoleMenuItemEnergy The constructor.
     * @param title The title of the menu item.
     * @param inputWaited The input waited for this item.
     * @param menu The menu containing this menu item.
     * @param component The component corresponding of this menu item.
     * @param gameController The game controller.
     */
    ConsoleMenuItemEnergy(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, EnergyProvidable *component,
                          GameController *gameController);

    /**
     * @brief action The methode used when the menu item is triggered.
     * @param args The argument provided with the input (if there are some).
     */
    virtual void action(std::vector<std::string> *args = nullptr) override;

private:
    /**
     * @brief component The component corresponding of this menu item.
     */
    EnergyProvidable *component;
    /**
     * @brief gameController The game controller.
     */
    GameController *gameController;
};

#endif // CONSOLEMENUITEMENERGY_H
