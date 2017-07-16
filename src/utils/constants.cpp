#ifndef CONSTANTS
#define CONSTANTS

/**
 * @file constants.cpp
 */

#include <array>
#include <stdexcept>
#include <string>

class DiceExpression;

namespace constants {

    /**
     * @brief The shipParts enum. All parts of a ship that can contain component.
     */
    enum shipParts {BOW_PART, STARBOARD_PART, STERN_PART, PORT_PART, CORE};
    /**
     * @brief The ShipDirection enum. In order: front, right, rear, left.
     */
    enum ShipDirection {BOW = 0, STARBOARD = 1, STERN = 2, PORT = 3};
    /**
     * @brief The Direction enum.
     */
    enum Direction {NORTH, EAST, SOUTH, WEST};

    /**
     * @brief The ClockDirection enum. Not used right now.
     */
    enum ClockDirection {CLOCKWISE, COUNTER_CLOCKWISE};
    /**
     * @brief The StageGeneratorStage enum. All the possible stages.
     */
    enum StageGeneratorStage {NORMAL, UNSTABLE, ALERT, CRITICAL, STOPPED};

    /**
     * @brief The gamePhase enum. All the game phases
     */
    enum gamePhase {ENERGY, COMMAND, INITIATIVE, MOVEMENT, FIRE, CREW};

    /**
     * @brief maxSpeed Tha maximum speed a ship can safely get to.
     */
    const int maxSpeed = 12;
    /**
     * @brief maxManoveurSpeed. The maximum speed from wich a ship can perform a manoveur.
     */
    const int maxManoveurSpeed = 3;
    /**
     * @brief criticalDamageThreshold The number of critical damage roll needed for the damage to be considered critical.
     */
    const int criticalDamageThreshold = 2;
    /**
     * @brief aimingDamageThreshold. The damage amoount threshold to reach to be able to aim.
     */
    const int aimingDamageThreshold = 4;
    /**
     * @brief aimRoll The roll used to aim.
     */
    const std::string aimRoll = "1D10";

    /**
     * @brief criticalDamageRoll The value on a damage roll that count as critical.
     */
    const int criticalDamageRoll = 1;
}

#endif
