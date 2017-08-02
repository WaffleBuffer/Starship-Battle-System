#ifndef CONSOLEIOCONTROLLER_H
#define CONSOLEIOCONTROLLER_H

#include "../iocontroller.h"
#include "../../utils/observer.h"

class ConsoleGameController;
class ConsoleMenu;

class ConsoleIOController: public IoController, public Observer
{
public:
    /**
     * @brief ConsoleIOController The default constructor.
     * @param gameController The game controller.
     */
    ConsoleIOController(ConsoleGameController *gameController);
    ~ConsoleIOController();
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
     * @brief getController Get the current occurence of ConsoleController.
     * @return The current occurence of ConsoleController.
     */
    static ConsoleIOController *getController();

    /**
     * @brief notify Notify this observer that the Observable has changed.
     * @param origin The changed observable
     * @param arg Some argument. Can be anything (but must be an object and not void* to check object type).
     */
    virtual void notify(Observable *origin, MyObject *arg);

    void setQuit(bool value);

private:
    /**
     * @brief controller The current occurence of ConsoleController.
     */
    static ConsoleIOController *controller;

    /**
     * @brief quit Does the user want to quit.
     */
    bool quit;
};

#endif // CONSOLEIOCONTROLLER_H
