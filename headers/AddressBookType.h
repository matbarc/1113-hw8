#include "ExtPerson.h"
#include <iostream>
#include <string>
using namespace std;

#ifndef ADDRESSBOOKTYPE_H
#define ADDRESSBOOKTYPE_H

class AddressBookType {
public:
  AddressBookType() : people() {}

private:
  ExtPerson people[500];
};

//***********************************************************
// Non member functions
//***********************************************************
#endif