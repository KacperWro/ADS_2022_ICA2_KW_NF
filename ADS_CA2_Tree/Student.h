#pragma once
using namespace std;

class Student
{
private:
	string user_id;
	int current_ranking;
	string first_name;
	string surname;
	string gender;
	string date_of_birth; //change data type to something similar to date time
	string email;
	string phone; //may want to convert to integer
	string postcode;
	string country;
	string last_log_on_date; //date
	string last_log_on_time; //time
	string joined_on; //date
	string account_credit; //might want to convert to integer
	string address;

public:
	Student() {
		this->user_id = "";
		this->current_ranking = 0;
		this->first_name = "";
		this->surname = "";
		this->gender = "";
		this->date_of_birth = "";
		this->email = "";
		this->phone = "";
		this->postcode = "";
		this->country = "";
		this->last_log_on_date = "";
		this->last_log_on_time = "";
		this->joined_on = "";
		this->account_credit = "";
		this->address = "";
	}

	Student(string user_id, int current_ranking, string first_name, string surname, string gender, string date_of_birth, string email, 
		string phone, string postcode, string country, string last_log_on_date, string last_log_on_time, string joined_on, string account_credit,
		string address) {
		
		this->user_id = user_id;
		this->current_ranking = current_ranking;
		this->first_name = first_name;
		this->surname = surname;
		this->gender = gender;
		this->date_of_birth = date_of_birth;
		this->email = email;
		this->phone = phone;
		this->postcode = postcode;
		this->country = country;
		this->last_log_on_date = last_log_on_date;
		this->last_log_on_time = last_log_on_time;
		this->joined_on = joined_on;
		this->account_credit = account_credit;
		this->address = address;
	}


	


};