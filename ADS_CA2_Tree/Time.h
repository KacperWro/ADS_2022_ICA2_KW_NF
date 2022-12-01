#pragma once
#include <ostream>
#include <string>
using namespace std;

/// <summary>
/// A user-defined class to store time
/// </summary>

class TimeHHMM {
#pragma region Fields
	//pick data types that minimize space requirements
	unsigned short int hours;		//2 bytes
	unsigned short int minutes;	//2 bytes
#pragma endregion

public:

#pragma region Constructors
	TimeHHMM(unsigned short int hours, unsigned short int minutes)
		: hours(hours), minutes(minutes) {}

	TimeHHMM()
		: hours(80), minutes(80) {}

	//takes a string and parses out data - useful!
	//TimeHHMM(string timeAsString) {
	//}

#pragma endregion

#pragma region Get & Set
	unsigned short int getHours() const { return this->hours; }
	unsigned short int getMinutes() const { return this->minutes; }

#pragma endregion

#pragma region Operators & Hash

	bool operator==(const TimeHHMM& externalTime)
	{
		return this->hours == externalTime.hours
			&& this->minutes == externalTime.minutes;
	}

	std::size_t hash() const
	{
		//What is the size of size_t? https://www.geeksforgeeks.org/size_t-data-type-c-language/
		//What are these numbers? https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
		size_t hash = std::hash<int>()(this->hours)
			+ 173 * std::hash<int>()(this->minutes);
		return hash;
	}

	friend ostream& operator<<(ostream& out, const TimeHHMM& time) {
		out << time.hours << ":" << time.minutes;
		return out;
	}
#pragma endregion
};
