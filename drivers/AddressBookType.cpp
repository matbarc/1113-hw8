#include "../headers/AddressBookType.h"
#include <ostream>
#include <sstream>
using std::ostream;

void AddressBookType::print(ostream &out) const {
  for (int i = 0; i <= lastIndexStored; i++) {
    out << people[i] << std::endl;
  }
}

void AddressBookType::load(istream &in) {
  string line;
  getline(in, line);

  lastIndexStored++;
  in >> people[lastIndexStored];
}

ostream &operator<<(ostream &out, const AddressBookType &book) {
  book.print(out);
  return out;
}

istream &operator>>(istream &in, AddressBookType &book) {
  book.load(in);
  return in;
}