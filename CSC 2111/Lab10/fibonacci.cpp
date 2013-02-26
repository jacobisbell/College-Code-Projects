/*--- fibonacci.cpp --------------------------------------------------------
   Program to compute the Fibonacci function both
   iteratively and recursively.

   Input:  a positive integer x
   Output: the x-th Fibonacci number

  Written by:   Larry R. Nyhoff
                 
  Add your name here and other info requested by your instructor.

  -------------------------------------------------------------------------*/

#include <iostream>
#include "Timer.h"

using namespace std;

Timer nonRecTimer;
Timer recTimer;


unsigned iterFibonacci(unsigned n);
/*---------------------------------------------------------
   An iterative (nonrecursive) Fibonacci number calculator
  
   Precondition:  n >= 1.
   Postcondition: n-th Fibonacci number is returned.
 ------------------------------------------------------------*/

unsigned recFibonacci(unsigned n);
/*---------------------------------------------------------
   A recursive) Fibonacci number calculator
  
   Precondition:  n >= 1.
   Postcondition: n-th Fibonacci number is returned.
 ------------------------------------------------------------*/


int main()
{
   unsigned x;

   cout << "Please enter a positive integer: ";
   cin >> x;
  
   // Now print the result of the iterative version of the function
   nonRecTimer.start();
   cout << "Iterative fib(" << x << ") = " << iterFibonacci(x) << endl;
   nonRecTimer.stop();
   cout << "Non-rec took: " << nonRecTimer << endl;

   // Now print the result of the recursive version of the function
    recTimer.start();
    cout << "Recursive fib(" << x << ") = " << recFibonacci(x) << endl;
    recTimer.stop();
    cout << "Rec took: " << recTimer << endl;
}


//--- Definition of iterFibonacci()
unsigned iterFibonacci(unsigned n)
{
   
   int
      nextFib = 1,        // the next Fibonacci number to be calculated
      previousFib = 1,    // the Fibonacci number before it
      beforePreviousFib;  // the Fibonacci number before that one

   for (int i = 3; i <= n; i++)
   {
      // First, update the previous and before previous values
      beforePreviousFib = previousFib;
      previousFib = nextFib;

      // Then compute the next Fibonacci value
      nextFib = previousFib + beforePreviousFib;
   }


   return nextFib;

}


//--- Definition of recFibonacci()
unsigned recFibonacci(unsigned n)
{

   if (n == 1 || n == 2)
      return n = 1;

   else
   {
      return recFibonacci((n-2)) + recFibonacci((n-1));
   }
}

















