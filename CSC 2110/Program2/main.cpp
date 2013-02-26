//Jacob Isbell

#include <iostream>
#include <iomanip>
#include <cmath>

#include "Game.h"

using namespace std;

int main()
{
   Game* blackjack;
   
   cout << endl;
   cout << setw(35) << right << "Welcome to Blackjack!" << endl << endl << endl;

   blackjack = new Game();
   delete blackjack;

while(true)
{
   cout << "Do you want to play again? (Y/N): ";
   char choice;
   cin >> choice;
   if (choice == 'N' || choice == 'n')
   {
      cout << "Thanks for playing!" << endl << endl; 
      break;
   }
   cout << endl;
   blackjack = new Game();
   delete blackjack;
}
   return 0;
}
