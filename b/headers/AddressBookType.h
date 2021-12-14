#include "ExtPerson.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

class AddressBookType {
public:
  AddressBookType() : people(), lastIndexStored(-1) {}

  void print(ostream &out) const;
  void load(istream &in);
  vector<ExtPerson> searchLastName(string lastName);
  vector<ExtPerson> searchBirthdayMonth(int month);
  vector<ExtPerson> searchRelation(Relationship rel);

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