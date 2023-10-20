#pragma once
#include <string>
using namespace std;

class timeMark {
private:
	string year;
	string month;
	string day;
	string hour;
	string minuts;
public:
	timeMark() {}
	timeMark(string data_time) {
		this->year = data_time.substr(0, 4);
		this->month = data_time.substr(5, 2);
		this->day = data_time.substr(8, 2);
		this->hour = data_time.substr(11, 2);
		this->minuts = data_time.substr(14, 2);
	}
	
	string getNormalTime();

	bool operator==(timeMark& other);
};


//2023-10-19.19:44:40
string timeMark::getNormalTime() {
	return year + "." + month + "." + day + "  " + hour + ":" + minuts;
}

bool timeMark::operator==(timeMark& other) {
	if (year == other.year && month == other.month && day == other.day && hour == other.hour && minuts == other.minuts) {
		return true;
	}
	return false;
}