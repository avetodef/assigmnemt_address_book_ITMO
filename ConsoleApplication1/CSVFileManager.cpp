#include "FileManager.h"
#include "Person.h"
#include <vector>
#include "CSVPersonSerializerImpl.cpp"
#include <string>
#include<stdio.h>
#include <fstream>

using namespace std;

class CSVFIleManager : public FileManager {

private:
	CSVPersonSerializerImpl serializer;
	fstream fout;
	string filename = "address_book.csv";
public:

	void write(vector<Person*> people) override {
        remove(filename.c_str());
		fout.open(filename, ios::out | ios::app);

		for (Person* p : people) {
			string toWrite = serializer.serialize(*p);
			fout << toWrite << endl;
		}
		fout.close();
	}

	void erase(long line) override {
        ifstream fin(filename);
        if (!fin.is_open()) {
            throw exception();
            return;
        }
        vector<string> lines;
        string l;
        while (getline(fin, l)) {
            lines.push_back(l);
        }
        fin.close();

        if (line < 0 || line >= lines.size()) {
            throw exception();
            return;
        }
        lines.erase(lines.begin() + line);
        ofstream fout(filename, ios::out | ios::trunc);
        if (!fout.is_open()) {
            throw exception();
            return;
        }
        for (const string& l : lines) {
            fout << l << endl;
        }
        fout.close();
	}
	CSVFIleManager() = default;
};

