#include <vector>
#include "PersonDAO.cpp"
#include "ConsoleController.cpp"
#include <algorithm>
#include <iostream>
#include "CommandsManager.h"

using namespace std;

vector<string> commands = {
	"add", "find_all", "delete_by_id", "find_by_id", "exit"
};

PersonDAO dao = PersonDAO();
ConsoleController console = ConsoleController();


bool checkCommand(string command) {
	auto c = find(::commands.begin(), ::commands.end(), command);
	if (c != ::commands.end()) {
		return true;
	}
	return false;
}


void perform(string command) { //performs a command
	if (command == "exit") {
		exit(0);
	}

	if (command == "add") { //add == save new user
		Person *p = console.input(); //add person
		if (p == nullptr) {
			console.output("this person cannot be created, try again!");
			return;
		}
		dao.save(p);
		return;
	}

	if (command == "find_all") {
		vector<Person*> all = dao.findAll();
		console.output(all);
		return;
	}

	if (command == "delete_by_id") {
		console.output("enter id");
		string strid;
		console.input(strid);

		long id = stol(strid);

		bool deleteResult = dao.deleteById(id);
		if (!deleteResult) {
			console.output("no such id, try again!");
		}
		return;
	}

	if (command == "find_by_id") {
		console.output("enter id");
		string strid;
		console.input(strid);

		long id = stol(strid);

		Person* p = dao.findById(id);

		console.output(p);
		return;
	}
}


void CommandsManager::run() {
	console.output("________________________________________________________________________________________________________");
	console.output("enter one of these commands: add, find_all, delete_by_id, find_by_id, exit");
	string command;
	console.input(command);
	
	if (checkCommand(command) == false) {
		console.output("no such command. try again");
		return;
	}
	
	perform(command);

	console.output("command performed.");
	console.output(" ");
}

