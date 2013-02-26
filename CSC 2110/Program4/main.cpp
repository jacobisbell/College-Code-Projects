//Program 4 by Jacob Isbell 2012

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include "BST.h"

using namespace std;

Tree gameTree;    //Create instance of class Tree

int main()
{

   //Pretty welcome message!

   cout << endl;
   cout << endl;
   cout << "---------------------------------------------------------" << endl;
   cout << "Hi, my name is Brown. I am a program that combines " << endl;
   cout << "persistent data storage, binary search trees, recursion " << endl;
   cout << "and an expandable working library of mammals to create a " << endl;
   cout << "mini version of the classic 20-questions game we have all" << endl;
   cout << "come to know and love." << endl << endl;
   cout << "All you have to do is to follow the simple prompts" << endl;
   cout << "throughout the program to play! If you are thinking of" << endl;
   cout << "an animal that I don't know about, I will ask you to" << endl;
   cout << "input the animal and I will save that for future games!" << endl;
   cout << "---------------------------------------------------------" << endl;
   cout << endl;
   cout << endl;

   gameTree.playGame();    //Call to the main playGame function in Tree class

   cout << endl << endl;
   cout << "------    ";
   cout << "Well, it was fun while it lasted wasn't it?" << endl;
   cout << "------    ";
   cout << "Hey! At least all of the data is saved so we" << endl;
   cout << "------    ";
   cout << "don't have to start from scratch next time!" << endl;
   cout << "------    ";
   cout << "Have a great day." << endl;
   cout << "------    ";
   cout << "                             Sincerely," << endl;
   cout << "------    ";
   cout << "                                    Brown" << endl;
   cout << endl << endl << endl;

   return 0;

}


