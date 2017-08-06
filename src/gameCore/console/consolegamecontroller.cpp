#include "consolegamecontroller.h"
#include "../../ioControler/Console/consolemenu.h"
#include "../../ioControler/Console/consolemenuitem.h"
#include "../../ship/iship.h"
#include "../../exception/basicexception.h"
#include "../team.h"
#include "../../ship/shipcontrol.h"
#include "../../ship/component/energyprovidable.h"
#include "../../ioControler/Console/consoleiocontroller.h"
#include "../../exception/ioexception.h"
#include "../../ioControler/Console/consolemenuitemreturn.h"
#include "../../utils/utils.cpp"
#include "../../order/provideenergyorder.h"
#include "../../logger/logger.h"
#include "../../logger/logentry.h"

#include <iostream>
#include <vector>
#include <string>

ConsoleGameController::ConsoleGameController()
    :GameController(), ioController(nullptr){

}

void ConsoleGameController::phaseInteraction()
{
    switch (this->getCurrentPhase()) {
    case constants::ENERGY:
        this->energyInteraction();
        break;
    case constants::COMMAND:

        break;
    case constants::INITIATIVE:

        break;
    case constants::MOVEMENT:

        break;
    case constants::FIRE:

        break;
    case constants::CREW:

        break;
    case constants::NO_PHASE:
        throw new BasicException("Can't interact in NO_PHASE in consoleGameController phaseInteraction()");
        break;
    default:
        throw new BasicException("Unknown game phase in ConsoleGameControler interaction");
        break;
    }
}

ConsoleIOController *ConsoleGameController::getIoController() const
{
    return ioController;
}

void ConsoleGameController::setIoController(ConsoleIOController *value)
{
    ioController = value;
}

/* The item for each energy item */
struct EnergyItem : ConsoleMenuItem {
    EnergyItem(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, EnergyProvidable *component, GameController *gameController)
        :ConsoleMenuItem(title, inputWaited, menu), component(component), gameController(gameController){}

    virtual void action(std::vector<std::string> *args = nullptr) {

        if(args == nullptr || args->size() == 0) {
            std::cout << "Need to provide an energy amount as argument" << std::endl;
            return;
        }
        if (!utils::isUnsigned(args->at(0))) {
            std::cout << "Need to provide a valid energy amount as argument" << std::endl;
            return;
        }

        unsigned int amount = utils::stoui(args->at(0));
        ShipControl *shipController = component->getShip()->getControl();

        if(amount > this->component->getMaxEnergy()) {
            std::cout << "Can't provide so many EU to this component" << std::endl;
            return;
        }

        // Look to see if an order already exist for this component
        ProvideEnergyOrder *order = nullptr;
        for (size_t orderCount = 0; orderCount < shipController->getOrders()->size(); ++orderCount) {
            ProvideEnergyOrder *currentOrder = dynamic_cast<ProvideEnergyOrder*> (shipController->getOrders()->at(orderCount));
            if (currentOrder == NULL) {
                continue;
            }
            if(currentOrder->getComponentProvided() == this->component) {
                order = currentOrder;
                break;
            }
        }

        std::string logAction;
        if(order != nullptr) {

            if((int)(amount) - order->getEnergy() > shipController->getCurrentAvailableEnergy()) {
                std::cout << "Not enough available EU" << std::endl;
                return;
            }

            shipController->setCurrentAvailableEnergy(shipController->getCurrentAvailableEnergy() + order->getEnergy());
            order->setEnergy(amount);
            logAction = " modified.";
        }
        else {

            if(amount > shipController->getCurrentAvailableEnergy()) {
                std::cout << "Not enough available EU" << std::endl;
                return;
            }

            order = new ProvideEnergyOrder(component->getShip(), component, amount);
            shipController->addOrder(order);
            logAction = " created.";
        }
        shipController->setCurrentAvailableEnergy(shipController->getCurrentAvailableEnergy() - order->getEnergy());

        // Log
        std::string entryMsg = order->toString() + logAction;
        LogEntry *entry = new LogEntry(entryMsg);
        gameController->getLogger()->addEntry(entry);

        // Update titles
        std::string itemTitle = component->getName() + " " + std::to_string(amount) + "/" + std::to_string(component->getMaxEnergy());
        this->setTitle(itemTitle);
        std::string title = "Energy distribution : " + std::to_string(shipController->getCurrentAvailableEnergy()) + " EU available";
        this->getMenu()->setTitle(title);
    }

    EnergyProvidable *component;
    GameController *gameController;
};

void ConsoleGameController::energyInteraction()
{

    // For each team
    for(size_t i = 0; i < this->getTeams()->size(); ++i) {
        Team *team = this->getTeams()->at(i);
        // For each ships from this team
        for(size_t j = 0; j < team->getShips()->size(); ++j) {
            IShip *ship = team->getShips()->at(j);

            std::string title = "Energy distribution : " + std::to_string(ship->getControl()->getCurrentAvailableEnergy()) + " EU available";
            ConsoleMenu energyMenu(title);

            // For each part from this ship
            for(size_t partCount = 0; partCount < ship->getParts()->size(); ++partCount) {
                std::vector<IComponent*> *part = ship->getParts()->at(partCount);

                size_t energyComponentCount = 0;
                // For each component from this part
                for(size_t componentCount = 0; componentCount < part->size(); ++componentCount) {
                    // Is this component energy providable
                    EnergyProvidable *component = dynamic_cast<EnergyProvidable*> (part->at(componentCount));
                    if (component == NULL) {
                        continue;
                    }
                    else {

                        std::string itemTitle = component->getName() + " 0/" + std::to_string(component->getMaxEnergy());
                        EnergyItem *item = new EnergyItem(itemTitle, std::to_string(energyComponentCount), &energyMenu, component, this);
                        energyMenu.getMenuItems()->push_back(item);
                        energyComponentCount++;
                    }
                }
            }
            ConsoleMenuItemReturn *returnItem = new ConsoleMenuItemReturn("Finish" , "f" , &energyMenu);
            energyMenu.getMenuItems()->push_back(returnItem);

            //try {
            this->getIoController()->loadMenu(&energyMenu);
            /*}
            catch (IOException *e) {

                std::cout << e->what() << std::endl;
                if(!e->getIsFatal()) {
                    this->getIoController()->loadMenu(&energyMenu);
                }
                delete (e);
            }*/
        }
    }
}
