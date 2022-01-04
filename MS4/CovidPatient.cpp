// Milestone: 4
// Date: 2021/4/4
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <iostream>
#include "CovidPatient.h"

namespace sdds
{

   int nextCovidTicket{1};

   CovidPatient::CovidPatient() : Patient(nextCovidTicket)
   {
      nextCovidTicket++;
   }

   std::istream &CovidPatient::csvRead(std::istream &istr)
   {
      Patient::csvRead(istr);
      nextCovidTicket = Patient::number() + 1;
      return istr;
   }

   std::ostream &CovidPatient::write(std::ostream &ostr) const
   {
      if (fileIO())
      {
         csvWrite(ostr);
      }
      else
      {
         ostr << "COVID TEST" << std::endl;
         Patient::write(ostr);
         ostr << std::endl;
      }
      return ostr;
   }

   std::istream &CovidPatient::read(std::istream &istr)
   {
      return fileIO() ? csvRead(istr) : Patient::read(istr);
   }

   char CovidPatient::type() const
   {
      return 'C';
   }

}