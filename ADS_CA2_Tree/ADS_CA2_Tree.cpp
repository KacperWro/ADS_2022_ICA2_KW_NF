// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TNode.h"
#include "Date.h"
#include "Utilities.h"
#include <vector>
#include "StudentKey.h"
#include "Student.h"
#include "Time.h"


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
	
	vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF//ADS_CA2_Tree//data_1000.csv");


		//DATE OF BIRTH
		Date dateOfBirth(delimitedRows[i][5]);

		//LAST LOG ON DATE
		Date lastLogOnDate(delimitedRows[i][10]);

	

		//JOINED ON
		Date joinedOn(delimitedRows[i][12]);

		Student newStudent(delimitedRows[i][0], stoi(delimitedRows[i][1]), delimitedRows[i][2], delimitedRows[i][3], delimitedRows[i][4], dateOfBirth,
			delimitedRows[i][6], delimitedRows[i][7], delimitedRows[i][8], delimitedRows[i][9], lastLogOnDate, lastLogOnTime, joinedOn, delimitedRows[i][13]);

		StudentKey newKey(newStudent.getUser_id(), newStudent.getFirst_name(), newStudent.getEmail());
		TNode<StudentKey, Student> newNode(newKey, newStudent);


		/*for (auto it = delimitedRows[i].begin(); it != delimitedRows[i].end(); it++)

			cout << *it << " " << endl;
		cout << endl;*/

	}

	// Hash code working example

	Date dob = Date("11/11/1970");
	Date lastLogOn = Date("04/12/2022");
	TimeHHMM lastLogTime = TimeHHMM(11, 55);
	Date joined = Date("03/11/2020");

	Student betty = Student("jshfgd", 21, "Betty", "Boop", "Female", dob, "Betty@Boop.com", "189507724136", "ahvbn", "USA", lastLogOn, lastLogTime, joined, "$50000.93");

	StudentKey bettyKey = StudentKey(betty);

	TNode<StudentKey, Student> testerNode(bettyKey, betty);

	cout << "HASH CODE FOR BETTY'S NODE: " << testerNode.hash() << endl;





}
