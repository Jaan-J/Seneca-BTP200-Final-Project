// Milestone: 2
// Date: 2021/3/22
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>

namespace sdds
{
    class Menu
    {
        char *m_text;
        int m_noOfSel;
        void display() const;
        void setText(const char *);

    public:
        Menu(const char *MenuContent, int NoOfSelections);
        virtual ~Menu();
        int &operator>>(int &Selection);
        Menu(const Menu &);
    };
}
#endif
