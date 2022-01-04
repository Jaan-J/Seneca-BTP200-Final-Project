// Milestone: 3
// Date: 2021/3/27
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_PATIENT_H
#define SDDS_PATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

namespace sdds
{
    class Patient : public IOAble
    {
        Ticket object;

        char *m_name = nullptr;
        int m_ohip;
        bool m_flag;

    public:
        int number() const;
        operator Time() const;

        Patient(const Patient &) = delete;
        Patient(int NUM = 0, bool flag = false);
        ~Patient();

        virtual char type() const = 0;
        bool fileIO() const;
        void fileIO(bool);

        void operator=(const Patient &) = delete;
        bool operator==(char) const;
        bool operator==(const Patient &) const;
        void getSpecs(std::istream &);
        void setArrivalTime();

        std::ostream &write(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
        std::ostream &csvWrite(std::ostream &ostr) const;
        std::istream &csvRead(std::istream &istr);
    };
}
#endif