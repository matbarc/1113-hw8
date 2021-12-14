#include "../headers/ExtDateType.h"
#include <iomanip>
#include <iostream>
using namespace std;

// Returns the name of the month given its number (e.g.: 1 -> January)
string ExtDateType::monthNumberToString(int month) {
  switch (month) {
  case 1:
    return "January";
  case 2:
    return "February";
  case 3:
    return "March";
  case 4:
    return "April";
  case 5:
    return "May";
  case 6:
    return "June";
  case 7:
    return "July";
  case 8:
    return "August";
  case 9:
    return "September";
  case 10:
    return "October";
  case 11:
    return "November";
  case 12:
    return "December";
  default:
    exit(1);
  }
}

// Prints this objects date as mmm-dd-yyyy
void ExtDateType::print1(ostream &out) const {
  char sep = '-';

  out << setfill('0') << this->month_str.substr(0, 3) << sep << setw(2)
      << this->getDay() << sep << this->getYear();
}

// Prints this objects date as mmm dd, yyyy
void ExtDateType::print2(ostream &out) const {
  out << this->month_str << " " << setw(2) << this->getDay() << ", "
      << this->getYear();
}

// Prints this objects date as dd-mmm-yyyy
void ExtDateType::print3(ostream &out) const {
  char sep = '-';

  out << setfill('0') << setw(2) << this->getDay() << sep
      << this->month_str.substr(0, 3) << sep << this->getYear();
}