#include <iostream>
#include <string>

using namespace std;

class NodeType                  //Node structure type definition
{

   public:
      string info;                  //Contains question or answer
      NodeType *left;               //Left pointer
      NodeType *right;              //Right pointer
      bool isQuestion;              //Determines if info is a question or answer

};

