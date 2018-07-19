#include "consoleiocontroller.h"
#include "consolemenu.h"
#include "consolemenuitem.h"
#include "../../ship/playercontrolledship.h"
#include "../../ship/shipfactory.h"
#include "../../gameCore/team.h"
#include "../../exception/basicexception.h"
#include "../../logger/logger.h"
#include "../../logger/logentry.h"
#include "../../utils/utils.cpp"
#include "../../ship/shipControl/shipcontrol.h"
#include "../../ship/component/energyprovidable.h"
#include "consolemenuitemenergy.h"
#include "consolemenuitemreturn.h"
#include "../../gameCore/gamecontroller.h"
#include "../../order/moveorder.h"
#include "../../exception/orderexception.h"
#include "consolemenuitemmove.h"
#include "../../utils/vectorialmovement.h"

#include <iostream>
#include <windows.h>
#include <unistd.h>

ConsoleIoController::ConsoleIoController(GameController *gameController)
    :IoController(gameController), quit(false){

    gameController->getLogger()->getObservers()->push_back(this);
}

ConsoleIoController::~ConsoleIoController()
{
}

void ConsoleIoController::launchGame()
{
    ConsoleMenu mainMenu("Main menu");

    struct PlayItem : ConsoleMenuItem {

        PlayItem(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, IoController *ioController)
            :ConsoleMenuItem(title, inputWaited, menu), ioController(ioController) {}

        virtual void action(std::vector<std::string> *args = nullptr) {

            (void) args;
            std::cout << "PLAY!" << std::endl;
            ShipFactory factory;
            PlayerControlledShip *ship = factory.buildTestShip(this->ioController);

            Team player;
            player.getShips()->push_back(ship);
            std::vector<Team*>teams;
            teams.push_back(&player);
            GameController *gameController = this->ioController->getGameController();
            gameController->newGame(&teams);
        }

        IoController *ioController;
    } play("Play", "p", &mainMenu, this);
    mainMenu.getMenuItems()->push_back(&play);

    struct QuitItem : ConsoleMenuItem {
        QuitItem(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, ConsoleIoController *controller)
            :ConsoleMenuItem(title, inputWaited, menu), controller(controller) {}

        virtual void action(std::vector<std::string> *args = nullptr) {

            (void)args;
            std::cout << "Bye !" << std::endl;
            this->controller->setQuit(true);
            this->getMenu()->setIsOver(true);
        }

        ConsoleIoController *controller;
    } quit("Quit", "q", &mainMenu, this);
    mainMenu.getMenuItems()->push_back(&quit);

    while(!this->quit) {

        this->loadMenu(&mainMenu);
    }
}

void ConsoleIoController::loadMenu(ConsoleMenu *menu)
{
    std::string input = "";
    std::vector<std::string> args;

    std::cout << menu->toString() << std::endl;
    std::getline(std::cin, input);
    ConsoleIoController::clearScreen();

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
        ConsoleIoController::clearScreen();

        args = utils::explode(input, ' ');
        if(args.size() > 0) {
            input = args.at(0);
            args.erase(args.begin());
        }
    }
}

void ConsoleIoController::notify(Observable *origin, MyObject *arg)
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

void ConsoleIoController::setQuit(bool value)
{
    quit = value;
}

void ConsoleIoController::commandPhaseInteraction(IShip *ship)
{

    std::string title = "Energy distribution : " + std::to_string(ship->getControl()->getCurrentAvailableEnergy()) + " EU available";
    ConsoleMenu energyMenu(title);

    // For each part from this ship
    for(size_t partCount = 0; partCount < ship->getParts()->size(); ++partCount) {
        std::vector<IComponent*> *part = ship->getParts()->at(partCount);

        size_t energyComponentCount = 0;
        // For each component from this part
        for(size_t componentCount = 0; componentCount < part->size(); ++componentCount) {
            // We look for an energy providable component
            EnergyProvidable *component = dynamic_cast<EnergyProvidable*> (part->at(componentCount));
            if (component == NULL) {
                continue;
            }
            else {

                std::string itemTitle = component->getName() + " 0/" + std::to_string(component->getMaxEnergy());
                ConsoleMenuItemEnergy *item = new ConsoleMenuItemEnergy(itemTitle, std::to_string(energyComponentCount), &energyMenu, component, this->getGameController());
                energyMenu.getMenuItems()->push_back(item);
                energyComponentCount++;
            }
        }
    }
    ConsoleMenuItemReturn *returnItem = new ConsoleMenuItemReturn("Finish" , "f" , &energyMenu);
    energyMenu.getMenuItems()->push_back(returnItem);

    this->loadMenu(&energyMenu);
}

void ConsoleIoController::movementPhaseInteraction(IShip *ship)
{
    std::cout << "begin movementPhaseInteraction() -> " << std::to_string(ship->getControl()->getOrders()->size()) << " orders" <<  std::endl;
    std::string title = "\nOrdering" + ship->getMovement()->toString() + "\nUse \"" + constants::acceptConsoleInput + "\" to execute order or \"" + constants::cancelConsoleInput + "\" to cancel it (with cost)";
    ConsoleMenu movementMenu(title);

    size_t movementOrderCount = 0;
    for (size_t orderCount = 0; orderCount < ship->getControl()->getOrders()->size(); ++orderCount) {

        // Make sure it is a valid order.
        MoveOrder *moveOrder = dynamic_cast<MoveOrder*> (ship->getControl()->getOrders()->at(orderCount));
        // If it is a move order
        if(moveOrder != NULL) {
            ConsoleMenuItemMove *moveMenuItem = new ConsoleMenuItemMove(moveOrder->toString(), std::to_string(movementOrderCount), &movementMenu, moveOrder);
            movementMenu.getMenuItems()->push_back(moveMenuItem);
            ++movementOrderCount;
        }
        else {
            std::cout << "Invalid order found in movement phase in movementPhaseInteraction()" << std::endl;
            throw new OrderException("Invalid order in movement phase in movementPhaseInteraction()", ship->getControl()->getOrders()->at(orderCount));
            continue;
        }
    }

    this->loadMenu(&movementMenu);
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

void ConsoleIoController::clearScreen()
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
