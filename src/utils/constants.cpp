#ifndef CONSTANTS
#define CONSTANTS

namespace constants {
    enum ShipDirection {BOW, STARBOARD, STERN, PORT};
    enum Direction {FRONT, RIGHT, BACK, LEFT};

    enum StageGeneratorStages {NORMAL, UNSTABLE, ALERT, CRITICAL, STOPPED};

    const int maxSpeed = 12;
}

#endif
