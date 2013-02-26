#include <iostream>
#include "plane.h"
#include <vector>

using namespace std;

struct QItem
{
   QItem* next;
   QItem* previous;
   Plane QData;
};

class Queue
{
   public:
      Queue();
      bool isEmpty();
      void addPlane(unsigned int);
      Plane pop_front();

   private:      
      void enqueue(Plane);
      Plane* dequeue();
      QItem* front;
      QItem* back;   
      int pCount; //plane count   

};    