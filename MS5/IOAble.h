// Milestone: 2
// Date: 2021/3/22
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_IOABLE_H
#define SDDS_IOABLE_H
#include <iostream>

namespace sdds
{
    class IOAble
    {
    public:
        virtual ~IOAble(){};
        virtual std::ostream &csvWrite(std::ostream &) const = 0;
        virtual std::istream &csvRead(std::istream &) = 0;
        virtual std::ostream &write(std::ostream &) const = 0;
        virtual std::istream &read(std::istream &) = 0;
    };

    std::ostream &operator<<(std::ostream &first, const IOAble &obj);
    std::istream &operator>>(std::istream &first, IOAble &obj);
}
#endif