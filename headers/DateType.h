#include <iostream>
using namespace std;

#ifndef DATETYPE_H
#define DATETYPE_H

class DateType {
public:
  DateType(int month = 1, int day = 1, int year = 1900) {
    this->month = month;
    this->day = day;
    this->year = year;
  }

  int getDay() const { return day; }
  int getMonth() const { return month; }
  int getYear() const { return year; }
  void setDate(int month, int day, int year);
  void setDay(int day) { this->day = day; }
  void setMonth(int month) { this->month = month; }
  void setYear(int year) { this->year = year; }

  bool isLeapYear() const;

  int daysThisMonth() const;
  int daysInMonth(int month, bool isLeapYear) const;
  int daysPassedInYear() const;
  int daysRemainingInYear() const;
  int daysRemainingInMonth() const;

  DateType addDays(int days) const;
  DateType copy() const;

  void print(ostream &out) const;
  void load(istream &in);

private:
  int month;
  int day;
  int year;
};

ostream &operator<<(ostream &out, const DateType &date);
istream &operator>>(istream &in, DateType &date);
int translateMonthString(string month);
#endif