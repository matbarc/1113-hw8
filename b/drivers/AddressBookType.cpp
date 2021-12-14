#include "../headers/AddressBookType.h"
#include <ostream>
#include <sstream>
#include <vector>
using std::ostream;

// Prints every ExtPerson contained in the book
void AddressBookType::print(ostream &out) const {
  for (int i = 0; i <= lastIndexStored; i++) {
    out << people[i] << std::endl;
  }
}

// Takes a reference to an instream and loads the information contained into it
// to the address book
void AddressBookType::load(istream &in) {
  string line;
  stringstream ss;

  lastIndexStored++;

  getline(in, line, '\n');
  ss = stringstream(line);
  ss >> people[lastIndexStored];
}

// Same as AddressBookType::print()
ostream &operator<<(ostream &out, const AddressBookType &book) {
  book.print(out);
  return out;
}

// Same as AddressBookType::load()
istream &operator>>(istream &in, AddressBookType &book) {
  book.load(in);
  return in;
}

// Searches the address book for given lastName (string) and returns a vector of
// ExtPerson with matching members in the book
vector<ExtPerson> AddressBookType::searchLastName(string lastName) {
  vector<ExtPerson> results;
  ExtPerson person;

  for (int i = 0; i <= this->lastIndexStored; i++) {
    person = this->people[i];
    if (person.getLastName() == lastName) {
      results.push_back(person);
    }
  }
  return results;
}

// Searches the address book for given birthday month (int) and returns a vector
// of ExtPerson with matching members in the book
vector<ExtPerson> AddressBookType::searchBirthdayMonth(int month) {
  vector<ExtPerson> results;
  ExtPerson person;

  for (int i = 0; i <= this->lastIndexStored; i++) {
    person = this->people[i];
    if (person.getBirthday().getMonth() == month) {
      results.push_back(person);
    }
  }
  return results;
}

// Searches the address book for given relationship (Relationship) and returns a
// vector of ExtPerson with matching members in the book
vector<ExtPerson> AddressBookType::searchRelation(Relationship rel) {
  vector<ExtPerson> results;
  ExtPerson person;

  for (int i = 0; i <= this->lastIndexStored; i++) {
    person = this->people[i];
    if (person.getRelationship() == rel) {
      results.push_back(person);
    }
  }
  return results;
}