//
//  DateDr.cpp
//  For Testing DateType Class
//

#include <fstream>
#include <string>
#include <iostream>

#include "DateType.h"

using namespace std;

int main()
{
   string command;
   int month, day, year;
   DateType date, date2;
   ofstream outFile;
   int daysAway;
  
   outFile.open("date.out");
   cout << "Input a command or Quit to terminate the test" << endl;
   cin >> command;
  
   while (command != "Quit")
   {
      if (command == "Initialize")
      {
         cout << "Input a month, day, and year on one line" << endl;
         cin >> month >> day >> year;
         try
         {
            date.Initialize(month, day, year);
            outFile << command << ": " << date.GetMonthAsString() << " " << date.GetDay() << ", "
                    << date.GetYear() << endl;	
         }	
         catch(string msg)
         {
            outFile << msg << endl;
         }		
      }
      else if (command == "GetMonth")
         outFile << command << ": "<< date.GetMonth() << endl;
      else if (command == "GetMonthAsString")
         outFile << command << ": " << date.GetMonthAsString() << endl;
      else if (command == "GetDay")
         outFile << command << ": " << date.GetDay() << endl;
      else if (command == "GetYear")
         outFile << command << ": "<< date.GetYear() << endl;
      else if (command == "DaysAway")
      {
         cout << "Input days away" << endl;
         cin >> daysAway;
         date2 = date.Adjust(daysAway);
         outFile << command << endl;
         outFile << date.GetMonthAsString() << " " << date.GetDay() << ", "
                 << date.GetYear();	  
         outFile << " plus " << daysAway << " is ";
         outFile << date2.GetMonthAsString() << " " << date2.GetDay() << ", "
                 << date2.GetYear() << endl;
      }  
      else
         cout << "Unrecognized command." << endl;
      cout << "Input a command or Quit to terminate the test" << endl;
      cin >> command;
  }
	  
  outFile.close();
}  	

