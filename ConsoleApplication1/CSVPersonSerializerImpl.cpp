#include "Serializer.h"
#include "Person.h"
#include "PersonFactory.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class CSVPersonSerializerImpl : public Serializer {
private:
	PersonFactory factory = PersonFactory();
public:
	Person* parse(string personString) override {
		stringstream ss(personString);
		vector<string> fields;
		string field;

		while (getline(ss, field, ',')) {
			fields.push_back(field);
		}
		
		Person* person = this->factory.create(fields[3]);
		person->id = stol(fields[0]);
		person->firstName = fields[1];
		person->lastName = fields[2];
		person->phone = fields[4];

		return person;
	}

	string serialize(Person& person) override {
		stringstream ss;
		char delimeter = ',';

		ss << person.getId() << delimeter << person.getFirstName()
			<< delimeter << person.getLastName() << delimeter
			<< factory.enumToString(person.getOccupation()) << delimeter
			<< person.getPhone();
		return ss.str();
	}

	CSVPersonSerializerImpl() = default;
};