#pragma once
#include <ostream>
#include <string>
#include "Date.h"
#include "Time.h"


using namespace std;
class Student
{
private:
	string user_id;
	int current_ranking;		//Maybe a smaller, unsigned datatype would suit better
	string first_name;
	string surname;
	string gender;
	Date date_of_birth;
	string email;
	string phone; //may want to convert to integer
	string postcode;
	string country;
	Date last_log_on_date; //date
	TimeHHMM last_log_on_time; //time
	Date joined_on; //date
	string account_credit; //might want to convert to double / float (whether signed or unsigned, unknown)
	// Just going to leave address out as it is problematic...

public:
	Student() {
		this->user_id = "";
		this->current_ranking = 0;
		this->first_name = "";
		this->surname = "";
		this->gender = "";
		this->date_of_birth = Date(80, 80, 8000);
		this->email = "";
		this->phone = "";
		this->postcode = "";
		this->country = "";
		this->last_log_on_date = Date(80, 80, 8000);
		this->last_log_on_time = TimeHHMM(70, 70);
		this->joined_on = Date(80, 80, 8000);
		this->account_credit = "";
	}

	Student(string user_id, int current_ranking, string first_name, string surname, string gender, Date date_of_birth, string email,
		string phone, string postcode, string country, Date last_log_on_date, TimeHHMM last_log_on_time, Date joined_on, string account_credit) {

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
	}


	string getUser_id() const { return this->user_id; }
	int getCurrent_ranking() const { return this->current_ranking; }
	string getFirst_name() const { return this->first_name; }
	string getSurname() const { return this->surname; }
	string getGender() const { return this->gender; }
	Date getDate_of_birth() const { return this->date_of_birth; }
	string getEmail() const { return this->email; }
	string getPhone() const { return this->phone; }
	string getPostcode() const { return this->postcode; }
	string getCountry() const { return this->country; }
	Date getLast_log_on_date() const { return this->last_log_on_date; }
	TimeHHMM getLast_log_on_time() const { return this->last_log_on_time; }
	Date getJoined_on() const { return this->joined_on; }
	string getAccount_credit() const { return this->account_credit; }



	bool operator==(const Student& student)
	{
		return this->user_id == student.user_id
			&& this->current_ranking == student.current_ranking
			&& this->first_name == student.first_name
			&& this->surname == student.surname
			&& this->gender == student.gender
			&& this->date_of_birth == student.date_of_birth
			&& this->email == student.email
			&& this->phone == student.phone
			&& this->postcode == student.postcode
			&& this->country == student.country
			&& this->last_log_on_date == student.last_log_on_date
			&& this->last_log_on_time == student.last_log_on_time
			&& this->joined_on == student.joined_on
			&& this->account_credit == student.account_credit;
	}


};