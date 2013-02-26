#include <iostream>

using namespace std;

class Plane
{
   public:
      Plane();
      void insertEnqueueArrivalTime(unsigned int);

      unsigned int enqueueTime;
      int timeInLandingQueue;
   private:
      int arrivalTime;
      int leavingTime;
      int remainingFuel;


};