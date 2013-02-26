#include "Game.h"
#include <time.h>
#include <cstdlib>
#include <iomanip>

int j = 0;  //global declaration of varilable so place in array of cards can be
            //maintained between/across functions

void Game::InitDeck()
{

   for (int i = 0; i < 52; i++)
   {
      if (i < 36)                      //Initializes all numeric cards in the
      {                                //four suites
         Deck[i].Type = i % 9 + 50;
         Deck[i].Value = Deck[i].Type - 48;
         if (i < 9)
            Deck[i].Suite = 'c';
         else if (i >= 9 && i < 18)
            Deck[i].Suite = 'd';
         else if (i >= 18 && i < 27)
            Deck[i].Suite = 'h';
         else if (i >= 27 && i < 36)
            Deck[i].Suite = 's';
      }
      else if (i >= 36)
      {
         char currentSuite;
         if (i >= 36 && i < 40)
            currentSuite = 'c';
         else if (i >= 40 && i < 44)
            currentSuite = 'd';
         else if (i >= 44 && i < 48)
            currentSuite = 'h';
         else if (i >= 48 && i < 52)
            currentSuite = 's';
         Deck[i].Type = 'A';
         Deck[i].Suite = currentSuite;
         Deck[i].Value = 1;
         i++;
         Deck[i].Type = 'K';
         Deck[i].Suite = currentSuite;
         Deck[i].Value = 10;
         i++;
         Deck[i].Type = 'Q';
         Deck[i].Suite = currentSuite;
         Deck[i].Value = 10;
         i++;
         Deck[i].Type = 'J';
         Deck[i].Suite = currentSuite;
         Deck[i].Value = 10;
      }      
   }
}

void Game::RandomizeDeck()
{
   srand(time(0));
   for (int i = 0; i < 1024; i++)
   {
      int tmp = rand() % 52;
      int tmp2 = rand() % 52;
      Card temp = Deck[tmp];
      Deck[tmp] = Deck[tmp2];
      Deck[tmp2] = temp;
   }
}

void Game::LogicLoop()
{
   
   int k = 0;
   
   cout << endl;  //provides spacing after user inputs name(s)
   
      char hitResponse;
   
      for (k; k < numPlayers; k = k + 0)   //asks user for hit or stand
      {
      
         bool anotherHit = true;
         
         while (anotherHit == true)
         {
            cout << players[k].getNameNOCOL();
            cout << ", do you want a hit?  (Y/N): ";
            cin >> hitResponse;
         
            if (hitResponse == 'Y' || hitResponse == 'y')
            {
               players[k].addCard(&Deck[j]);   //add new card to player
               j++;
               
               //print player and cards again
               cout << setw(10) << left << players[k].getName() << right;
               players[k].printCards();
               cout << endl;
               
               int points;
               
               points = players[k].getPoints();
               
               if (points > 21)
               {
                  players[k].busted = true;
                  cout << players[k].getNameNOCOL() << " busts." << endl;
                  cout << endl;
                  k = k+1;
                  anotherHit = false;
                  break;
               }   
            }
            
            else
            {
               cout << endl;
               k = k+1;
               anotherHit = false;
            }
         }
   }
   
   cout << setw(10) << left << "House:" << right;
   house->printCards();
   cout << endl;    
   
   while ((house->getPoints()) <= 16)
   {
      house->addCard(&Deck[j]);  //Gives house another card
      j++;
   }
   
   if (house->getPoints() > 21)
      house->busted = true;
   cout << setw(10) << left << "House:" << right;
   house->printCards();
   cout << endl << endl;
   
   
   
   int winningPlayer= 0;
   for (int i = 0; i < numPlayers; i++)
      if (players[winningPlayer].busted)
         winningPlayer++;
   int winningdiff = 21 - players[winningPlayer].getPoints();
   bool istie = false;
   for (int i = 1; i < numPlayers; i++)
   {
      if (players[i].busted == false)
      {
         int diff = (21 - players[i].getPoints());
         if (diff < winningdiff)
         {
            winningPlayer = i; 
            istie = false;
         }
         else if (diff == winningdiff)
            istie = true;
      }
   }
   
   if ((((21 - players[winningPlayer].getPoints()) < (21 - house->getPoints())) || house->busted) && !istie)
   {
      for (int k = 0; k < numPlayers; k++)
      {
         if (players[k].busted == false)
         {
            if (k == winningPlayer)
            {
               cout << players[k].getNameNOCOL();
               cout << " wins.";
            }
            else
            {
               cout << players[k].getNameNOCOL();
               cout << " loses.";
            }
            cout << endl;
         }
      }
   }   
   else
   {
      for (int k = 0; k < numPlayers; k++)
      {
          if (players[k].busted == false)
          {
             cout << players[k].getNameNOCOL();
             cout << " loses.";
             cout << endl;
          }
      }
   }
   
   cout << endl;
}

Game::Game()
{

   while (true)
   {
      cout << "How many players? (1 - 4): ";
      cin >> numPlayers;
      
      //input validation
      if (numPlayers < 1 || numPlayers > 4)
         cout << "Please re-enter a number of players between 1 and 4." << endl;   
      else
         break;
   }

   players = new Player[numPlayers];   //creates players
   
   house = new Player("house");
   
   InitDeck();
   
   RandomizeDeck();
   
   
   for (int i = 0; i < numPlayers; i++)
   {
      players[i].addCard(&Deck[j]);
      j++;
      players[i].addCard(&Deck[j]);
      j++;
      
      if (i == 0)
      {
         house->addCard(&Deck[j]);
         j++;
         house->addCard(&Deck[j]);
         j++;
      }
   }
   
   cout << endl;
   
   for (int i = 0; i < numPlayers; i++)   //prints player names and cards
   {                                        
      cout << setw(10) << left << players[i].getName() << right;
      players[i].printCards();
      cout << endl;   
   }
   
   cout << setw(10) << left << "House:" << right;
   house->printHouseCards();
   cout << endl;   
 
   LogicLoop();
   
   //for (int i = 0; i < 52; i++)
   //   cout << Deck[i].Type << "   " << Deck[i].Suite << endl;
   
   
}
