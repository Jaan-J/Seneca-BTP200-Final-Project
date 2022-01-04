// Milestone: 2
// Date: 2021/3/22
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>

namespace sdds {

    extern bool debug;            
    int getTime();
    int getInt(const char* prompt = nullptr);
    int getInt(int min, int max, const char* prompt = nullptr, const char* errorMessage = nullptr, bool showRangeAtError = true);
    char* getcstr(const char* prompt = nullptr, std::istream& istr = std::cin, char delimiter = '\n');

}
#endif 