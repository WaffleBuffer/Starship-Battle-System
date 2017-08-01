#include "consoleiocontroller.h"
#include "consolemenu.h"
#include "consolemenuitem.h"

#include "../../ship/ship.h"
#include "../../ship/shipfactory.h"

#include <iostream>

ConsoleIOController::ConsoleIOController(GameController *gameController)
    :IoController(gameController){

}

void ConsoleIOController::launchGame()
{
    ConsoleMenu mainMenu("Main menu");

    struct MyConsoleItem : ConsoleMenuItem {
        MyConsoleItem(const std::string &title, const std::string &inputWaited)
            :ConsoleMenuItem(title, inputWaited) {}
        virtual void action(std::vector<std::string> *args = nullptr) {
            std::cout << "PLAY!" << std::endl;
            ShipFactory factory;
            Ship *ship = factory.buildTestShip();
            std::cout << ship->toString() << std::endl;
        }
    } myItem("Play", "p");
    mainMenu.getMenuItems()->push_back(&myItem);

    std::string input = "";
    while (!mainMenu.checkInput(input)) {
        std::cout << mainMenu.toString() << std::endl;
        std::getline(std::cin, input);
    }
}
