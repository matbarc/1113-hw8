#include "../headers/AddressType.h"
#include <ostream>
using std::ostream;

void AddressType::print(ostream &out) const {
  string sep = ", ";
  out << address << sep << city << sep << state << sep << zip;
}

void AddressType::load(istream &in) { in >> address >> city >> state >> zip; }

ostream &operator<<(ostream &out, AddressType &addr) {
  addr.print(out);
  return out;
}

istream &operator>>(istream &in, AddressType &addr) {
  addr.load(in);
  return in;
}