// Milestone: 5
// Date: 2021/4/10
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "PreTriage.h"

using namespace std;
namespace sdds
{
    PreTriage::PreTriage(const char *dataFilename) : m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
                                                     m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
    {
        int len = strlen(dataFilename);
        m_dataFilename = new char[len + 1];
        strcpy(m_dataFilename, dataFilename);
        m_dataFilename[len] = '\0';
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        load();
    }

    PreTriage::~PreTriage()
    {
        ofstream fout(m_dataFilename);
        cout << "Saving Average Wait Times," << endl;
        cout << "   COVID Test: " << m_averCovidWait << endl;
        cout << "   Triage: " << m_averTriageWait << endl;
        fout << m_averCovidWait << "," << m_averTriageWait << endl;
        cout << "Saving m_lineup..." << endl;
        for (int d = 0; d < m_lineupSize; d++)
        {
            cout << d + 1 << "- ";
            m_lineup[d]->csvWrite(cout) << endl;
            m_lineup[d]->csvWrite(fout) << endl;
        }
        for (int i = 0; i < m_lineupSize; i++)
        {
            delete m_lineup[i];
        }
        delete[] m_dataFilename;
        cout << "done!" << endl;
        fout.close();
    }

    void PreTriage::run(void)
    {
        while (true)
        {
            int choice;
            m_appMenu >> choice;
            if (choice == 0)
                return;
            if (choice == 1)
                reg();
            if (choice == 2)
                admit();
        }
    }

    void PreTriage::reg()
    {
        int choice;
        if (m_lineupSize == maxNoOfPatients)
        {
            cout << "Line up full!" << endl;
            return;
        }
        m_pMenu >> choice;
        if (choice == 0)
            return;
        if (choice == 1)
            m_lineup[m_lineupSize] = new CovidPatient();
        if (choice == 2)
            m_lineup[m_lineupSize] = new TriagePatient();
        m_lineup[m_lineupSize]->setArrivalTime();
        cout << "Please enter patient information: " << endl;
        m_lineup[m_lineupSize]->fileIO(false);
        m_lineup[m_lineupSize]->read(cin);
        cout << endl
             << "******************************************" << endl;
        cout << *m_lineup[m_lineupSize];
        cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]);
        cout << endl
             << "******************************************" << endl
             << endl;
        m_lineupSize++;
    }

    void PreTriage::admit()
    {
        int choice;
        m_pMenu >> choice;
        char type = '\0';
        if (choice == 1)
            type = 'C';
        if (choice == 2)
            type = 'T';
        if (choice == 0)
            return;
        int index = indexOfFirstInLine(type);
        if (index == -1)
            return;
        cout << endl
             << "******************************************" << endl;
        m_lineup[index]->fileIO(false);
        cout << "Calling for ";
        cout << *m_lineup[index];
        cout << "******************************************" << endl
             << endl;
        setAverageWaitTime(*m_lineup[index]);
        removePatientFromLineup(index);
    }

    const Time PreTriage::getWaitTime(const Patient &o) const
    {
        Time res;
        unsigned int sum = 0;
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (o.type() == m_lineup[i]->type())
            {
                sum++;
            }
        }
        if (o.type() == 'C')
            res = m_averCovidWait * sum;
        else
            res = m_averTriageWait * sum;
        return res;
    }

    void PreTriage::setAverageWaitTime(const Patient &p)
    {
        Time AWT = p.type() == 'C' ? m_averCovidWait : m_averTriageWait; // average wait time
        Time CT = Time(getTime());                                       // current time
        Time PTT = Time(p);                                              // patient ticket time

        unsigned int d = p.number();
        AWT = ((CT - PTT) + (AWT * (d - 1))) / d;
        if (p.type() == 'C')
            m_averCovidWait = AWT;
        else
            m_averTriageWait = AWT;
    }

    void PreTriage::removePatientFromLineup(int index)
    {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    }

    int PreTriage::indexOfFirstInLine(char type) const
    {
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (type == m_lineup[i]->type())
            {
                return i;
            }
        }
        return -1;
    }

    void PreTriage::load()
    {
        cout << "Loading data..." << endl;
        ifstream fin(m_dataFilename);
        fin >> m_averCovidWait;
        fin.ignore();
        fin >> m_averTriageWait;
        fin.ignore();
        Patient *ptr = NULL;
        for (int i = 0; i < maxNoOfPatients && fin.peek() != EOF; i++)
        {
            char d;
            fin >> d;
            if (d == 'C')
                ptr = new CovidPatient();
            if (d == 'T')
                ptr = new TriagePatient();
            if (ptr != NULL)
            {
                ptr->fileIO(true);
                fin >> *ptr;
                ptr->fileIO(false);
                m_lineup[i] = ptr;
                m_lineupSize++;
            }
        }
        if (fin.peek() != EOF)
            cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
        else if (m_lineupSize == 0)
            cout << "No data or bad data file!" << endl;
        if (m_lineupSize > 0)
            cout << m_lineupSize << " Records imported..." << endl;
        cout << endl;
    }
}