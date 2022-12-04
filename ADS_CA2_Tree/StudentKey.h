#pragma once
#include <ostream>
#include <string>
#include "Student.h"


using namespace std;
class StudentKey
{
private:
	string user_id;
	string first_name;
	string email;
	size_t hashedNumber;

public:
	StudentKey() {
		this->user_id = "";
		this->first_name = "";
		this->email = "";
		this->hashedNumber = 0;
	}

	StudentKey(string user_id, string first_name, string email) {
		this->user_id = user_id;
		this->first_name = first_name;
		this->email = email;
		this->hashedNumber = hash();
	}

	StudentKey(Student& t)
	{
		this->user_id = t.getUser_id();
		this->first_name = t.getFirst_name();
		this->email = t.getEmail();
	}

	//string getUser_id() const { return this->user_id; }
	//string getFirst_name() const { return this->first_name; }
	//string getEmail() const { return this->email; }
	size_t getHash() const { return this->hashedNumber; }

	bool operator==(const StudentKey& studentKey)
	{
		return this->hashedNumber == studentKey.hashedNumber;
	}

	std::size_t hash() const
	{
		size_t hash = std::hash<string>()(this->user_id)
			+ 101 * std::hash<string>()(this->first_name)
			+ 149 * std::hash<string>()(this->email);
		return hash;
	}


};