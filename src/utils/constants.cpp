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
     * @brief maxSpeed Tha maximum speed a ship can safely get to.
     */
    const int maxSpeed = 12;
    /**
     * @brief maxManoveurSpeed. The maximum speed from wich a ship can perform a manoveur.
     */
    const int maxManoveurSpeed = 3;
    /**
     * @brief criticalDamageThreshold. The threshold of damage amount to reach to be considered critical.
     */
    const int criticalDamageThreshold = 8;
    /**
     * @brief aimingDamageThreshold. The damage amoount threshold to reach to be able to aim.
     */
    const int aimingDamageThreshold = 4;
    /**
     * @brief aimRoll The roll used to aim.
     */
    const std::string aimRoll = "1D10";
}

#endif
