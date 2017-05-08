#ifndef UTILS
#define UTILS

#include "constants.cpp"

#include <string>
#include <stdexcept>

namespace utils {
    inline bool isUnsigned(const std::string & s) {
        if(s.empty()) return false;

        char *p;
        strtoul(s.c_str(), &p, 10);

        return (*p == 0);
    }


    inline unsigned int stoui(const std::string& s) {
        unsigned long lresult = stoul(s, 0, 10);
        unsigned int result = lresult;
        if (result != lresult) {
            throw std::out_of_range("unsigned too long");
        }
        return result;
    }

    inline std::string StageGeneratorStagesToStr(const constants::StageGeneratorStage & stage) {
        switch (stage) {
        case constants::NORMAL:
            return "Normale";
            break;
        case constants::UNSTABLE:
            return "Unstable";
            break;
        case constants::ALERT:
            return "Alert";
            break;
        case constants::STOPPED:
            return "Stopped";
            break;
        default:
            throw std::invalid_argument( "Unknown StageGeneratorStage" );
            break;
        }
    }

    inline constants::Direction getClockwiseDirection(constants::Direction direction) {
        switch (direction) {
        case constants::NORTH:
            return constants::EAST;
            break;
        case constants::EAST:
            return constants::SOUTH;
            break;
        case constants::SOUTH:
            return constants::WEST;
            break;
        case constants::WEST:
            return constants::NORTH;
            break;
        default:
            throw std::invalid_argument( "Unknown direction" );
            break;
        }
    }

    inline constants::Direction getCounterClockwiseDirection(constants::Direction direction) {
        switch (direction) {
        case constants::NORTH:
            return constants::WEST;
            break;
        case constants::EAST:
            return constants::NORTH;
            break;
        case constants::SOUTH:
            return constants::EAST;
            break;
        case constants::WEST:
            return constants::SOUTH;
            break;
        default:
            throw std::invalid_argument( "Unknown direction" );
            break;
        }
    }

    inline std::string getDirectionStr(constants::Direction direction) {
        switch (direction) {
        case constants::NORTH:
            return "North";
            break;
        case constants::EAST:
            return "East";
            break;
        case constants::SOUTH:
            return "South";
            break;
        case constants::WEST:
            return "West";
            break;
        default:
            throw std::invalid_argument( "Unknown direction" );
            break;
        }
    }
}

#endif
