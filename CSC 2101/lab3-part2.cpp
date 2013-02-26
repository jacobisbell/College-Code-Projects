//Jacob Isbell 9/13/11 Lab 3 Part 2 This figures total purchase of apples

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{  
   
   double price, quantity, amount, tax, total;
   
   cout << "Price of apples/pound = $";
   cin >> price;
   
   cout << "Quantity of apples purchased = ";
   cin >> quantity;
   
   amount = price * quantity;
   
   tax = .0975 * amount;
   
   total = amount + tax;
   
   cout << "Price/lb: ";
   cout << setw(8) << setprecision(2) << fixed << right << "$" << price << endl;
   
   cout << "Quantity:";
   cout << setw(13) << setprecision(2) << fixed << right << quantity << "lbs" << endl;
   
   cout << "Amount:";
   cout << setw(11) << setprecision(2) << fixed << right << "$" << amount << endl;

   cout << "Tax:";
   cout << setw(14) << setprecision(2) << fixed << right << "$" << tax << endl;
   
   cout << "Total Purchase:";
   cout << setw(3) << setprecision(2) << fixed << right << "$" << total << endl << endl;
   
   return 0;

}
