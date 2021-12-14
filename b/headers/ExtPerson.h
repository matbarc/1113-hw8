#include "AddressType.h"
#include "ExtDateType.h"
#include "Person.h"
#include <iostream>
#include <vector>

#ifndef EXTPERSON_H
#define EXTPERSON_H

enum Relationship { FAMILY_MEMBER, FRIEND, BUSINESS_ASSOCIATE };

class ExtPerson : public Person {
public:
  ExtDateType getBirthday() const { return birthday; }
  AddressType getAddress() const { return address; }
  Relationship getRelationship() const { return relationship; }
  string getPhoneNumber() const { return phone_num; }
  void setBirthday(ExtDateType bday) { birthday = bday; }
  void setAddress(AddressType addr) { address = addr; }
  void setRelationship(Relationship rel) { relationship = rel; }
  void setPhoneNumber(string num) { phone_num = num; }

  void print(ostream &out) const;
  void print_info(ostream &out) const;
  void load(istream &in);

private:
  ExtDateType birthday;
  AddressType address;
  Relationship relationship;
  string phone_num;
};
//***********************************************************
// Non member functions
//***********************************************************
istream &operator>>(istream &in, ExtPerson &person);
istream &operator>>(istream &in, Relationship &rel);
ostream &operator<<(ostream &out, const vector<ExtPerson> &vec);
#endif