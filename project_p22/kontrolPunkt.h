#pragma once
#include<iostream>
#include "Visitor.h"
#include <stdio.h>
#include <fstream>

#pragma warning(disable : 4996)

using namespace std;

class ControlPunkt {
private:
	static int now_count;
	vector<Visitor> visitors;
public:
	ControlPunkt() {}
	
	string currentDateTime();

	int getNow_count() { return now_count; }

	void registration_input(Visitor human);
	void registration_exit(Visitor human);

	void print_visitors();
	void write_visitors_in_file();
};
int ControlPunkt::now_count = 0;

// Visitor entered in Control punkt
void ControlPunkt::registration_input(Visitor human) {
	visitors.push_back(human);
	now_count++;
}

// Visitor human exit from Control punkt
void ControlPunkt::registration_exit(Visitor human) {
	for (int i = 0; i < size(visitors); ++i) {
		if (visitors[i] == human) {
			visitors[i].setTimeOutput(currentDateTime());
		}
	}
	now_count--;
}

// Print data about all visitors
void ControlPunkt::print_visitors() {
	for (auto user : visitors) {
		cout << "Name: " << user.getName() << endl;
		cout << "Surname: " << user.getSurname() << endl;
		cout << "Pasport data: " << user.getPasport() << endl;
		cout << "Time input: " << user.getTimeInput().getNormalTime() << endl;
		cout << "HI" << endl;
		cout << "Time output: " << user.getTimeOutput().getNormalTime() << endl;
	}
}

// Write in file data from vector visitors
void ControlPunkt::write_visitors_in_file() {
	ofstream wr("users.txt");
	for (auto user : visitors) {
		wr << user.getName() << "\n";
		wr << user.getSurname() << "\n";
		wr << user.getPasport() << "\n";
		wr << user.getTimeInput().getNormalTime() << "\n";
		wr << user.getTimeOutput().getNormalTime() << "\n\n";
	}
}

// Return Current Date and Time
string ControlPunkt::currentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
	return buf;
}

