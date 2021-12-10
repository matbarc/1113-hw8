#include "../headers/Person.h"
#include <iostream>
#include <string>

using namespace std;

void Person::setName(string first, string last) {

  this->firstName = first;
  this->lastName = last;
}

void Person::load(istream &in) {
  getline(in, firstName, ',');
  in.ignore(1);
  getline(in, lastName, ',');
  in.ignore(1);
}

void Person::print(ostream &out) const {
  out << this->firstName << " " << this->lastName;
}

ostream &operator<<(ostream &out, const Person &person) {
  person.print(out);
  return out;
}

istream &operator>>(istream &in, Person &person) {
  person.load(in);
  return in;
}
