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
}

#endif
