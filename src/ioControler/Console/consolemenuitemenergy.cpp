#include "consolemenuitemenergy.h"
#include "../../ship/component/energyprovidable.h"
#include "../../utils/utils.cpp"
#include "../../ship/shipControl/shipcontrol.h"
#include "../../order/provideenergyorder.h"
#include "../../logger/logger.h"
#include "../../logger/logentry.h"
#include "../../ship/iship.h"
#include "../../gameCore/gamecontroller.h"
#include "consolemenu.h"

#include <iostream>
#include <string>
#include <vector>

ConsoleMenuItemEnergy::ConsoleMenuItemEnergy(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, EnergyProvidable *component, GameController *gameController)
    :ConsoleMenuItem(title, inputWaited, menu), component(component), gameController(gameController){

}

void ConsoleMenuItemEnergy::action(std::vector<std::string> *args)
{
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

        // Test to see if we have enough energy (only when the user wants to add energy)
        if((int)amount > order->getEnergy() && amount - order->getEnergy() > shipController->getCurrentAvailableEnergy()) {
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
