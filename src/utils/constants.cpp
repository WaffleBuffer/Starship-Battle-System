#ifndef CONSTANTS
#define CONSTANTS

#include <array>
#include <stdexcept>
#include <string>

class DiceExpression;

namespace constants {
    // In order: front, right, rear, left
    enum ShipDirection {BOW = 0, STARBOARD = 1, STERN = 2, PORT = 3};
    enum Direction {NORTH, EAST, SOUTH, WEST};

    enum ClockDirection {CLOCKWISE, COUNTER_CLOCKWISE};
    enum StageGeneratorStage {NORMAL, UNSTABLE, ALERT, CRITICAL, STOPPED};

    const int maxSpeed = 12;
    const int maxManoveurSpeed = 3;
    const int criticalDamageThreshold = 8;
    const int aimingDamageThreshold = 4;
    const std::string aimRoll = "1D10";
}

#endif
