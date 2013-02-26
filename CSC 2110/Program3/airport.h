#include <iostream>
#include "queue.h"

using namespace std;

class Airport
{
   public:
      Airport();
      void userInput();
      int getCurrentTime();
      void simulationLogic();
      void printResults();

      int randomGenerator();

      unsigned int currentTime;


   private:
      int landingCounter;
      int takeoffCounter;
      int totalSimTime;
      int minToLand;
      int minToTakeoff;
      int isBusy;
      double landingProb;
      double takeoffProb;
      int crashCounter;
      int maxLandingTime;
      Queue landingQueue;
      Queue takeoffQueue;

      long long avgTakeoff, avgLand;

};