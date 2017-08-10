#include "gamecontroller.h"
#include "team.h"
#include "../exception/basicexception.h"
#include "../ship/iship.h"
#include "../logger/logger.h"
#include "../logger/logentry.h"
#include "../ship/shipControl/shipcontrol.h"
#include "../order/provideenergyorder.h"

Logger *GameController::logger = nullptr;

GameController::GameController()
    :teams(new std::vector<Team*>()), currentPhase(constants::NO_PHASE), turn(0){

    if(GameController::logger == nullptr) {
        GameController::logger = new Logger();
    }
}

GameController::~GameController()
{
    for (size_t i = 0; i < this->teams->size(); ++i) {
        delete(this->teams->at(i));
    }
    delete(this->teams);
}

void GameController::nextPhase()
{
    switch (this->currentPhase) {
    case constants::ENERGY:
        this->currentPhase = constants::COMMAND;
        this->commandPhase();
        break;
    case constants::COMMAND:
        this->currentPhase = constants::INITIATIVE;
        this->initiativePhase();
        break;
    case constants::INITIATIVE:
        this->currentPhase = constants::MOVEMENT;
        this->movementPhase();
        break;
    case constants::MOVEMENT:
        this->currentPhase = constants::FIRE;
        this->firePhase();
        break;
    case constants::FIRE:
        this->currentPhase = constants::CREW;
        this->crewPhase();
        break;
    case constants::CREW:
        this->currentPhase = constants::ENERGY;
        this->endTurn();
        this->turn++;
        this->beginTurn();
        this->energyPhase();
        break;
    case constants::NO_PHASE:
        this->currentPhase = constants::ENERGY;
        this->energyPhase();
        break;
    default:
        throw new BasicException("Unknown game phase in GameControler");
        break;
    }
}

void GameController::gameLoop()
{
    while(true) {
        this->nextPhase();
    }
}

void GameController::beginTurn()
{

}

void GameController::endTurn()
{

}

Logger *GameController::getLogger()
{
    if (logger == nullptr) {
        throw new BasicException("Logger not initialized");
    }
    return logger;
}

constants::gamePhase GameController::getCurrentPhase() const
{
    return currentPhase;
}

void GameController::energyPhase()
{
    GameController::getLogger()->addEntry(new LogEntry("Beginning energy phase"));
    Team *team;
    IShip *ship;
    // TODO: make this multi-thread : one thread for each team.
    for (size_t i = 0; i < this->teams->size(); ++i) {
        team = this->teams->at(i);
        for(size_t j = 0; j < team->getShips()->size(); ++j) {
            ship = team->getShips()->at(j);
            int amount = ship->generateEnergy();
            GameController::getLogger()->addEntry(new LogEntry(ship->getName() + " has generated " + std::to_string(amount) + " EU"));
        }
    }
}

void GameController::commandPhase()
{
    GameController::getLogger()->addEntry(new LogEntry("Beginning command phase"));
    Team *team;
    IShip *ship;
    // TODO: make this multi-thread : one thread for each team.
    for (size_t i = 0; i < this->teams->size(); ++i) {
        team = this->teams->at(i);
        for(size_t j = 0; j < team->getShips()->size(); ++j) {
            ship = team->getShips()->at(j);

            ship->getControl()->commandDecision();

            ShipControl *shipControl = ship->getControl();
            // Apply all energy orders and only them (since some energy order result in creation of other orders)
            for(size_t i = 0; i < shipControl->getOrders()->size(); ++i) {
                ProvideEnergyOrder *provideOrder = dynamic_cast<ProvideEnergyOrder*>(shipControl->getOrders()->at(i));
                // If a non-energy order found, that mean there are no more energy order (as they are all at the beginning).
                if(provideOrder == NULL) {
                    break;
                }
                else {
                    provideOrder->applyOrder();
                }
            }
            // Now we erase those order. We do it here because some order create new ones that invalidate iterator.
            for(auto it = shipControl->getOrders()->begin(); it != shipControl->getOrders()->end();) {
                ProvideEnergyOrder *provideOrder = dynamic_cast<ProvideEnergyOrder*>(*it);
                // If a non-energy order found, that mean there are no more energy order (as they are all at the beginning).
                if(provideOrder == NULL) {
                    break;
                }
                else {
                    it = shipControl->getOrders()->erase(it);
                }
            }
        }
    }
}

void GameController::initiativePhase()
{
    GameController::getLogger()->addEntry(new LogEntry("Beginning initiative phase"));
}

void GameController::movementPhase()
{
    GameController::getLogger()->addEntry(new LogEntry("Beginning movement phase"));
    Team *team;
    IShip *ship;
    // TODO: make this multi-thread : one thread for each team.
    // TODO: order teams by team initiative.
    for (size_t i = 0; i < this->teams->size(); ++i) {
        team = this->teams->at(i);
        // TODO : order ships by initiative.
        for(size_t j = 0; j < team->getShips()->size(); ++j) {
            ship = team->getShips()->at(j);

            ship->getControl()->movementDecision();
            // Apply all movement orders
            ship->getControl()->applyOrders();
        }
    }
}

void GameController::firePhase()
{
    GameController::getLogger()->addEntry(new LogEntry("Beginning fire phase"));
}

void GameController::crewPhase()
{
    GameController::getLogger()->addEntry(new LogEntry("Beginning crew phase"));
}

std::vector<Team *> *GameController::getTeams() const
{
    return teams;
}

void GameController::newGame(std::vector<Team *> *teams)
{
    for (size_t i = 0; i < this->teams->size(); ++i) {
        delete(this->teams->at(i));
    }
    delete(this->teams);
    this->currentPhase = constants::NO_PHASE;
    this->turn = 0;

    this->teams = teams;
    this->gameLoop();
}
