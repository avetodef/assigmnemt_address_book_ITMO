#pragma once
#include "Person.h"
#include <string>

using namespace std;

class PersonFactory
{
public:
	Person* create(string occupation);
	string enumToString(PersonOccupation occ);
	PersonFactory() = default;
private:
	static long id;
};

