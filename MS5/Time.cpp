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
        char i = '\0';
        int hrs = 0;
        int mins = 0;

        istr >> hrs;
        if (hrs < 0)
        {
            istr.setstate(ios::failbit);
            return istr;
        }
        istr >> i;
        if (i != ':')
        {
            istr.setstate(ios::failbit);
            return istr;
        }
        istr >> mins;
        if (mins < 0)
        {
            istr.setstate(ios::failbit);
            return istr;
        }

        m_minutes = hrs * 60 + mins;
        return istr;
    }

    Time &Time::operator-=(const Time &D)
    {
        int minsDay = 24 * 60;
        int minA = (int)(*this);
        int minB = (int)(D);
        int diff = (((minA - minB) % minsDay) + minsDay) % minsDay;
        m_minutes = diff;

        return *this;
    }

    Time Time::operator-(const Time &D) const
    {
        int minsDay = 24 * 60;
        Time ret;
        int minA = (int)(*this);
        int minB = (int)(D);
        int diff = (((minA - minB) % minsDay) + minsDay) % minsDay;
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