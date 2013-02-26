// Jacob Isbell
// 2101 - 003
// Lab 4 Part 1 - Determine whether or not even number entered

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{

   int value, modulusResult, evenAdd;

   cout << "Please enter an integer :";
   cin >> value;
   
   evenAdd = value;
   
   modulusResult = value % 2;
   
   if (modulusResult == 0)
      evenAdd = value + 1;
      
   cout << evenAdd << endl;
   
   return 0;
}

