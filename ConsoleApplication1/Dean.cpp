
#include "Person.h"
class Dean : public Person {
public:
	Dean(long _id, const string& _firstName, const string& _lastName, const PersonOccupation& _occupation, const string& _phone)
		: Person(_id, _firstName, _lastName, _occupation, _phone) {}

	string getFullRepresentation()const override {
		return "ID: " + to_string(id) + "\n" +
			"Dean: " + firstName + " " + lastName + "\n" +
			"Occupation: " + "Dean" + "\n" +
			"Phone number: " + phone
			;
	}
};