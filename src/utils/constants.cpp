#ifndef CONSTANTS
#define CONSTANTS

#include <array>
#include <stdexcept>


namespace constants {
    enum ShipDirection {BOW, STARBOARD, STERN, PORT};
    enum Direction {NORTH, EAST, SOUTH, WEST};

    enum ClockDirection {CLOCKWISE, COUNTER_CLOCKWISE};
    enum StageGeneratorStage {NORMAL, UNSTABLE, ALERT, CRITICAL, STOPPED};

    const int maxSpeed = 12;
}

#endif
