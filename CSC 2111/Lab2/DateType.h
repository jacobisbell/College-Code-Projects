#include <string>
#include <fstream>

using namespace std;

// Declare a class to represent the Date ADT
// This is file DateType.h.

class DateType
{
   public:
      void Initialize(int newMonth, int newDay, int newYear);
      int GetMonth() const;					// returns year
      int GetYear() const;					// returns month
      int GetDay() const;					// returns day
      string GetMonthAsString() const;		// returns month as a string
      bool leapYear(int) const;
      DateType Adjust(int daysAway) const;
   private:
      int  year;
      int  month;
      int  day;				
};
