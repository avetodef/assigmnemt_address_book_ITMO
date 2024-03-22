#include "PersonController.h"
#include "PersonFactory.h"
#include <iostream>
#include <vector>
#include <regex>

class ConsoleController : public PersonController {
private:
	PersonFactory factory = PersonFactory();
	bool validatePhone(string& phone) {
		regex pattern("\\d{11}"); //11 цифр
		return regex_match(phone, pattern);
	}

public:
	void output(Person* p) override {
		cout << p->getFullRepresentation() << endl;
	}

	void output(string s) {
		cout << s << endl;
	}

	void output(vector<Person*> all) {
		for (Person *p : all) {
			output(p);
		}
	}
	
	void input(string &param) {
		cin >> param;
	}

	Person* input() override {
		string name, lname, occup, phone; //TODO check phone and occupation
		cout << "enter name" << endl;
		cin >> name;
		cout << "enter last name" << endl;
		cin >> lname;
		cout << "enter one of these occupations: STUDENT, LABWORKER, PROFESSOR, DEAN" << endl;
		cin >> occup;
		cout << "enter phone number in format 8**********" << endl;
		cin >> phone;

		Person* p = factory.create(occup);
		if (p == nullptr) {
			output("incorrect occupation!");
			return nullptr;
		}
		p->firstName = name;
		p->lastName = lname;
		bool valPhone = validatePhone(phone);
		if (valPhone) {
			p->phone = phone;
			return p;
		}
		output("incorrect phone number!");

		return nullptr;
	}
};
