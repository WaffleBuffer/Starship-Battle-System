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

void ConsoleGameController::energyInteraction()
{
    /* The item for each energy item */
    struct EnergyItem : ConsoleMenuItem {
        EnergyItem(const std::string &title, const std::string &inputWaited, ConsoleMenu *menu, EnergyProvidable *component)
            :ConsoleMenuItem(title, inputWaited, menu), component(component) {}

        virtual void action(std::vector<std::string> *args = nullptr) {

            if(args == nullptr || args->size() == 0) {
                throw new IOException("Need to provide an energy amount as argument", false);
            }
            utils::isUnsigned(args->at(0));

        }

        EnergyProvidable *component;
    };

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
                delete (e);
                this->getIoController()->loadMenu(&energyMenu);
            }
        }
    }
}
