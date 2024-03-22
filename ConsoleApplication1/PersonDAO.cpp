#include "Person.h"
#include "DAO.h"
#include "CSVFileManager.cpp"
#include <vector>

using namespace std;

class PersonDAO : public DAO{
private:
	vector<Person*> people = {};
	CSVFIleManager file;
public:

	vector<Person*> findAll() override{
		return vector<Person*>(people);
	}

	bool save(Person* p) override{
		people.push_back(p);
		file.write(people);
		return true;
	}

	bool deleteById(long id) override{
		long line = 0;
		for (Person* p : people) {
			line += 1;
			if (p->getId() == id) {
				people.erase(remove(people.begin(), people.end(), p));
				file.erase(line);
				return true;
			}
		}
		return false;
	}

	Person* findById(long id) override {
		for (Person* p : people) {
			if (p->getId() == id) {
				return p;
			}
		}
		return nullptr;
	}
	PersonDAO() = default;
};