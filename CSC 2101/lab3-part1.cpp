//Jacob Isbell 9/13/11 Lab 3 Part 1 This figures the number of pizza slices

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   double diameter, area, slices, pi;
   
   pi = 3.14159;                                   //define pi
   
   cout << "What is the diameter of the pizza in inches? :";
   cin >> diameter;
   //area = ((diameter * diameter) * pi)/4;                           //find area of the pizza
  double radius = diameter/2;
  area = pi*(radius*radius);
  slices = area/14.125;
   cout << "The total number of pizza slices is:";
   cout << setprecision(0) << slices << endl;
   
   return 0;
   
}
