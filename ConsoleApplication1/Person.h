#include <string>
#include "PersonOccupation.h"

using namespace std;
#pragma once

class Person
{
	public:
	long id;
	string firstName;
	string lastName;
	PersonOccupation occupation;
	string phone;
	
public:
	virtual string getFullRepresentation() const = 0;
	
	long getId() const { return id; }
	string getFirstName() const { return firstName; }
	string getLastName() const { return lastName; }
	PersonOccupation getOccupation() const { return occupation; }
	string getPhone() const { return phone; }

	Person(long _id, const string& _firstName, const string& _lastName, const PersonOccupation& _occupation, const string& _phone)
		: id(_id), firstName(_firstName), lastName(_lastName), occupation(_occupation), phone(_phone) {}
	Person() = default;

	bool operator==(const Person& other) const {
		return (this->id == other.id);
	}
};