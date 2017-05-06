#ifndef UTILS
#define UTILS

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
}

#endif
