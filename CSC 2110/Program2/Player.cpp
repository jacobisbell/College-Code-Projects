#include "Player.h"
#include <iostream>
#include <iomanip>   //need for setw function

string Player::getNameNOCOL()
{
   return playerName;               
}


string Player::getName()
{
                                   //need to append colon here to make spacing
   return playerName + ":";        //work out in the Game.cpp
}

void Player::playerLoses(string playerName)
{
   cout << playerName << " loses.";
   cout << endl;
}
      
void Player::playerWins (string playerName)
{
   cout << playerName << " wins.";
   cout << endl;
}

Player::Player()  //default player creator
{
   busted = false;
   numCards = 0;
   cout << "Enter player name: ";
   cin >> playerName;
}

Player::Player(string name)   //player creator for house player
{
   busted = false;
   numCards = 0;
   playerName = name;
}


void Player::addCard(Card *card)
{
   if (card->inHand)
   {
      cerr << "Card is already in hand" << endl;
      return;
   }
   Card* temp = hand;
   hand = new Card[++numCards];
   for (int i = 0; i < (numCards-1); i++)
      hand[i] = temp[i];
   hand[numCards-1] = *card;
   card->inHand = true;
}

void Player::printCards()
{
   int total = 0;
   for (int i = 0; i < numCards; i++)
   {
      if (hand[i].Type == 10 + 48)     //handling ASCII character (colon) 10
         cout << setw(5) << "10";
      else
         cout << setw(5) << hand[i].Type;

      if (hand[i].Suite == 's')
         cout << "♠";
      else if (hand[i].Suite == 'c')
         cout << "♣";
      else if (hand[i].Suite == 'h')
         cout << "♥";
      else if (hand[i].Suite == 'd')
         cout << "♦";

         total += hand[i].Value;
   }
   cout << setw(3) << "(" << total << ")";
}

void Player::printHouseCards()
{
   int total = 0;
   
   cout << " " << setw(5) << "XX";
   
   for (int i = 1; i < numCards; i++)
   {
      if (hand[i].Type == 10 + 48)     //handling ASCII character (colon) 10
         cout << setw(5)  << "10";
      else
         cout << setw(5) << hand[i].Type;
         
      if (hand[i].Suite == 's')
         cout << "♠";
      else if (hand[i].Suite == 'c')
         cout << "♣";
      else if (hand[i].Suite == 'h')
         cout << "♥";
      else if (hand[i].Suite == 'd')
         cout << "♦";
         
         cout << " ";
   }
}


int Player::getPoints()
{
   int total = 0;
   for (int i = 0; i < numCards; i++)
   {
         total += hand[i].Value;
   }

   return total;

}





