//Jacob Isbell - Program 4 - CSC 2110

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

#include "BSTNode.h"

using namespace std;

struct NodeType;                 //Node structure declaration

typedef NodeType * NodePointer;  //Sets node pointer to type NodeType pointer

class Tree
{

public:

   Tree();                                   //Default constructor definition
   void treeInsert(NodePointer);  //Constructs tree from file
   void treeSave(NodePointer);
   void playGame();

private:

   NodePointer taxonomy_root_ptr;            //Points to tree root
   NodePointer ptrLoc;

   ifstream streamInput;                           //Input stream for file
   ofstream streamOutput;                          //Output stream for file
   
   string userAnimal;
   bool boolPlayAgain;


};


Tree::Tree()                     //Default constructor for class "Tree"
{                       
   taxonomy_root_ptr = new NodeType();
   ptrLoc = NULL;
   boolPlayAgain = true;
}


//----- Handles reading data from file using standard stream function
//----- Some code referenced from 
//----- http://www.cplusplus.com/reference/iostream/ifstream/
void Tree::treeInsert(NodePointer passedNode)
{
   passedNode->isQuestion = false;

   string currentLine;

   getline(streamInput, currentLine);

   if (currentLine.length() == 0)
   {
      return;
   }

   //don't need else statement

   if (currentLine[0] == '1')
   {
      passedNode->isQuestion = true;
   }

   int lineLength;

   lineLength = (currentLine.size() - 1);    //Returns size - 1 for reading
                                             //purposes in next line

   passedNode->info = currentLine.substr(1, lineLength);
   //Refereced from http://www.cplusplus.com/reference/string/string/substr/
   
   if (passedNode->isQuestion)
   {
      passedNode->left = new NodeType();
      passedNode->right = new NodeType();

      treeInsert(passedNode->left);      //recursion!
      treeInsert(passedNode->right);     //recursion!
   }

   //else it will exit function

}

//----- Handles writing data to file using standard stream function
void Tree::treeSave(NodePointer passedNode)
{
   streamOutput << passedNode->isQuestion;
   streamOutput << passedNode->info;
   streamOutput << endl;

   if (passedNode->isQuestion)
   {
      treeSave(passedNode->left);       //recursion!
      treeSave(passedNode->right);      //recursion!
   }

//   else

}



//----- Main function for the game that handles nearly all user interaction and
//----- game logic. 
void Tree::playGame()
{
   while(boolPlayAgain)
   {

      ptrLoc = taxonomy_root_ptr;

      streamInput.open("database.dat");                     //Static database file
      if (streamInput.good())                               //name (no user input)
         treeInsert(taxonomy_root_ptr);
      else
      {
         cout << "The default database file was ";    //handles exception
         cout << "not able to be opened." << endl;    //incase file      

// Didn't have time to get working... would of been cool though.

         char createNewResponse;

         cout << "Would you like me to create a new database file? (y/n)";
         cin >> createNewResponse;

         if (createNewResponse == 'y' || createNewResponse == 'Y')
         {
            cout << "Ok, I'll create a new database file." << endl;

            ofstream defaultFile;
            defaultFile.open ("database.dat");

            defaultFile << "1Are you a mammal?" << endl;
            defaultFile << "1Are you bigger than a cat?" << endl;
            defaultFile << "1Are you a marsupial" << endl;
            defaultFile << "0kangaroo" << endl;
            defaultFile << "1Are you taller than a tiger?" << endl;
            defaultFile << "0giraffe" << endl;
            defaultFile << "0monkey" << endl;
            defaultFile << "0mouse" << endl;
            defaultFile << "1Do you live underwater?" << endl;
            defaultFile << "0trout" << endl;
            defaultFile << "0robin" << endl;

            defaultFile.close();

            treeInsert(taxonomy_root_ptr);

         }

         else
         {
            cout << "exiting..." << endl;
            break;
         }

      }
      

      streamInput.close();

      char userResponse;                                        

      while(ptrLoc->isQuestion == true)   //While there is still a question and
      {                                   //not an answer to be printed/guessed
         cout << endl;
         cout << ptrLoc->info;            //Will print question in node
         cout << " (y/n)" << endl;
         cin >> userResponse;             //Will hold user's response

         if (userResponse == 'y' || userResponse == 'Y')
            ptrLoc = ptrLoc->left;

         else
            ptrLoc = ptrLoc->right;
      }

      //Once the program gets here, it will have found an answer, not 
      //necessarily the right one, but it will have one.

      if (ptrLoc->info != "")
      {
         cout << "Are you a " << ptrLoc->info << " ?";
         cout << " (y/n)" << endl;
         cin >> userResponse;
      }

      if (userResponse == 'n' || userResponse == 'N')
      {
         cout << "Wow! I'm wrong. You win. Just so I know next time, what ";
         cout << "animal are you? ";

         cin >> userAnimal;

         if (ptrLoc->info != "")
         {
            cout << "Please type a y/n question that will distinguish a ";

            string userQuestion; //String to store user's response

            cout << userAnimal << " from a " << ptrLoc->info << " . ";

            cin.ignore(1000, '\n');           //Have to flush input buffer!!!
                                              //took me forever to figure that
            getline (cin, userQuestion);
         //Referenced from: http://www.cplusplus.com/reference/string/getline


            cout << "As a " << userAnimal << ", " << userQuestion << " ";
            cout << "Please answer y/n: ";

            char questionResponse;
            cin >> questionResponse;

            ptrLoc->left = new NodeType;
            ptrLoc->right = new NodeType;

            if (questionResponse == 'n' || questionResponse == 'N')
            {

            //Could of also created some temp pointers (what I did at first)
            //and use those to navigate through the tree, however, this is 
            //easier and more efficient

               ptrLoc->left->isQuestion = false;     //Very hard lines
               ptrLoc->left->info = ptrLoc->info;    //to figure out

               ptrLoc->right->isQuestion = false;
               ptrLoc->right->info = userAnimal;
            }

            else     //do the above in reverse
            {

               ptrLoc->left->isQuestion = false;
               ptrLoc->left->info = userAnimal;

               ptrLoc->right->isQuestion = false;     //Very hard lines
               ptrLoc->right->info = ptrLoc->info;    //to figure out


            }

            ptrLoc->info = userQuestion;     //Need these lines
            ptrLoc->isQuestion = true;       //otherwise program dies

         }

         else
         {
            ptrLoc->info = userAnimal;
            ptrLoc->isQuestion = false;
         }

      }

      char playAgain;

      cout << "Shall we play again y/n? ";
      cin >> playAgain;

      if (playAgain == 'n' || playAgain == 'N')
         boolPlayAgain = false;

      //You must have the next three lines of code inside the while loop!
      //Otherwise, if the user types "y", they want to play again, the data
      //entered in the current game will never be saved.
      
      streamOutput.open("database.dat");
      
      treeSave(taxonomy_root_ptr);
      
      streamOutput.close();
   }

}







