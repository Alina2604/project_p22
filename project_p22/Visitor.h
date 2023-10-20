#pragma once
#include <vector>
#include <string>
#include "timeMark.h"

#pragma warning(disable : 4996)
using namespace std;


class Visitor {
private:
	string name;
	string surname;
	string pasport_data;
	timeMark time_input;
	timeMark time_output;
public:
	Visitor() {}

	Visitor(string nm, string srn, string psp_dt) {
		this->name = nm;
		this->surname = srn;
		this->pasport_data = psp_dt;
		this->time_input = currentDateTime();
	}

	void setTimeOutput(string tm);

	string currentDateTime();

	string getName() { return this->name; }
	string getSurname() { return this->surname; }
	string getPasport() { return this->pasport_data; }

	timeMark getTimeInput() { return this->time_input; }
	timeMark getTimeOutput() { return this->time_output; }

	bool operator==(Visitor& other);
};

// Operator ==
bool Visitor::operator==(Visitor& other) {
	if (name == other.name && surname == other.surname && pasport_data == other.pasport_data) {
		if (time_input == other.time_input && time_output == other.time_output) {
			return true;
		}
	}
	return false;
}

void Visitor::setTimeOutput(string tm) {
	this->time_output = timeMark(tm);
}

// Return Current Date and Time
string Visitor::currentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}