#include "../headers/Person.h"
#include <iostream>
#include <string>
using namespace std;

// Sets name for this object given strings for its first and last name
void Person::setName(string first, string last) {
  this->firstName = first;
  this->lastName = last;
}

// Loads this objects data from given instream
void Person::load(istream &in) {
  getline(in, firstName, ',');
  in.ignore(1);
  getline(in, lastName, ',');
  in.ignore(1);
}

// Print this object as FirstName LastName
void Person::print(ostream &out) const {
  out << this->firstName << " " << this->lastName;
}

// Same as Person::print()
ostream &operator<<(ostream &out, const Person &person) {
  person.print(out);
  return out;
}

// Same as Person::load()
istream &operator>>(istream &in, Person &person) {
  person.load(in);
  return in;
}
