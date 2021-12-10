#include "../headers/ExtPerson.h"
#include <ostream>
using std::ostream;

void ExtPerson::print(ostream &out) const {
  out << address << ", " << phone_num;
}

void ExtPerson::load(istream &in) {
  Person::load(in);
  in >> address;
  getline(in, phone_num, ',');
  in.ignore(1);
  in >> relationship;
  if (in)
    in >> birthday;

  print(cout);
}

istream &operator>>(istream &in, ExtPerson &person) {
  person.load(in);
  return in;
}

istream &operator>>(istream &in, Relationship &rel) {
  string temp;

  getline(in, temp, ',');
  in.ignore(1);

  if (temp == "Business Associate")
    rel = BUSINESS_ASSOCIATE;
  else if (temp == "Family Member")
    rel = FAMILY_MEMBER;
  else if (temp == "Friend")
    rel = FRIEND;
  else {
    cerr << "No such relationship exists. (" << temp << ")\n";
    exit(1);
  }

  return in;
}