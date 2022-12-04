#pragma once
#include <ostream>
#include <string>
#include "../ADS_CA2_Tree/Date.h"
#include "../ADS_CA2_Tree/Time.h"


using namespace std;
class StudentKey
{
private:
	string user_id;
	string first_name;
	string email;

public:
	StudentKey() {
		this->user_id = "";
		this->first_name = "";
		this->email = "";
	}

	StudentKey(string user_id, string first_name, string email) {
		this->user_id = user_id;
		this->first_name = first_name;
		this->email = email;
	}

	string getUser_id() const { return this->user_id; }
	string getFirst_name() const { return this->first_name; }
	string getEmail() const { return this->email; }

	bool operator==(const StudentKey& studentKey)
	{
		return this->user_id == studentKey.user_id
			&& this->first_name == studentKey.first_name
			&& this->email == studentKey.email;
	}



};