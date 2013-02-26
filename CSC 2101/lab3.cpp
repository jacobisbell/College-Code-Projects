// Created by Jacob Isbell
// 9/13/2011
// Program 1 tells number of slices in pizza when given diameter.

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main ()
{

   double diameter, area, slices, pi;
   
   pi = 3.14159;
   
   cout << "What is the diameter of the pizza in inches? :";
   cin >> diameter;
   area = pi*diameter;
   slices = area/14.125;
   cout << "The total number of pizza slices is:";
   cout << setprecision(10) << slices;
   
   return 0;

}


