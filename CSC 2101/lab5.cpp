//Jacob Isbell
// Lab 5 CSC 2101


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{

   int maritalStatus, income;
   char first[16], last[16];
   double tax;
   
   cout << "Enter (1) if you are single, (2) if you are married." << endl;
   cin >> maritalStatus;
   
   if (maritalStatus == 1 || maritalStatus == 2)
   {
      
      cout << "Please enter your first and last name: ";
      cin >> first >> last;
      
      cout << "Please enter your taxable income: ";
      cin >> income;
      
      if (maritalStatus == 1)
      {
         if (income <= 10000)
             tax = .1 * income;
         else if (income >= 10001 && income <= 40000)
            tax = .15 * income;
         else if (income >= 40001 && income <= 60000)
            tax = .20 * income;
         else
            tax = .25 * income;
      
      }
      
      else
      {
         if (income <= 20000)
            tax = .1 * income;
         else if (income >= 20001 && income <= 60000)
            tax = .15 * income;
         else if (income >= 60001 && income <= 15000)
            tax = .20 * income;
         else
            tax = .25 * income;
      
      }
      
      
      cout << first << " " << last << ": Your 2011 income tax is " << tax << " dollars." << endl;   
                     
   }
   
   else
      cout << "Invalid filing category" << endl;
      
   return 0;

}
