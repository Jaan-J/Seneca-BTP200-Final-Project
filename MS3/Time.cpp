// Milestone: 3
// Date: 2021/3/27
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <string>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{
    Time::Time(unsigned int minutes)
    {
        m_minutes = minutes;
    }

    Time &Time::setToNow()
    {
        m_minutes = getTime();
        return *this;
    }

    std::ostream &Time::write(std::ostream &ostr) const
    {
        unsigned int hours = m_minutes / 60;
        unsigned int mins = m_minutes - hours * 60;
        if (hours < 10)
            ostr << "0";
        ostr << hours << ":";
        if (mins < 10)
            ostr << "0";
        ostr << mins;
        return ostr;
    }
    std::istream &Time::read(std::istream &istr)
    {
        string inputTime;
        int hours;
        int minutes;

        istr >> inputTime;
        if (inputTime.length() == 0)
        {
            istr.setstate(ios::failbit);
            return istr;
        }
        for (int i = 0; inputTime[i] != '\0'; i++)
        {
            if (inputTime[i] != ':' && (inputTime[i] < '0' || inputTime[i] > '9'))
            {
                istr.setstate(ios::failbit);
                return istr;
            }
        }

        hours = stoi(inputTime.substr(0, inputTime.find(':')));
        minutes = stoi(inputTime.substr(inputTime.find(':') + 1));

        if (minutes < 0 || hours < 0)
            istr.setstate(ios::failbit);
        else
            m_minutes = hours * 60 + minutes;
        return istr;
    }
    Time &Time::operator-=(const Time &D)
    {
        int minDaily = 24 * 60;
        int minA = (int)(*this);
        int minB = (int)(D);
        int diff = (((minA - minB) % minDaily) +minDaily) %minDaily;
        m_minutes = diff;

        return *this;
    }
    Time Time::operator-(const Time &D) const
    {
        int minDaily = 24 * 60;
        Time ret;
        int minA = (int)(*this);
        int minB = (int)(D);
        int diff = (((minA - minB) %minDaily) +minDaily) %minDaily;
        ret.m_minutes = diff;
        return ret;
    }
    Time &Time::operator+=(const Time &D)
    {
        m_minutes += D.m_minutes;
        return *this;
    }
    Time Time::operator+(const Time &D) const
    {
        Time ret;
        ret.m_minutes = m_minutes + D.m_minutes;
        return ret;
    }
    Time &Time::operator=(unsigned int val)
    {
        m_minutes = val;
        return *this;
    }
    Time &Time::operator*=(unsigned int val)
    {
        m_minutes *= val;
        return *this;
    }

    Time &Time::operator/=(unsigned int val)
    {
        m_minutes /= val;
        return *this;
    }
    Time Time::operator*(unsigned int val) const
    {
        Time ret;
        ret.m_minutes = m_minutes * val;
        return ret;
    }

    Time Time::operator/(unsigned int val) const
    {
        Time ret;
        ret.m_minutes = m_minutes / val;
        return ret;
    }
    Time::operator unsigned int() const
    {
        return m_minutes;
    }
    Time::operator int() const
    {
        return (int)m_minutes;
    }
    std::ostream &operator<<(std::ostream &ostr, const Time &D)
    {
        D.write(ostr);
        return ostr;
    }
    std::istream &operator>>(std::istream &istr, Time &D)
    {
        D.read(istr);
        return istr;
    }
}