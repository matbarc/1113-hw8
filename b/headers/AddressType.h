#include <iostream>
#include <string>
using namespace std;

#ifndef ADDRESSTYPE_H
#define ADDRESSTYPE_H

class AddressType {
public:
  AddressType(string address = "", string city = "", string state = "",
              string zip = "") {
    this->address = address;
    this->city = city;
    this->state = state;
    this->zip = zip;
  }

  void print(ostream &out) const;
  void load(istream &in);

private:
  string address, city, state, zip;
};

//***********************************************************
// Non member functions
//***********************************************************
ostream &operator<<(ostream &out, const AddressType &addr);
istream &operator>>(istream &in, AddressType &addr);
#endif