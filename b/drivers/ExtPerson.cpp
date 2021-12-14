#include "../headers/ExtPerson.h"
#include <ostream>
#include <vector>
using std::ostream;

// Prints this person as ExtPerson(Last, First)
void ExtPerson::print(ostream &out) const {
  out << "ExtPerson(" << getLastName() << ", " << getFirstName() << ")";
}

// Prints this person's info (address, phone and birthday, if present)
void ExtPerson::print_info(ostream &out) const {
  ExtDateType defDate;

  out << address << ", " << phone_num;
  if (birthday != defDate) {
    out << ", ";
    birthday.print3(out);
  }
}

// Loads this object's info from given instream
void ExtPerson::load(istream &in) {
  Person::load(in);
  in >> address;
  getline(in, phone_num, ',');
  in.ignore(1);
  in >> relationship;
  if (in)
    in >> birthday;
}

// Same as ExtPerson::load()
istream &operator>>(istream &in, ExtPerson &person) {
  person.load(in);
  return in;
}

// Loads a Relationship status from a given instream
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

// Same as calling `cout << person` for every person in vector
ostream &operator<<(ostream &out, const vector<ExtPerson> &vec) {
  ExtPerson person;

  if (vec.size() == 0) {
    out << "[]";
    return out;
  }

  out << "[" << vec[0];
  for (int i = 1; i < vec.size(); i++) {
    person = vec[i];
    out << ", " << person;
  }
  out << ']';
  return out;
}