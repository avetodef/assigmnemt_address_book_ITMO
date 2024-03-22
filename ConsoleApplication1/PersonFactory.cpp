#include "PersonFactory.h"

#include "Person.h"
#include <string>
#include "Student.cpp"
#include "LabWorker.cpp"
#include "Professor.cpp"
#include "Dean.cpp"
#include <unordered_map>
#include "PersonOccupation.h"
#include <iostream>

using namespace std;

static unordered_map<string, PersonOccupation> const occupMap = {
	{"STUDENT", STUDENT},
	{"LABWORKER", LABWORKER},
	{"PROFESSOR", PROFESSOR},
	{"DEAN", DEAN}
};

PersonOccupation parse(string s) {
	auto i = occupMap.find(s);
	if (i != occupMap.end()) {
		return i->second;
	}
	return ERROR;
}

string PersonFactory::enumToString(PersonOccupation occ) {
	for (const auto& it : occupMap) {
		if (it.second == occ) {
			return it.first;
		}
	}
	throw exception("String representation not found for given PersonOccupation");
}

Person* PersonFactory::create(string s) { //creates a person with a unique id and occupation
	long currentId = ++PersonFactory::id;

	PersonOccupation occupation = parse(s);

	if (occupation == ERROR) {
		return nullptr;
	}

	if (occupation == STUDENT) {
		return new Student(currentId, (string)"",(string) "", occupation, (string)"");
	}
	if (occupation == LABWORKER) {
		return new LabWorker(currentId, (string)"", (string)"", occupation, (string)"");
	}
	if (occupation == PROFESSOR) {
		return new Professor(currentId, (string)"", (string)"", occupation, (string)"");
	}
	if (occupation == DEAN) {
		return new Dean(currentId, (string)"", (string)"", occupation, (string)"");
	}
	return nullptr;
}

long PersonFactory::id = 0;


