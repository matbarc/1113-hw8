#include <iostream>
#include <string>
using namespace std;

#ifndef PERSON_H
#define PERSON_H

class Person {
public:
  Person(string first = "", string last = "") {
    firstName = first;
    lastName = last;
  }
  void setName(string first, string last);
  string getFirstName() const { return firstName; }
  string getLastName() const { return lastName; }

  virtual void print(ostream &out) const;
  void load(istream &in);

private:
  string firstName, lastName;
};

//***********************************************************
// Non member functions
//***********************************************************
ostream &operator<<(ostream &out, const Person &person);
istream &operator>>(istream &in, Person &person);
#endif
