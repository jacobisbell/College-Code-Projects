 /*--- lab7.cpp -------------------------------------------------
  Program to test class Queue.

  Input (keyboard): Commands entered by the user.
  Output (screen):  List of commands and messages describing
                    the effects of each command.
  
  Written by:   Larry R. Nyhoff
   
                              Lab #7
  ------------------------------------------------------------------*/

#include <iostream>
#include <cctype>
using namespace std;

#include "Queue.h"


void showCommands()
/*--------------------------------------------------------------
  Function to list the available commands.
----------------------------------------------------------------*/
{
   cout << "Use the following commands to test the Queue class:\n"
        << "a --- add an element to the queue\n"
        << "d --- display contents of queue\n"
        << "e --- test whether a queue is empty\n"
        << "f --- retrieve the item at the front of the queue\n"
        << "h --- help -- print this list of commands\n"
        << "r --- remove item from front of the queue\n"
        << "q --- quit testing\n"
        << "u --- dump the queue (i.e. remove everything)\n";
}

int main()
{
   QueueElement item;      // item to add to the queue
   char command;           // user command (selected from menu)
   Queue q;                // The QUEUE

   for (int i = 1; i <= QUEUE_CAPACITY - 1; i++)
      q.enqueue(i);
   cout << "Here is the queue:\n";
   q.display(cout);
   cout << "It is full.\n\n";

   showCommands();
   do
   {
      cout << "Command? ";
      cin >> command;
      if (isupper(command)) command = tolower(command);

      switch(command)
      {
         case 'a':
                   cout << "Enter item to add to queue: ";
                   cin >> item;
                   q.enqueue(item);
                   cout << "--> " << item << " added\n";
                   break;
         case 'd': 
                   cout << "--> Queue contents:\n";
                   q.display(cout);
                   break;
         case 'e':
                   cout << "--> Queue " << (q.empty() ? "is" : "is not")
                        << " empty\n";
                   break;
         case 'f':
                   cout << "--> " << q.front() << " is at the front\n";
                   break;
         case 'h':
                   showCommands();
                   break;
         case 'r': 
                   cout << "Removing front element from the queue\n";
                   //q.dequeue();
                   break;
         case 'q':
                   cout << "--> End of test\n";
                   break;
         case 'u':
                   while ( !q.empty() )
	               //   q.dequeue();
                   cout << "--> Queue dumped\n";
                   break;
         default:
                cout << "*** Illegal command: " << command << endl;
      }
   }
   while (command != 'q');
}
