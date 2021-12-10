#include "../headers/DateType.h"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void DateType::setDate(int month, int day, int year) {
  this->month = month;
  this->day = day;
  this->year = year;
}

void DateType::print(ostream &out) const {

  out << this->month << " / " << this->day << " / " << this->year;
}

bool DateType::isLeapYear() const {
  int mod4 = this->year % 4, mod100 = this->year % 100;

  if (mod4 == 0 && mod100 != 0) {
    return true;
  }
  return false;
}

int DateType::daysThisMonth() const {
  return DateType::daysInMonth(this->month, this->isLeapYear());
}

int DateType::daysInMonth(int month, bool isLeapYear) const {
  switch (month) {
  case 2:
    if (isLeapYear)
      return 29;
    return 28;
  case 1:
  case 3:
  case 5:
  case 7:
  case 8:
  case 10:
  case 12:
    return 31;
  case 4:
  case 6:
  case 9:
  case 11:
    return 30;
  default:
    cerr << "exiting" << endl;
    exit(1);
  }
}

int DateType::daysPassedInYear() const {
  int total = 0;

  for (int i = 1; i < this->month; i++) {
    total += DateType::daysInMonth(i, this->isLeapYear());
  }
  total += this->day - 1;
  return total;
}

int DateType::daysRemainingInYear() const {
  int total_days;

  total_days = this->isLeapYear() ? 366 : 365;
  return total_days - this->daysPassedInYear();
}

int DateType::daysRemainingInMonth() const {
  return this->daysThisMonth() - this->day;
}

DateType DateType::copy() const {
  return DateType(this->month, this->day, this->year);
}

DateType DateType::addDays(int days) const {
  DateType date = this->copy();

  if (days <= daysRemainingInMonth()) {
    date.setDay(date.getDay() + days);
    return date;
  }

  if (date.getMonth() == 12) {
    date.setMonth(1);
    date.setYear(date.getYear() + 1);
  } else {
    date.setMonth(date.getMonth() + 1);
  }
  date.setDay(1);

  return date.addDays(days - daysRemainingInMonth() - 1);
}

int translateMonthString(string month) {
  if (month == "January")
    return 1;
  else if (month == "February")
    return 2;
  else if (month == "March")
    return 3;
  else if (month == "April")
    return 4;
  else if (month == "May")
    return 5;
  else if (month == "June")
    return 6;
  else if (month == "July")
    return 7;
  else if (month == "October")
    return 8;
  else if (month == "September")
    return 9;
  else if (month == "October")
    return 10;
  else if (month == "November")
    return 11;
  else if (month == "December")
    return 12;
  else {
    cerr << "No such month exists.\n";
    exit(1);
  }
}

void DateType::load(istream &in) {
  string monthString;

  in >> monthString;
  month = translateMonthString(monthString);
  in >> day >> year;
}

//****************************************************************
// Non-member functions are defined below
//****************************************************************
ostream &operator<<(ostream &out, const DateType &date) {
  date.print(out);
  return out;
}

istream &operator>>(istream &in, DateType &date) {
  date.load(in);
  return in;
}
