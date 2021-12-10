#include "../headers/AddressType.h"
#include <ostream>
using std::ostream;

void AddressType::print(ostream &out) const {
  string sep = ", ";
  out << address << sep << city << sep << state << sep << zip;
}

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

ostream &operator<<(ostream &out, const AddressType &addr) {
  addr.print(out);
  return out;
}

istream &operator>>(istream &in, AddressType &addr) {
  addr.load(in);
  return in;
}