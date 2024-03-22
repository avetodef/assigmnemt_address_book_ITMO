#pragma once
#include "Person.h"
#include <string>

using namespace std;


class Serializer
{
public:
	virtual Person* parse(string) = 0;
	virtual string serialize(Person&) = 0;
};

