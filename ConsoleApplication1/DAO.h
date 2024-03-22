#pragma once
using namespace std;
#include <vector>
#include "Person.h"
#include "Serializer.h"

class DAO
{

public:
	virtual vector<Person*> findAll() = 0;
	virtual bool save(Person*) = 0; 
	virtual bool deleteById(long) = 0;
	virtual Person* findById(long) = 0;
};
