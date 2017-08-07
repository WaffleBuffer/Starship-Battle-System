#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

/**
 * @file gamecontroller.h
 */

#include "../utils/constants.cpp"
#include <vector>

class Team;
class Logger;

/**
 * @brief The GameController class The controller that will manage the game (turns, phases...). However, it is inferior to the ioController (which will call the GameController).
 */
class GameController
{
public:
    /**
     * @brief GameController The default constructor.
     */
    GameController();
    virtual ~GameController();

    /**
     * @brief getCurrentPhase Get the current phase of the current turn.
     * @return The current phase.
     */
    constants::gamePhase getCurrentPhase() const;

    /**
     * @brief getLogger Get the logger controller.
     * @return The logger controller.
     */
    static Logger *getLogger();

    /**
     * @brief getTeams Get the teams.
     * @return The teams.
     */
    std::vector<Team *> *getTeams() const;

    /**
     * @brief newGame Begin a new game.
     * @param teams The teams participating.
     */
    void newGame(std::vector<Team *> *teams);

private:
    /**
     * @brief beginTurn Begin a new turn.
     */
    void beginTurn();
    /**
     * @brief endTurn End the current turn.
     */
    void endTurn();

    /**
     * @brief teams The different teams of ships playing currently.
     */
    std::vector<Team*> *teams;
    /**
     * @brief currentPhase The current game phase. In order : energy -> command -> initiative -> movement -> fire -> crew, then new turn.
     */
    constants::gamePhase currentPhase;
    /**
     * @brief logger The logger controller. It is created with the game controller, so nothing should access it when no game controller exist.
     */
    static Logger *logger;
    /**
     * @brief turn The current turn number (begining at 0).
     */
    unsigned int turn;

    /**
     * @brief energyPhase Begin the energy phase.
     */
    void energyPhase();
    /**
     * @brief commandPhase Begin the command phase.
     */
    void commandPhase();
    /**
     * @brief initiativePhase Begin the initiative phase.
     */
    void initiativePhase();
    /**
     * @brief movementPhase Begin the movement phase.
     */
    void movementPhase();
    /**
     * @brief firePhase Begin the fire phase.
     */
    void firePhase();
    /**
     * @brief crewPhase Begin the crew phase.
     */
    void crewPhase();
    /**
     * @brief nextPhase Call for next phase methode. In order : energy -> command -> initiative -> movement -> fire -> crew, then new turn.
     */
    void nextPhase();

    /**
     * @brief gameLoop The main game loop for each phases
     */
    void gameLoop();
};

#endif // GAMECONTROLLER_H
