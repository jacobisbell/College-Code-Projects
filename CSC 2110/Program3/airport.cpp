#include "airport.h"

Airport::Airport()
{
   landingCounter = 0;
   takeoffCounter = 0;
   currentTime = 0;
   totalSimTime = 0;
   crashCounter = 0;
   avgTakeoff = 0;
   avgLand = 0;
   isBusy = 0;

   srand(time(0));


   userInput();

   simulationLogic();

   printResults();


}

void Airport::userInput()     //Requests user input for program variables
{
   cout << endl << endl << endl;
   cout << "------- Welcome to AirSimPro by Jacob Isbell (c) 2012 -------";
   cout << endl << endl << endl;
   cout << "Minutes to land: ";
   cin >> minToLand;

   cout << "Minutes to takeoff: ";
   cin >> minToTakeoff;

   cout << "Probability of plane arrival for landing: ";
   cin >> landingProb;
   landingProb *= 100;    //coverts number to value between 0-100

   cout << "Probability of plane arrival for takeoff: ";
   cin >> takeoffProb;
   takeoffProb *= 100;

   cout << "Maximum time in landing queue: ";
   cin >> maxLandingTime;

   cout << "Total simulation time in minutes: ";
   cin >> totalSimTime;
   cout << endl;

}


void Airport::simulationLogic()
{

   while (currentTime < totalSimTime)
   {
      if (randomGenerator() <= landingProb)     //Addition to landing queue
         landingQueue.addPlane(getCurrentTime());   

      if (randomGenerator() <= takeoffProb)
         takeoffQueue.addPlane(getCurrentTime());
      
      Plane dequeuedPlane;
      if (isBusy-- <= 0)
      {
         if (!landingQueue.isEmpty())
         {

            dequeuedPlane = landingQueue.pop_front();

            dequeuedPlane.timeInLandingQueue = (currentTime - dequeuedPlane.enqueueTime);

            avgLand += dequeuedPlane.timeInLandingQueue;

            if(dequeuedPlane.timeInLandingQueue > maxLandingTime)
               crashCounter++;
            else
            {
               landingCounter++;
               isBusy = minToLand;
            }
         }
         else if (landingQueue.isEmpty() && !takeoffQueue.isEmpty())
         {

            dequeuedPlane = takeoffQueue.pop_front();

            dequeuedPlane.timeInLandingQueue = (currentTime - dequeuedPlane.enqueueTime);

            avgTakeoff += dequeuedPlane.timeInLandingQueue;

            takeoffCounter++;
            isBusy = minToTakeoff;


         }
         else
         {
         }
      }
      currentTime++;

   }
}


int Airport::randomGenerator()
{

   int randomGen = rand() % 100 + 1;
   return randomGen;

}


void Airport::printResults()
{
   int avgLandFinal = 0, avgTakeoffFinal = 0;
   if (landingCounter)
      avgLandFinal = avgLand / landingCounter;
   if (takeoffCounter)
      avgTakeoffFinal = avgTakeoff / takeoffCounter;

   cout << "Number of planes that took off: " << takeoffCounter << endl;
   cout << "Number of planes that landed  : " << landingCounter << endl;
   cout << "Number of planes that crashed : " << crashCounter << endl;
   cout << "Average time in takeoff queue : " << avgTakeoffFinal << endl;
   cout << "Average time in landing queue : " << avgLandFinal << endl;
}


int Airport::getCurrentTime()
{
   return currentTime;
}
















