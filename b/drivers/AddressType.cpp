#include "../headers/AddressType.h"
#include <ostream>
using std::ostream;

// Prints full address (street address, city, state, zip) to given outstream
void AddressType::print(ostream &out) const {
  string sep = ", ";
  out << address << sep << city << sep << state << sep << zip;
}

// Loads information from a given instream to the address
void AddressType::load(istream &in) {
  getline(in, address, ',');
  in.ignore(1);
  getline(in, city, ',');
  in.ignore(1);
  getline(in, state, ',');
  in.ignore(1);
  getline(in, zip, ',');
  in.ignore(1);
}

// Same as AddressType::print()
ostream &operator<<(ostream &out, const AddressType &addr) {
  addr.print(out);
  return out;
}

// Same as AddressType::load()
istream &operator>>(istream &in, AddressType &addr) {
  addr.load(in);
  return in;
}