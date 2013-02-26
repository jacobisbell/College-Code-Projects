#include <iostream>
#include <iomanip>
#include <cmath>
#include "airport.h"

int main()     //Calls Airport function and handles looping of program
{

   while (true)
   {

      char userResponse;

      Airport simulation;

      cout << endl;
      cout << "Would you like to run a new simulation? y/n" << endl;
      cin >> userResponse;
      cout << endl;

      if (userResponse == 'N' || userResponse == 'n')
         break;

   }

   cout << "Thanks for choosing AirSimPro for all of your airport";
   cout << " simulation needs!";
   cout << endl << endl << endl;

   return 0;

}