#include <iostream>
#include "Card.h"

using namespace std;

class Player
{

   public:
      void createPlayers(int);      //takes number of players and creates them
      void playerLoses(string);   
      void playerWins (string);
      void printCards();
      void addCard(Card *card);
      void printHouseCards();
      
      int getPoints();
      string getName();
      string getNameNOCOL();

      Player();
      Player(string name);
      
      bool busted;

   private:
      string playerName;
      
      Card* hand;
      int numCards;
     
};



