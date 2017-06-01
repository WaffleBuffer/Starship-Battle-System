#ifndef UTILS
#define UTILS

/**
 * @file utils.cpp
 */

#include "constants.cpp"

#include <string>
#include <stdexcept>

namespace utils {
    /**
     * @brief isUnsigned. Can a string be converted to unsigned.
     * @param s The string to test.
     * @return true if can be converted to unsigned, false otherwise.
     */
    inline bool isUnsigned(const std::string & s) {
        if(s.empty()) return false;

        char *p;
        strtoul(s.c_str(), &p, 10);

        return (*p == 0);
    }

    /**
     * @brief stoui Convert a string to unsigned.
     * @param s The string to convert.
     * @return The converted unsigned.
     */
    inline unsigned int stoui(const std::string& s) {
        unsigned long lresult = stoul(s, 0, 10);
        unsigned int result = lresult;
        if (result != lresult) {
            throw std::out_of_range("unsigned too long");
        }
        return result;
    }

    /**
     * @brief StageGeneratorStagesToStr Get the string representation of a generator stage.
     * @param stage The stage to represent.
     * @return The string representation of the generator stage
     */
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
        case constants::CRITICAL:
            return "Critical";
            break;
        case constants::STOPPED:
            return "Stopped";
            break;
        default:
            throw std::invalid_argument( "Unknown StageGeneratorStage in string" );
            break;
        }
    }

    /**
     * @brief getClockwiseDirection Get the next direction clockwise.
     * @param direction The base direction
     * @return The next direction clockwise.
     */
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

    /**
     * @brief getClockwiseDirection Get the next direction counter clockwise.
     * @param direction The base direction
     * @return The next direction counter clockwise.
     */
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

    /**
     * @brief getDirectionStr get the string representation of a direction.
     * @param direction The direction.
     * @return The string representation of direction.
     */
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

    /**
     * @brief getInvertDir Get the invert direction.
     * @param dir The base direction.
     * @return The invert direction of dir.
     */
    inline constants::Direction getInvertDir(constants::Direction dir) {
        switch (dir) {
        case constants::NORTH:
            return constants::SOUTH;
            break;
        case constants::EAST:
            return constants::WEST;
            break;
        case constants::SOUTH:
            return constants::NORTH;
            break;
        case constants::WEST:
            return constants::EAST;
            break;
        default:
            throw std::invalid_argument( "Unknown direction" );
            break;
        }
    }

    /**
     * @brief getInvertShipDir Get the invert ship direction.
     * @param dir The base ship direction.
     * @return The invert ship direction of dir.
     */
    inline constants::ShipDirection getInvertShipDir(constants::ShipDirection dir) {
        switch (dir) {
        case constants::BOW:
            return constants::STERN;
            break;
        case constants::STARBOARD:
            return constants::PORT;
            break;
        case constants::STERN:
            return constants::BOW;
            break;
        case constants::PORT:
            return constants::STARBOARD;
            break;
        default:
            throw std::invalid_argument( "Unknown direction to invert" );
            break;
        }
    }

    /**
     * @brief partToStr Get the string representation of a ship part.
     * @param part The ship part.
     * @return The string representation.
     */
    inline std::string partToStr(constants::shipParts part) {
        switch (part) {
        case constants::CORE:
            return "Core";
            break;
        case constants::STARBOARD_PART:
            return "Starboard";
            break;
        case constants::STERN_PART:
            return "Stern";
            break;
        case constants::PORT_PART:
            return "Port";
            break;
        case constants::BOW_PART:
            return "Bow";
            break;
        default:
            throw std::invalid_argument( "Unknown ship part to str" );
            break;
        }
    }

    /**
     * @brief strToPart Get the ship part from a string
     * @param str The string to try to convert.
     * @return The corresponding ship part.
     */
    inline constants::shipParts strToPart(std::string str) {
        if(str == "Core") {
            return constants::CORE;
        }
        else if (str == "Starboard") {
            return constants::STARBOARD_PART;
        }
        else if (str == "Stern") {
            return constants::STERN_PART;
        }
        else if (str == "Bow") {
            return constants::BOW_PART;
        }
        else if (str == "Port") {
            return constants::PORT_PART;
        }
        else {
            throw std::invalid_argument( "Unknown str to ship part" );
        }
    }

    /**
     * @brief shipDirectionToStr Get string representation of a ship direction
     * @param dir The ship direction.
     * @return The string representation.
     */
    inline std::string shipDirectionToStr(constants::ShipDirection dir) {
        switch (dir) {
        case constants::BOW:
            return "Bow";
            break;
        case constants::STARBOARD:
            return "Starboard";
            break;
        case constants::STERN:
            return "Stern";
            break;
        case constants::PORT:
            return "Port";
            break;
        default:
            throw std::invalid_argument( "Unknown ship direction to str" );
            break;
        }
    }

    /**
     * @brief strToShipDir Get the ship direction from a string
     * @param str The string to try to convert.
     * @return The corresponding ship direction.
     */
    inline constants::ShipDirection strToShipDir(std::string str) {
        if (str == "Starboard") {
            return constants::STARBOARD;
        }
        else if (str == "Stern") {
            return constants::STERN;
        }
        else if (str == "Bow") {
            return constants::BOW;
        }
        else if (str == "Port") {
            return constants::PORT;
        }
        else {
            throw std::invalid_argument( "Unknown str to ship part" );
        }
    }
}

#endif
