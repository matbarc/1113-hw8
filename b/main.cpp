// This program implements an address book and tests the following
// functionality:
// - searching for last name
// - printing a given person
// - searching by birthday month
// - search by relation with book owner
// Author: Matheus Barcellos
// Assignment: Homework 8
// Class: CSCI 1113

#include "./headers/AddressBookType.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  AddressBookType book;
  ifstream infile;
  string temp;
  vector<ExtPerson> vec;

  infile.open("input.txt");

  while (!infile.eof()) {
    infile >> book;
  }

  // example of searching for last name
  vec = book.searchLastName("Reina");

  // example of printing info of a given person
  vec[0].print_info(cout);
  cout << '\n';

  // example of printing without birthday
  book.searchLastName("Dyson")[0].print_info(cout);
  cout << '\n';

  // print monthly birthdays for may
  cout << book.searchBirthdayMonth(5) << '\n';

  // print frieds (could've just as easily been associates or family members)
  cout << book.searchRelation(FRIEND) << '\n';
  return 0;
}
