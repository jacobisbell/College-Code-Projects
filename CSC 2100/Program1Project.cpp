/* Created by Jacob Isbell 
 * 10/1/2011 - CSC-2100 - Program 1
 *
 * This program is a complete loan payment calculator. 
 * 
 *    The user inputs the amount of the loan, annual interest rate in percent, number of payments per year,
 * and the total number of payments over the course of the loan's life. The program then proceedes to print
 * the headers and labels for the columns that display the resulting data from the calculations.
 *
 *    The program then prints the labels on the furthest most left column that displays what payment number
 * is being diplayed on that line. There is also a dividing line that is printed directly below the column 
 * headers to visually seperate the headers from the calculated data.
 *
 *   Basically, the program takes the user input and returns input to variables. After this is complete,
 * the values inputted are then processed through various financial formulas to obtain the final values
 * required in the program specifications. The program also keeps track of the number of loans processed in
 * a given session and returns this value when the user decides to quit the program.
 * 
 *   I also included a statement at the end of the program that outputs the result of the number of loans in
 * the correct grammar. For example, if a total of only one loan was processed it will output "There was 1
 * loan processed." However, if more than one loan was processed it will output "There were (number of loans)
 * processed."
 *   
 *   The variable sections are divided by type of variable and whether it is fed content from the user input
 * or if the variable simply holds a calculated value. This makes it easy to find variable definitions very
 * quickly and efficiently.
 *
 * End header comments
 *
*/


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{

   //Variable definitions

   double A, annualPercent; //user input vars
   double p, amountInterest, amountPrincipal, balance, newBalance, ppery, r, amountPrincipalPeriod, totalInterest, totalAmount; //calculated vars
   
   int paymentsYear, n; //user input vars
   int count, loanCount=0; //calculated vars
   
   bool newLoan = true;
   char userLoanResponse, response;
   
   while (newLoan == true)
   
   {
   
      //Loan counter
      loanCount++;
      
      //User input code
      cout << "Enter the amount of the loan $";
      cin >> A;
   
      cout << "Enter the annual percentage rate (ex. 3.75) : ";
      cin >> annualPercent;
   
      cout << "Number of payments per year : ";
      cin >> ppery;
   
      cout << "Number of total payments : ";
      cin >> n;
      
      cin.ignore(80,'\n');
      
      cout << endl;
      
      
      //Output fed from input
      cout << "Amount of Loan      $";
      cout << setw(9) << setprecision(2) << fixed << right << A << endl;
      
      cout << "Annual Interest Rate ";
      cout << setw(9) << setprecision(3) << fixed << right << annualPercent << "%" << endl;
      
      cout << "Payments per year";
      cout << setw(13) << setprecision(0) << fixed << right << ppery << endl;
      
      cout << "Total number of payments";
      cout << setw(6) << setprecision(2) << fixed << right << n << endl << endl;
      

      //Print column headers
      //top headers
      cout << fixed << right << setw(5) << "Payment";
      cout << fixed << right << setw(10) << "Payment";
      cout << fixed << right << setw(12) << "Amount";
      cout << fixed << right << setw(14) << "Amount to";
      cout << fixed << right << setw(18) << "Balance after" << endl;
      
      //bottom headers
      cout << fixed << right << setw(7) << "Number";
      cout << fixed << right << setw(10) << "Amount";
      cout << fixed << right << setw(12) << "Interest";
      cout << fixed << right << setw(14) << "Principal";
      cout << fixed << right << setw(18) << "this payment" << endl;
      
      cout << "_____________________________________________________________";
      
      cout << endl << endl;
      
      //Rate      
      r = ((annualPercent/100)/ppery); 
      
      //Payment per period
      p = ((A*pow((1+r),n)*r)/(pow((1+r),n)-1));
                  
      count = 0;
      newBalance = A;

      while (count < n)
      {
         count++;
         
         //Core math            
         amountInterest = (newBalance*r);
                  
         amountPrincipal = (p-amountInterest);
         
         newBalance = newBalance-amountPrincipal;
         
         //If balance is negative set equal to zero
         if (newBalance < 0.00)
            newBalance = 0.00;
         
         cout << setw(4) << right << count << "." << setw(12) << setprecision(2) << p << setw(12) << amountInterest << setw(14) << amountPrincipal << setw(18) << newBalance << endl;
         
         //Pause after 12 lines of output
         if (count % 12 == 0)
         {
            cout << endl;
            cout << "Hit <Enter> to continue";
            cin.get (response);
            cout << endl;
         }
      
      }
      
      cout << endl;
      totalAmount = (p*n);
      cout << setw(9) << "Total Payment Amount: $" << totalAmount << endl;
      
      totalInterest = totalAmount-A;
      cout << setw(9) << "Total Interest Payment: $" << totalInterest << endl << endl;
      
      
   
      cout << "Another loan? y/n & <Enter> : ";
      cin >> userLoanResponse;

   if (userLoanResponse == 'n')
      {
      
      newLoan = false;
      cout << endl;
      
      //Code for total loans processed output string to be grammatically correct
      if (loanCount == 1)
      {   
         cout << "There was " << loanCount << " loan processed.";
      }
      
      else
      {
         cout << "There were " << loanCount << " loans processed.";
      }
      
      cout << endl << endl;

      }
            
   }   
   
   return 0;
}
