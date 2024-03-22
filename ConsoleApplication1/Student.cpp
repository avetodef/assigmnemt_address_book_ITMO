
#include "Person.h"
#include <string>


using namespace std;

class Student : public Person {
	
public: 
	Student(long _id, const string& _firstName, const string& _lastName, const PersonOccupation& _occupation, const string& _phone)
		: Person(_id, _firstName, _lastName, _occupation, _phone){}

	string getFullRepresentation()const override {
		return "ID: " + to_string(id) + "\n" +
			"Student: " + firstName + " " + lastName + "\n"+
			"Occupation: " + "STUDENT" + "\n" +
			"Phone number: " + phone
			;	
	}
};