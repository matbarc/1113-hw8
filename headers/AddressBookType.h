#include "ExtPerson.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

class AddressBookType {
public:
  AddressBookType() : people(), lastIndexStored(-1) {}

  void print(ostream &out) const;
  void load(istream &in);

private:
  ExtPerson people[500];
  int lastIndexStored;
};

//***********************************************************
// Non member functions
//***********************************************************
istream &operator>>(istream &in, AddressBookType &book);
ostream &operator<<(ostream &out, const AddressBookType &book);
#endif