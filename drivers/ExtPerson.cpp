#include "../headers/ExtPerson.h"
#include <ostream>
using std::ostream;

void ExtPerson::print(ostream &out) const {
  out << address << ", " << phone_num;
}

void ExtPerson::load(istream &in) {
  Person::load(in);
  in >> address >> relationship;
  if (in)
    in >> birthday;
}

istream &operator>>(istream &in, ExtPerson &person) {
  person.load(in);
  return in;
}

istream &operator>>(istream &in, Relationship &rel) {
  string temp;

  in >> temp;

  if (temp == "Business Associate")
    rel = BUSINESS_ASSOCIATE;
  else if (temp == "Family Member")
    rel = FAMILY_MEMBER;
  else if (temp == "Friend")
    rel = FRIEND;
  else {
    cerr << "No such relationship exists.\n";
    exit(1);
  }

  return in;
}