#include "shipfactory.h"

#include "../diceExpression/diceexpression.h"
#include "component/navthruster.h"
#include "component/translationthruster.h"
#include "component/rotationthruster.h"
#include "component/energyComponents/generatorstage.h"
#include "component/energyComponents/stagegenerator.h"
#include "component/energyComponents/stoppedgeneratorstage.h"
#include "component/sensor.h"
#include "playercontrolledship.h"
#include "src/order/provideenergyorder.h"
#include "shipControl/playershipcontrol.h"
#include "src/exception/shipexception.h"
#include "src/exception/orderexception.h"
#include "armor.h"
#include "damage.h"
#include "component/energyComponents/stabilizator.h"
#include "hull.h"
#include "hulllevel.h"
#include "../thirdParty/pugixml-1.8/src/pugixml.hpp"
#include "../utils/vectorialmovement.h"
#include "../exception/xmlexception.h"

ShipFactory::ShipFactory()
{

}

PlayerControlledShip *ShipFactory::buildTestShip(IoController *ioController)
{
    PlayerControlledShip *ship;

    NavThruster *thrusterMK1 = new NavThruster("thruster MK1", "first sublight speed space thruster", nullptr, 3);
    TranslationThruster *tThrusterMK1 = new TranslationThruster("Translation thruster MK1", "Simple translation thruster", nullptr, 1);
    RotationThruster *rThrusterMK1 = new RotationThruster("Rotation thruster MK1", "simple rotation thruster", nullptr, 1);

    std::vector<HullLevel*> *hullLevels = new std::vector<HullLevel*>();
    for(size_t i = 0; i < 4; ++i) {
        if(i < 3) {
            hullLevels->push_back(new HullLevel(5));
        }
        else {
            hullLevels->push_back(new HullLevel(4));
        }
    }
    Hull *hull = new Hull(hullLevels);

    Armor *armor = new Armor(2,2,2,2);

    NavThruster *fThruster = new NavThruster(thrusterMK1);
    NavThruster *bThruster = new NavThruster(thrusterMK1);

    TranslationThruster *fTThruster = new TranslationThruster(tThrusterMK1);
    TranslationThruster *rTThruster = new TranslationThruster(tThrusterMK1);
    TranslationThruster *bTThruster = new TranslationThruster(tThrusterMK1);
    TranslationThruster *lTThruster = new TranslationThruster(tThrusterMK1);

    RotationThruster *cTThruster = new RotationThruster(rThrusterMK1);

    Sensor *sensor = new Sensor("Sensor Mk1", "Simple array of sensors", ship, 5);

    ship = new PlayerControlledShip("UES Test", "First Union of Earth prototype of Starship", hull, armor, sensor, fThruster, bThruster, lTThruster, fTThruster, rTThruster, bTThruster,
                    cTThruster, 0, ioController);

    StageGenerator *generator = new StageGenerator("Stage Generator MK1", "First generation of stage generators", ship);
    generator->addStage(new GeneratorStage(constants::NORMAL, new DiceExpression("D10"), generator));
    generator->addStage(new GeneratorStage(constants::CRITICAL, new DiceExpression("1D6 + 3"), generator));
    generator->addStage(new StoppedGeneratorStage(generator, new DiceExpression("D6 + 2"), 4));
    ship->addGenerator(generator, constants::CORE);

    Stabilizator *stab1 = new Stabilizator("Basic stabilizator", "basic stabilizator", nullptr, 8, nullptr);
    generator->addStabilizator(stab1);

    return ship;
}
