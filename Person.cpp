#include <iostream>
#include <string>
#include "Person.h"
using namespace std;


void Person::setName(string first, string last) {
	
	this->firstName = first;
	this->lastName = last;
}
void Person::print(ostream& out) const {

	out << this->firstName << " " << this->lastName;
}

ostream& operator<<(ostream& out, const Person& person) {

	person.print(out);
	return out;
}

