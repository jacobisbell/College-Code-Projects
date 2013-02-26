// Jacob Isbell
// 2101 - 003
// Lab 4 Part 2 - Determine which dates are magic!


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{

   int month, day, year;
   
   cout << "Please enter date as you are prompted:" << endl;
   
   cout << "Month :";
   cin >> month;
   
   cout << "Day :";
   cin >> day;
   
   cout << "Year :";
   cin >> year;
   
   cout << endl;
   
   
   if ( month * day == year)
      cout << "You have entered a Magic Date!" << endl << endl;
      
   else 
      cout << "There is nothing magic about this date!" << endl << endl;
      
   return 0;
}

