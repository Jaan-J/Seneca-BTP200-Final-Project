// Milestone: 2
// Date: 2021/3/22
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <cstring>
#include "Menu.h"
#include "utils.h"

using namespace std;
namespace sdds
{
    void Menu::display() const
    {
        cout << m_text << endl;
        cout << "0- Exit" << endl;
    }

    void Menu::setText(const char *text)
    {
        int len = strlen(text);
        m_text = new char[len + 1];
        strcpy(m_text, text);
        m_text[len] = '\0';
    }

    Menu::Menu(const char *MenuContent, int NoOfSelections)
    {
        setText(MenuContent);
        m_noOfSel = NoOfSelections;
    }

    Menu::~Menu()
    {
        delete[] m_text;
    }

    Menu::Menu(const Menu &other)
    {
        setText(other.m_text);
        m_noOfSel = other.m_noOfSel;
    }

    int &Menu::operator>>(int &Selection)
    {
        display();
        int value = getInt(0, m_noOfSel, "> ", "Invalid option ");
        Selection = value;
        return Selection;
    }
}