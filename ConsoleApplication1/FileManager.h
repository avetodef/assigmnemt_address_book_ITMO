#pragma once

#include "Person.h"
#include <vector>

using namespace std;

class FileManager
{
public:
	virtual void write(vector<Person*> v) = 0;
	virtual void erase(long line) = 0;
	FileManager() = default;
};

