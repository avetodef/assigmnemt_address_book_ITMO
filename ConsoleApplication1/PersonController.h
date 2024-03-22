#pragma once
#include "Person.h"

class PersonController
{
public:
	virtual void output(Person*) = 0;
	virtual Person* input() = 0;
	PersonController() = default;
};

