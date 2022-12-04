// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TNode.h"
#include "Date.h"
#include "Utilities.h"
#include "StudentKey.h"
#include "Student.h"

using namespace std;

int main()
{
	try {
		Date x = Date("11/11/2005");
		cout << "Year from main()" << x.getYear();
	}
	catch(int x) {
		cout << "Something went wrong with initialisation. ERROR CODE: " << x << endl;
	}



	
	vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//Kacper//source//repos//ADS_2022_ICA2_KW_NF//ADS_CA2_Tree//data_1000.csv");

	

	for (int i = 1; i < 3; i++) {
		Student newStudent;
		string dateDelimiter = "/";
		string timeDelimiter = ":";

		newStudent.setUser_id(delimitedRows[i][0]);
		newStudent.setCurrent_ranking(stoi(delimitedRows[i][1]));
		newStudent.setFirst_name(delimitedRows[i][2]);
		newStudent.setSurname(delimitedRows[i][3]);
		newStudent.setGender(delimitedRows[i][4]);

		//DATE OF BIRTH
		string dob = delimitedRows[i][5];

		int day = stoi(dob.substr(0, dob.find(dateDelimiter)));
		dob = dob.substr(3);
		int month = stoi(dob.substr(0, dob.find(dateDelimiter)));
		dob = dob.substr(3);
		int year = stoi(dob.substr(0, dob.find(dateDelimiter)));
		dob = dob.substr(3);

		Date dateOfBirth(day, month, year);
		newStudent.setDate_of_birth(dateOfBirth);




		newStudent.setEmail(delimitedRows[i][6]);
		newStudent.setPhone(delimitedRows[i][7]);
		newStudent.setPostcode(delimitedRows[i][8]);
		newStudent.setCountry(delimitedRows[i][9]);



		//LAST LOG ON DATE
		string lastLogDate = delimitedRows[i][10];

		day = stoi(lastLogDate.substr(0, lastLogDate.find(dateDelimiter)));
		lastLogDate = lastLogDate.substr(3);
		month = stoi(lastLogDate.substr(0, lastLogDate.find(dateDelimiter)));
		lastLogDate = lastLogDate.substr(3);
		year = stoi(lastLogDate.substr(0, lastLogDate.find(dateDelimiter)));
		lastLogDate = lastLogDate.substr(3);

		Date lastLogOnDate(day, month, year);
		newStudent.setLast_log_on_date(lastLogOnDate);




		//LAST LOG ON TIME
		string logOnTime = delimitedRows[i][11];
		unsigned short int hours = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
		logOnTime = logOnTime.substr(3);
		unsigned short int minutes = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));

		TimeHHMM lastLogOnTime(hours, minutes);
		newStudent.setLast_log_on_time(lastLogOnTime);




		//JOINED ON
		string joinDate = delimitedRows[i][12];
		day = stoi(joinDate.substr(0, joinDate.find(dateDelimiter)));
		joinDate = joinDate.substr(3);
		month = stoi(joinDate.substr(0, joinDate.find(dateDelimiter)));
		joinDate = joinDate.substr(3);
		year = stoi(joinDate.substr(0, joinDate.find(dateDelimiter)));
		joinDate = joinDate.substr(3);

		Date joinedOn(day, month, year);
		newStudent.setJoined_on(joinedOn);

		newStudent.setAccount_credit(delimitedRows[i][13]);

		/*for (auto it = delimitedRows[i].begin(); it != delimitedRows[i].end(); it++)
			
			cout << *it << " " << endl;
		cout << endl;*/

		StudentKey newKey(newStudent.getUser_id(), newStudent.getFirst_name(), newStudent.getEmail());
		TNode<StudentKey, Student> newNode(newKey, newStudent);
		cout << newNode.getData().getCountry() << endl;
	}



}
