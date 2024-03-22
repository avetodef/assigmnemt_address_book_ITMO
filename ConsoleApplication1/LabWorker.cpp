
#include "Person.h"
class LabWorker : public Person {
public:
	LabWorker(long _id, const string& _firstName, const string& _lastName, const PersonOccupation& _occupation, const string& _phone)
		: Person(_id, _firstName, _lastName, _occupation, _phone) {}

	string getFullRepresentation()const override {
		return "ID: " + to_string(id) + "\n" +
			"LabWorker: " + firstName + " " + lastName + "\n" +
			"Occupation: " + "LabWorker" + "\n" +
			"Phone number: " + phone
			;
	}
};