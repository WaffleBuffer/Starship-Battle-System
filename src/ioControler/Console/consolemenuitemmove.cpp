#include "consolemenuitemmove.h"
#include "../../order/moveorder.h"
#include "../../utils/constants.cpp"
#include "../../exception/basicexception.h"
#include "../../gameCore/gamecontroller.h"
#include "../../logger/logentry.h"
#include "../../logger/logger.h"
#include "consolemenu.h"
#include "../../ship/iship.h"
#include "../../utils/vectorialmovement.h"

#include <iostream>

ConsoleMenuItemMove::ConsoleMenuItemMove(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, MoveOrder *order)
    :ConsoleMenuItem(title, inputWaited, menu), order(order){

}

void ConsoleMenuItemMove::action(std::vector<std::string> *args)
{
    if(args == nullptr || args->size() == 0) {
        std::cout << "Need to provide an argument" << std::endl;
        return;
    }

    bool correctInput = false;

    if(args->at(0) == constants::acceptConsoleInput) {

        // TODO : accept case
        correctInput = true;
        this->order->applyOrder();
        Logger *logger = GameController::getLogger();
        if(logger != nullptr) {
            LogEntry logEntry(this->toString() + " applied");
            logger->addEntry(&logEntry);
        }
    }
    else if(args->at(0) == constants::cancelConsoleInput) {

        // TODO : cancel case
        correctInput = true;
    }
    else {
        std::cout << "Invalid argument for movement menu item" << std::endl;
        return;
    }

    // If a correct input has been processed normally, delete this menu item.
    if (correctInput) {

        std::string title = this->order->getShip()->getMovement()->toString() + "\nMovement ordering";
        this->getMenu()->setTitle(title);

        for(auto it = this->getMenu()->getMenuItems()->begin(); it != this->getMenu()->getMenuItems()->end(); ++it) {
            if(*it == this) {
                this->getMenu()->getMenuItems()->erase(it);
                break;
            }
        }

        if(this->getMenu()->getMenuItems()->size() == 0) {
            this->getMenu()->setIsOver(true);
        }
        delete(this);
    }
}
