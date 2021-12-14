// This program implements and tests DateTypes with following functionality:
// - adding days
// - remaining days (in year, month)
// - passed days in year
// - different printing formats
// Author: Matheus Barcellos
// Assignment: Homework 8
// Class: CSCI 1113

#include "./headers/ExtDateType.h"
#include <string>
using namespace std;

int main() {
  ExtDateType date(12, 1, 2021);
  DateType date2;

  // testing printing methods
  date.print1(cout);
  cout << '\n';
  date.print2(cout);
  cout << '\n';
  date.print3(cout);
  cout << "\n\n";

  // testing number of days remaining in month
  cout << "expected: 31\n";
  cout << "actual: " << date.daysRemainingInMonth() << "\n\n";

  // testing number of days passed in year
  date.setDate(2, 1, 2022);
  cout << "expected: 31\n";
  cout << "actual: " << date.daysPassedInYear() << "\n\n";

  // add days to date
  date2 = date.addDays(8);
  cout << "expected: 2 / 9 / 2022\n";
  cout << "actual: " << date2 << '\n';
  return 0;
}
