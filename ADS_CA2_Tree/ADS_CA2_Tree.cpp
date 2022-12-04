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
	
	vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF//ADS_CA2_Tree//data_1000.csv");

	for (int i = 1; i < delimitedRows.size(); i++) {
		string timeDelimiter = ":";

		//DATE OF BIRTH
		Date dateOfBirth(delimitedRows[i][5]);

		//LAST LOG ON DATE
		Date lastLogOnDate(delimitedRows[i][10]);

		//LAST LOG ON TIME
		string logOnTime = delimitedRows[i][11];
		unsigned short int hours = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
		logOnTime = logOnTime.substr(3);
		unsigned short int minutes = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));

		TimeHHMM lastLogOnTime(hours, minutes);

		//JOINED ON
		Date joinedOn(delimitedRows[i][12]);

		Student newStudent(delimitedRows[i][0], stoi(delimitedRows[i][1]), delimitedRows[i][2], delimitedRows[i][3], delimitedRows[i][4], dateOfBirth,
			delimitedRows[i][6], delimitedRows[i][7], delimitedRows[i][8], delimitedRows[i][9], lastLogOnDate, lastLogOnTime, joinedOn, delimitedRows[i][13]);

		StudentKey newKey(newStudent.getUser_id(), newStudent.getFirst_name(), newStudent.getEmail());
		TNode<StudentKey, Student> newNode(newKey, newStudent);


		if (i == 7) {
			Date finalDob(delimitedRows[100][5]);

			//LAST LOG ON DATE
			Date finalLastLogDate(delimitedRows[100][10]);

			//LAST LOG ON TIME
			string finalLastLogTime = delimitedRows[100][11];
			unsigned short int lastHours = stoi(finalLastLogTime.substr(0, finalLastLogTime.find(timeDelimiter)));
			finalLastLogTime = finalLastLogTime.substr(3);
			unsigned short int lastMinutes = stoi(finalLastLogTime.substr(0, finalLastLogTime.find(timeDelimiter)));

			TimeHHMM lastLogOnTime(lastHours, lastMinutes);

			//JOINED ON
			Date lastJoinedOn(delimitedRows[100][12]);

			Student newerStudent(delimitedRows[100][0], stoi(delimitedRows[100][1]), delimitedRows[100][2], delimitedRows[100][3], delimitedRows[100][4], finalDob,
				delimitedRows[100][6], delimitedRows[100][7], delimitedRows[100][8], delimitedRows[100][9], finalLastLogDate, lastLogOnTime, lastJoinedOn, delimitedRows[100][13]);

			StudentKey newerKey(newerStudent.getUser_id(), newerStudent.getFirst_name(), newerStudent.getEmail());
			bool truth = newNode.insert(newerKey, newerStudent);
			cout << truth;

			cout << "\n" << newNode.getData().getEmail() << endl;
			TNode<StudentKey, Student> *newestNode = newNode.getpRight();
			cout << "\n" << newestNode->getData().getEmail() << endl;

			break;
		}

		/*for (auto it = delimitedRows[i].begin(); it != delimitedRows[i].end(); it++)

			cout << *it << " " << endl;
		cout << endl;*/

		

	}



}
