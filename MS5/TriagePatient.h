// Milestone: 4
// Date: 2021/4/4
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"

namespace sdds
{

    class TriagePatient : public Patient
    {
    private:
        char *m_symptoms;

    public:
        TriagePatient();
        char type() const;
        std::ostream &csvWrite(std::ostream &ostr) const;
        std::istream &csvRead(std::istream &istr);
        std::ostream &write(std::ostream &ostr) const;
        std::istream &read(std::istream &istr);
        ~TriagePatient();
    };
}
#endif // !SDDS_TRIAGEPATIENT_H
