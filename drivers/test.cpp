#include "DateType.h"
#include <iostream>
using namespace std;

int main() {
  ExtDateType date, date2;

  date = ExtDateType(12, 31, 2021);
  for (int i = 1; i < 50; i++) {
    cout << i << ": " << date.addDays(i) << endl;
  }

  date.print1(cout);
  cout << endl;
  date.print2(cout);
  cout << endl;
  date.print3(cout);

  return 0;
}