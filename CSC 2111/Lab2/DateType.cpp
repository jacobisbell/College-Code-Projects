// File DateType.cpp  contains the implementation of class DateType
#include "DateType.h"
#include <fstream>
#include <iostream>
using namespace std;

// Nmber of days in each month
static int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30,
                            31, 30, 31};	

// Nmaes of the months
static string conversionTable[] = {"Error", "January", "February", 
    "March", "April", "May", "June", "July", "August", "September",
    "October", "November", "December"};

void DateType::Initialize (int newMonth, int newDay, int newYear)
// Post: If newMonth, newDay and newYear represent a valid date,
//       year is set to newYear;
//       month is set to newMonth;
//       day is set to newDay;
//       otherwise a string exception is thrown, stating the
//       first incorrect parameter.
//
// Note:  Years must be 1900 or sooner.
//
{  
   if (newYear >= 1900 && newMonth <= 12 && newMonth > 0 && newDay > 0 && newDay <= daysInMonth[newMonth])
   {
      year = newYear;
      month = newMonth;
      day = newDay;
   }
   
   if (newYear >= 1900)
      cout << "The year entered is not valid. It must be later than 1900." << endl;
      
   else if (newMonth > 12 || newMonth <= 0)
      cout << "The month entered is not valid. It must be in between 1 and 12." << endl;
      
   else if (newDay <= 0 || newDay > 31)
      cout << "The day entered is not valid. It must be in between 1 and 31." << endl;
   
}

int DateType::GetMonth() const
// Accessor function for data member month.
{
   return month;
}

string DateType::GetMonthAsString() const
// Returns data member as a string
{

   return conversionTable[month];
   
}

int DateType::GetYear() const
// Accessor function for data member year.
{
   return year;
}

int DateType::GetDay() const
// Accessor function for data member day.
{
   return day;
}

bool DateType::leapYear(int year) const
//
// To check if it is leap year you must check
// if it is divisible by 4 and not a multiple
// of 100 unless it is 400.
// You must change Febuary to 29 days.
//
{
   bool leapYearBool = false;
   
   if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
       leapYearBool = true;
   return true;

}

DateType DateType::Adjust(int daysAway) const
// Pre:  Self has been initialized
// Post: Function value = newDate daysAway from self
{
   int newDay = day + daysAway;
   int newMonth = month;
   int newYear = year;
   bool finished = false;
   
   while (finished == false)
   {
      int daysInThisMonth = daysInMonth[newMonth];
      if (newMonth = 2)
         {
            if (leapYear(newYear))
               daysInThisMonth++;
         }
         
      if (newDay <= daysInThisMonth)
         finished = true;
      
      else
      {
         newDay = newDay - daysInThisMonth;
         newMonth = (newMonth % 12) + 1;
         
         if (newMonth = 1)
            newYear++;
      }
   }
   
   DateType returnDate.initialize(newMonth, newDay, newYear)
   return returnDate;

}








