#ifndef CONSOLEIOCONTROLLER_H
#define CONSOLEIOCONTROLLER_H

#include "../iocontroller.h"

class ConsoleIOController: public IoController
{
public:
    /**
     * @brief ConsoleIOController The default constructor.
     * @param gameController The game controller.
     */
    ConsoleIOController(GameController *gameController);
    /**
     * @brief launchGame Launch the game. This is pure virtual because it will depend of the how you want to play (graphics or console).
     */
    virtual void launchGame() override;
};

#endif // CONSOLEIOCONTROLLER_H
