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
	
	vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//Kacper//OneDrive - Dundalk Institute of Technology//Algs + Data//data_1000.csv");
	//vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_yip//ADS_CA2_Tree//data_1000.csv");

	BinaryTree<size_t, Student> newTree;

	for (int i = 1; i < 7; i++) {
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
		//cout << newKey.getHash() << endl;

	}


	StudentKey dummy(delimitedRows[1][0], delimitedRows[1][2], delimitedRows[1][6]);
	size_t hashCode = dummy.hash();

	StudentKey dummy1(delimitedRows[2][0], delimitedRows[2][2], delimitedRows[2][6]);
	size_t hashCode1 = dummy.hash();

	StudentKey dummy2(delimitedRows[3][0], delimitedRows[3][2], delimitedRows[3][6]);
	size_t hashCode2 = dummy.hash();

	StudentKey dummy3(delimitedRows[4][0], delimitedRows[4][2], delimitedRows[4][6]);
	size_t hashCode3 = dummy.hash();

	StudentKey dummy4(delimitedRows[5][0], delimitedRows[5][2], delimitedRows[5][6]);
	size_t hashCode4 = dummy.hash();

	StudentKey dummy5(delimitedRows[6][0], delimitedRows[6][2], delimitedRows[6][6]);
	size_t hashCode5 = dummy.hash();


	/*StudentKey dummy(delimitedRows[4][0], delimitedRows[4][2], delimitedRows[4][6]);

	size_t hashCode = dummy.hash();*/

	cout << "\nCount: " << newTree.count() << endl;
	//cout << "\nFound and deleted?: " << newTree.removeWithAllChildren(16290277276361596134) << endl;
	//cout << "\nFound and deleted?: " << newTree.remove(16290277276361596134) << endl;

	cout << "\nDepth!: " << newTree.depth(dummy.hash()) << endl;
	cout << "\nDepth!: " << newTree.depth(dummy1.hash()) << endl;
	cout << "\nDepth!: " << newTree.depth(dummy2.hash()) << endl;
	cout << "\nDepth!: " << newTree.depth(dummy3.hash()) << endl;
	cout << "\nDepth!: " << newTree.depth(dummy4.hash()) << endl;
	cout << "\nDepth!: " << newTree.depth(dummy5.hash()) << endl;

	int height = 0;
	int max = 0;
	newTree.getHeight(height, max);
	cout << "\nHeight: " << max << endl;

	cout << "\nCount: " << newTree.count() << endl;


	TNode<size_t, Student>* myStudent = newTree.search(16290277276361596134);

	if (myStudent == nullptr) {
		cout << "Student not found" << endl;
	}
	else
	{
		myStudent->getData().print();
	}



}
