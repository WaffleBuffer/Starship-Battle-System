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
#include <windows.h>
#include <unistd.h>

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
    ConsoleIOController::clearScreen();

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
        ConsoleIOController::clearScreen();

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

    std::cout << entry->toString() << std::endl;
}

void ConsoleIOController::setQuit(bool value)
{
    quit = value;
}

void clearScreenWindows() {

#if defined(_WIN32) || defined(_WIN64)
      HANDLE                     hStdOut;
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      DWORD                      count;
      DWORD                      cellCount;
      COORD                      homeCoords = { 0, 0 };

      hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
      if (hStdOut == INVALID_HANDLE_VALUE) return;

      /* Get the number of cells in the current buffer */
      if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
      cellCount = csbi.dwSize.X *csbi.dwSize.Y;

      /* Fill the entire buffer with spaces */
      if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR) ' ',
        cellCount,
        homeCoords,
        &count
        )) return;

      /* Fill the entire buffer with the current colors and attributes */
      if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
        )) return;

      /* Move the cursor home */
      SetConsoleCursorPosition( hStdOut, homeCoords );
#endif
}

void clearScreenPOSIX() {
    /*if (!cur_term){
        int result;
        setupterm( NULL, STDOUT_FILENO, &result );
        if (result <= 0) return;
     }

     putp(tigetstr("clear"));*/
    std::cout << "\033[2J\033[1;1H";
}

void ConsoleIOController::clearScreen()
{
#ifdef _WIN32
    clearScreenWindows();
#elif _WIN64
    clearScreenWindows();
#elif __linux__
    clearScreenPOSIX();
#elif __unix__
    clearScreenPOSIX();
#elif defined(_POSIX_VERSION)
    clearScreenPOSIX();
#else
    // Unsupported OS console
    return;
#endif
}
