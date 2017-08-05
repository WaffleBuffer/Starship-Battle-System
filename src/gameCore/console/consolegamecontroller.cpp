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
    EnergyItem(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, EnergyProvidable *component)
        :ConsoleMenuItem(title, inputWaited, menu), component(component){}

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
        // TODO : check if the amount asked is over the limit of energy.
        ProvideEnergyOrder *order = new ProvideEnergyOrder(component->getShip(), component, amount);

        shipController->addOrder(order);
    }

    EnergyProvidable *component;
};

/* The item to act on already created orders */
struct OrderItem : ConsoleMenuItem {
    OrderItem(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, ProvideEnergyOrder *order)
        :ConsoleMenuItem(title, inputWaited, menu), order(order){}

    virtual void action(std::vector<std::string> *args = nullptr) {

        if(args != nullptr && args->size() > 0) {
            // throw new IOException("Unknown argument to act on order");
        }
    }

    ProvideEnergyOrder *order;
};

/* The menu item to see orders */
struct SeeOrderItem : ConsoleMenuItem {
    SeeOrderItem(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, IShip *ship)
        :ConsoleMenuItem(title, inputWaited, menu), ship(ship){}

    virtual void action(std::vector<std::string> *args = nullptr) {

        // TODO
        for (size_t i = 0; i < ship->getControl()->getOrders()->size(); ++i) {

        }
    }

    IShip *ship;
};

void ConsoleGameController::energyInteraction()
{

    for(size_t i = 0; i < this->getTeams()->size(); ++i) {
        Team *team = this->getTeams()->at(i);
        for(size_t j = 0; j < team->getShips()->size(); ++j) {
            IShip *ship = team->getShips()->at(j);

            std::string title = "Energy distribution " + std::to_string(ship->getControl()->getCurrentAvailableEnergy());
            ConsoleMenu energyMenu(title);

            for(size_t partCount = 0; partCount < ship->getParts()->size(); ++partCount) {
                std::vector<IComponent*> *part = ship->getParts()->at(partCount);

                size_t energyComponentCount = 0;
                for(size_t componentCount = 0; componentCount < part->size(); ++componentCount) {
                    EnergyProvidable *component = dynamic_cast<EnergyProvidable*> (part->at(componentCount));
                    if (component == NULL) {
                        continue;
                    }
                    // TODO : compute the amount of energy already provided to show it.
                    else {
                        EnergyItem *item = new EnergyItem(component->getName(), std::to_string(energyComponentCount), &energyMenu, component);
                        energyMenu.getMenuItems()->push_back(item);
                        energyComponentCount++;
                    }
                }
            }
            ConsoleMenuItemReturn *returnItem = new ConsoleMenuItemReturn("Finish" , "f" , &energyMenu);
            energyMenu.getMenuItems()->push_back(returnItem);

            try {
                this->getIoController()->loadMenu(&energyMenu);
            }
            catch (IOException *e) {

                std::cout << e->what() << std::endl;
                if(!e->getIsFatal()) {
                    this->getIoController()->loadMenu(&energyMenu);
                }
                delete (e);
            }
        }
    }
}
