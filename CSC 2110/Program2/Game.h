#include <iostream>
#include "Player.h"

using namespace std;

class Game
{

   public:
   
   Game();
   
   private:
   
   void InitDeck();
   void RandomizeDeck();
   void LogicLoop();

   Card Deck[52];
   Player* players;
   Player* house;
   int numPlayers;
   
};


