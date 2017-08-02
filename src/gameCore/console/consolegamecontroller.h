#ifndef CONSOLEGAMECONTROLLER_H
#define CONSOLEGAMECONTROLLER_H

#include "../gamecontroller.h"

class ConsoleIOController;

/**
 * @brief The ConsoleGameController class. The game controller to use in console.
 */
class ConsoleGameController: public GameController
{
public:
    /**
     * @brief ConsoleGameController The constructor.
     * @param ioController The console io controller.
     */
    ConsoleGameController();

    /**
     * @brief phaseInteraction ask for an interaction for the current phase.
     */
    void virtual phaseInteraction();
    /**
     * @brief getIoController Get the io controller.
     * @return The io controller.
     */
    ConsoleIOController *getIoController() const;
    /**
     * @brief setIoController Set the io controller.
     * @param value The io controller to set.
     */
    void setIoController(ConsoleIOController *value);

private:
    /**
     * @brief ioController The console io controller.
     */
    ConsoleIOController *ioController;
    /**
     * @brief energyInteraction Make the intercations needed in energy phase.
     */
    void energyInteraction();
};

#endif // CONSOLEGAMECONTROLLER_H
