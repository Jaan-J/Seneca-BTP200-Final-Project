// Milestone: 3
// Date: 2021/3/27
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <cstring>
#include <string>
#include "utils.h"
#include "Patient.h"

namespace sdds
{
    int Patient::number() const
    {
        return object.number();
    }

    Patient::operator Time() const
    {
        return Time(object);
    }

    Patient::Patient(int NUM, bool test) : object(NUM)
    {
        flag = test;
    }
    Patient::~Patient()
    {
        delete[] m_name;
    }

    bool Patient::fileIO() const
    {
        return flag;
    }

    void Patient::fileIO(bool test)
    {
        flag = test;
    }

    bool Patient::operator==(char p) const
    {
        return p == type();
    }
    bool Patient::operator==(const Patient &obj) const
    {
        return type() == obj.type();
    }

    void Patient::setArrivalTime()
    {
        object.resetTime();
    }

    std::ostream &Patient::write(std::ostream &ostr) const
    {
        ostr << object << '\n';

        for (int i = 0; i < 25 && m_name[i]; i++)
        {
            ostr << m_name[i];
        }

        ostr << ", OHIP: ";
        ostr << m_ohip;

        return ostr;
    }

    std::istream &Patient::read(std::istream &istr)
    {
        int len;

        std::cout << "Name: ";
        std::string name;
        std::getline(istr, name);

        len = name.length();

        delete[] m_name;
        m_name = new char[len + 1];
        strcpy(m_name, name.c_str());

        m_name[len] = '\0';

        std::cout << "OHIP:";
        m_ohip = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ");

        return istr;
    }

    std::ostream &Patient::csvWrite(std::ostream &ostr) const
    {
        ostr << type() << ',';
        ostr << m_name << ',';
        ostr << m_ohip << ',';

        return object.csvWrite(ostr);
    }

    std::istream &Patient::csvRead(std::istream &istr)
    {
        int len;

        std::string name;
        std::getline(istr, name, ',');

        len = name.length();

        delete[] m_name;

        m_name = new char[len + 1];
        strcpy(m_name, name.c_str());

        m_name[len] = '\0';

        istr >> m_ohip;
        istr.ignore();

        return object.csvRead(istr);
    }
}