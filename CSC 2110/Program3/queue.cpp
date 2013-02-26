#include "queue.h"

Queue::Queue()
{
   pCount = 0;

}

bool Queue::isEmpty()
{
   if (pCount == 0)
      return true;
   else
      return false;

}

void Queue::enqueue(Plane newPlane)
{
   QItem* newItem = new QItem();
   newItem->QData = newPlane;
   if (pCount == 0)
   {
      front = newItem;
      back = newItem;
      back->next = NULL;
      front->previous = NULL;
   }
   
   else
   {
      back->next = newItem;
      newItem->next = NULL;
      newItem->previous = back;
      back = newItem;
   }
   pCount++;
}

Plane* Queue::dequeue()
{
   if (pCount == 0)
      return NULL;
   else
   {
      Plane* result = &front->QData;
      front = front->next;
      pCount--;
      return result;
   }
   return NULL;
}


void Queue::addPlane(unsigned int currentPassedTime)
{
   Plane newPlane;

   newPlane.insertEnqueueArrivalTime(currentPassedTime);
   enqueue(newPlane);
}

Plane Queue::pop_front()
{
   return *dequeue();
}