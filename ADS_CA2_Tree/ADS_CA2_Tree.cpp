// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TNode.h"
#include "Date.h"
#include "Utilities.h"
#include "StudentKey.h"
#include "Student.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
	try {
		Date x = Date("11/11/2005");
		cout << "Year from main()" << x.getYear() << endl;
	}
	catch(int x) {
		cout << "Something went wrong with initialisation. ERROR CODE: " << x << endl;
	}
	
	vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//Kacper//source//repos//ADS_2022_ICA2_KW_NF//ADS_CA2_Tree//data_1000.csv");

	BinaryTree<size_t, Student> newTree;

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
		/*TNode<StudentKey, Student> newNode(newKey, newStudent);*/
		newTree.insert(newKey.getHash(), newStudent);

	}
	cout << "\nCount: " << newTree.count() << endl;
	cout << "\nFound?: " << newTree.remove(18443049407160319861) << endl;
	cout << "\nFound?: " << newTree.remove(16290277276361596134) << endl;
	cout << "\nCount: " << newTree.count() << endl;

}
