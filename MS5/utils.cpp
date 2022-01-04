// Milestone: 5
// Date: 2021/4/8
// Author: Jaan Javed
// Student Number: 100131192
///////////////////////////////////////////////////
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"

using namespace std;
namespace sdds
{
   bool debug = false;

   int getInt(const char *prompt)
   {
      string userEntry;
      int flag{0};
      int num;
      bool foundNum = false;
      bool negInt = false;

      if (prompt != nullptr)
         cout << prompt;
      getline(cin, userEntry);
      userEntry = userEntry + '\n';

      while (flag == 0 || flag == 1)
      {
         num = 0;
         int i{0};
         negInt = false;
         foundNum = false;
         while (userEntry[i])
         {
            if (userEntry[i] == '-')
               negInt = true;
            else if (userEntry[i] < '0' || userEntry[i] > '9')
            {
               if (foundNum == false)
               {
                  flag = 0;
               }
               else if (userEntry[i] == '\n')
                  flag = 2;
               else
                  flag = 1;
               break;
            }
            else
            {
               foundNum = true;
               num = num * 10 + userEntry[i] - '0';
            }
            i++;
         }
         if (negInt)
            num = 1 * num;
         if (flag != 2)
         {
            if (flag == 0)
               cout << "Bad integer value, try again: ";
            else
               cout << "Enter only an integer, try again: ";
            getline(cin, userEntry);
            userEntry = userEntry + '\n';
         }
      }
      return num;
   }

   int getInt(int min, int max, const char *prompt, const char *errorMessage, bool showRangeAtError)
   {
      int flag = 0;
      bool foundNum = false;
      int num;
      string userEntry;
      bool negInt = false;

      if (prompt != nullptr)
         cout << prompt;
      getline(cin, userEntry);
      userEntry = userEntry + '\n';

      while (flag == 0 || flag == 1)
      {
         negInt = false;
         int i{0};
         foundNum = false;
         num = 0;

         while (userEntry[i])
         {
            if (userEntry[i] == '-')
               negInt = true;
            else if (userEntry[i] < '0' || userEntry[i] > '9')
            {
               if (foundNum == false)
                  flag = 0;
               else if (userEntry[i] == '\n')
                  flag = 2;
               else
                  flag = 1;
               break;
            }

            else
            {
               foundNum = true;
               num = num * 10 + userEntry[i] - '0';
            }
            i++;
         }
         if (negInt)
            num = -1 * num;
         if (flag != 2)
         {
            if (flag == 0)
               cout << "Bad integer value, try again: ";
            else
               cout << "Enter only an integer, try again: ";
            getline(cin, userEntry);
            userEntry = userEntry + '\n';
         }
         else if (num < min || num > max)
         {
            flag = 1;
            if (errorMessage != nullptr)
               cout << errorMessage;
            if (showRangeAtError)
            {
               cout << "[" << min << " <= value <= " << max << "]: ";
            }
            getline(cin, userEntry);
            userEntry = userEntry + '\n';
         }
      }
      return num;
   }

   char *getcstr(const char *prompt, std::istream &istr, char delimiter)
   {
      string input;
      if (prompt != nullptr)
         cout << prompt;
      getline(istr, input);
      int len = input.length();
      char *str = new char[len + 1];
      strcpy(str, input.c_str());
      str[len] = '\0';
      return str;
   }

   int getTime()
   {
      int mins{-1};
      if (debug)
      {
         Time t(0);
         cout << "Enter current time: ";
         do
         {
            cin.clear();
            cin >> t;
            if (!cin)
            {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else
            {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else
      {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
}