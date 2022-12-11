#pragma once
#include <ostream>
#include <string>
#include "Student.h"


using namespace std;
class StudentKey
{
private:
	size_t hashedNumber;

public:
	StudentKey() {
		this->hashedNumber = 0;
	}

	StudentKey(string user_id, string first_name, string email) {
		
		this->hashedNumber = hash(user_id, first_name, email);
	}

	size_t getHash() const { return this->hashedNumber; }

	bool operator==(const StudentKey& studentKey)
	{
		return this->hashedNumber == studentKey.hashedNumber;
	}

	std::size_t hash(string user_id, string first_name, string email) const
	{
		size_t hash = std::hash<string>()(user_id)
			+ 101 * std::hash<string>()(first_name)
			+ 149 * std::hash<string>()(email);
		return hash;
	}

};