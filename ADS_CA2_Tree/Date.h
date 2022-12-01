#pragma once
#include <ostream>
#include <string>
#include <stdlib.h>

using namespace std;

/// <summary>
/// A user-defined class to store date
/// </summary>
/// <see>https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm</see>
/// <see>https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers</see>
class Date {
#pragma region Fields
	//pick data types that minimize space requirements
	unsigned short int day;		//2 bytes
	unsigned short int month;	//2 bytes
	unsigned int year;			//4 bytes
#pragma endregion

public:

#pragma region Constructors
	Date(unsigned short int day, unsigned short int month, unsigned int year)
		: day(day), month(month), year(year) {}

	Date() : day(80), month(80), year(8000) {}

	//takes a string and parses out data - (doesnt seem to work yet)
	Date(string dateAsString) {
		string delimiter = "/";

		unsigned short int dayExtract = 0;
		unsigned short int monthExtract = 0;
		unsigned int yearExtract = 0;

		size_t pos = 0;
		size_t count = 0;

		std::string subString;
		while ((pos = dateAsString.find(delimiter)) != std::string::npos) {
			if (count == 0) {
				dayExtract = stoi(dateAsString.substr(0, pos));
				dateAsString.erase(0, pos + delimiter.length());
				count++;
			}
			else if (count == 1) {
				monthExtract = stoi(dateAsString.substr(0, pos));
				dateAsString.erase(0, pos + delimiter.length());
				count++;
			}
			else if (count == 2) {
				yearExtract = stoi(dateAsString.substr(0, pos));
				dateAsString.erase(0, pos + delimiter.length());
				count++;
			}
			else {
				throw 86;
			}
		}
		this->day = dayExtract;
		this->month = monthExtract;
		this->year = yearExtract;

	}

#pragma endregion

#pragma region Get & Set
	unsigned short int getDay() const { return this->day; }
	unsigned short int getMonth() const { return this->month; }
	unsigned short int getYear() const { return this->year; }

#pragma endregion

#pragma region Operators & Hash

	bool operator==(const Date& date)
	{
		return this->day == date.day
			&& this->month == date.month
			&& this->year == date.year;
	}

	std::size_t hash() const
	{
		//What is the size of size_t? https://www.geeksforgeeks.org/size_t-data-type-c-language/
		//What are these numbers? https://en.wikipedia.org/wiki/List_of_prime_numbers#The_first_1000_prime_numbers
		size_t hash = std::hash<int>()(this->day)
			+ 101 * std::hash<int>()(this->month)
			+ 149 * std::hash<int>()(this->year);
		return hash;
	}

	friend ostream& operator<<(ostream& out, const Date& date) {
		out << date.day << "," << date.month << "," << date.year;
		return out;
	}
#pragma endregion
};
