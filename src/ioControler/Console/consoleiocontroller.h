#ifndef CONSOLEIOCONTROLLER_H
#define CONSOLEIOCONTROLLER_H

#include "../iocontroller.h"
#include "../../utils/observer.h"

class GameController;
class ConsoleMenu;

class ConsoleIoController: public IoController, public Observer
{
public:
    /**
     * @brief ConsoleIOController The default constructor.
     * @param gameController The game controller.
     */
    ConsoleIoController(GameController *gameController);
    ~ConsoleIoController();
    /**
     * @brief launchGame Launch the game. This is pure virtual because it will depend of the how you want to play (graphics or console).
     */
    virtual void launchGame() override;

    /**
     * @brief loadMenu Load a menu and display it. Then wait for input.
     * @param menu The menu to load.
     */
    virtual void loadMenu(ConsoleMenu *menu);

    /**
     * @brief notify Notify this observer that the Observable has changed.
     * @param origin The changed observable
     * @param arg Some argument. Can be anything (but must be an object and not void* to check object type).
     */
    virtual void notify(Observable *origin, MyObject *arg) override;

    void setQuit(bool value);

    /**
     * @brief energyPhaseInteraction Ask for a player interaction for energy phase decisions
     * @param ship The ship that need an interaction.
     */
    virtual void energyPhaseInteraction(IShip *ship) override;

private:

    /**
     * @brief quit Does the user want to quit.
     */
    bool quit;

    static void clearScreen();
};

#endif // CONSOLEIOCONTROLLER_H
