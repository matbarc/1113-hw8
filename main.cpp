#include "./headers/AddressBookType.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
  AddressBookType book;
  ifstream infile;
  string temp;

  infile.open("input.txt");

  while (getline(infile, temp)) {
    stringstream s(temp);
    string temp2;

    while (getline(s, temp2, ',')) {
      cout << temp2 << "|";
    }
  }
  cout << book;

  return 0;
}