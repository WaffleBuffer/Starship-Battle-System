#include "consoleiocontroller.h"
#include "consolemenu.h"
#include "consolemenuitem.h"
#include "../../gameCore/console/consolegamecontroller.h"
#include "../../ship/ship.h"
#include "../../ship/shipfactory.h"
#include "../../gameCore/team.h"
#include "../../exception/basicexception.h"
#include "../../logger/logger.h"
#include "../../logger/logentry.h"
#include "../../utils/utils.cpp"

#include <iostream>

ConsoleIOController *ConsoleIOController::controller = nullptr;

ConsoleIOController::ConsoleIOController(ConsoleGameController *gameController)
    :IoController(gameController), quit(false){
    ConsoleIOController::controller = this;
    gameController->getLogger()->getObservers()->push_back(this);
    gameController->setIoController(this);
}

ConsoleIOController::~ConsoleIOController()
{
    ConsoleIOController::controller = nullptr;
}

void ConsoleIOController::launchGame()
{
    ConsoleMenu mainMenu("Main menu");

    struct PlayItem : ConsoleMenuItem {

        PlayItem(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu)
            :ConsoleMenuItem(title, inputWaited, menu) {}

        virtual void action(std::vector<std::string> *args = nullptr) {

            std::cout << "PLAY!" << std::endl;
            ShipFactory factory;
            Ship *ship = factory.buildTestShip();

            Team player;
            player.getShips()->push_back(ship);
            std::vector<Team*>teams;
            teams.push_back(&player);
            GameController *gameController = ConsoleIOController::getController()->getGameController();
            gameController->newGame(&teams);
        }
    } play("Play", "p", &mainMenu);
    mainMenu.getMenuItems()->push_back(&play);

    struct QuitItem : ConsoleMenuItem {
        QuitItem(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, ConsoleIOController *controller)
            :ConsoleMenuItem(title, inputWaited, menu), controller(controller) {}

        virtual void action(std::vector<std::string> *args = nullptr) {
            std::cout << "Bye !" << std::endl;
            this->controller->setQuit(true);
            this->getMenu()->setIsOver(true);
        }

        ConsoleIOController *controller;
    } quit("Quit", "q", &mainMenu, this);
    mainMenu.getMenuItems()->push_back(&quit);

    while(!this->quit) {

        this->loadMenu(&mainMenu);
    }
}

void ConsoleIOController::loadMenu(ConsoleMenu *menu)
{
    std::string input = "";
    std::vector<std::string> args;

    std::cout << menu->toString() << std::endl;
    std::getline(std::cin, input);

    args = utils::explode(input, ' ');
    if(args.size() > 0) {
        input = args.at(0);
        args.erase(args.begin());
    }

    while (!menu->getIsOver()) {
        menu->checkInput(input, &args);

        if (menu->getIsOver()) {
            break;
        }

        std::cout << menu->toString() << std::endl;
        std::getline(std::cin, input);

        args = utils::explode(input, ' ');
        if(args.size() > 0) {
            input = args.at(0);
            args.erase(args.begin());
        }
    }
}

ConsoleIOController *ConsoleIOController::getController()
{
    if (controller == nullptr) {
        throw new BasicException("Logger not initialized");
    }
    return controller;
}

void ConsoleIOController::notify(Observable *origin, MyObject *arg)
{
    Logger *logger = dynamic_cast<Logger*> (origin);
    if(logger == NULL) {
        return;
    }
    LogEntry *entry = dynamic_cast<LogEntry*> (arg);
    if(entry == NULL) {
        return;
    }

    std:: cout << entry->toString() << std::endl;
}

void ConsoleIOController::setQuit(bool value)
{
    quit = value;
}
