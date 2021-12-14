#include "DateType.h"
#include <iostream>
using namespace std;

#ifndef EXTDATETYPE_H
#define EXTDATETYPE_H

class ExtDateType : public DateType {
public:
  ExtDateType(int month = 1, int day = 1, int year = 1900)
      : DateType(month, day, year) {
    this->month_str = this->monthNumberToString(month);
  }
  static string monthNumberToString(int month);
  void print1(ostream &out) const;
  void print2(ostream &out) const;
  void print3(ostream &out) const;

private:
  string month_str;
};

ostream &operator<<(ostream &out, const ExtDateType &date);
#endif