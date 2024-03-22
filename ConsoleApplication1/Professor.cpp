
#include "Person.h"
class Professor : public Person {
public:
	Professor(long _id, const string& _firstName, const string& _lastName, const PersonOccupation& _occupation, const string& _phone)
		: Person(_id, _firstName, _lastName, _occupation, _phone) {}

	string getFullRepresentation()const override {
		return "ID: " + to_string(id) + "\n" +
			"Professor: " + firstName + " " + lastName + "\n" +
			"Occupation: " + "Professor" + "\n" +
			"Phone number: " + phone
			;
	}
};