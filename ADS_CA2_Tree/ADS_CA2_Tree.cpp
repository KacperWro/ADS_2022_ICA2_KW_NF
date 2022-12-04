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
		cout << "Year from main()" << x.getYear() << endl;
	}
	catch(int x) {
		cout << "Something went wrong with initialisation. ERROR CODE: " << x << endl;
	}



	
	/*vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//Kacper//source//repos//ADS_2022_ICA2_KW_NF//ADS_CA2_Tree//data_1000.csv");
	//vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF//ADS_CA2_Tree//data_1000.csv");

	

	for (int i = 0; i < 3; i++) {
		for (
			auto it = delimitedRows[i].begin();
			it != delimitedRows[i].end(); it++)
			cout << *it << " " << endl;
		cout << endl;
	} */

	Date dob = Date("11/11/1970");
	Date lastLogOn = Date("04/12/2022");
	TimeHHMM lastLogTime = TimeHHMM(11, 55);
	Date joined = Date("03/11/2020");


	Student betty = Student("jshfgd", 21, "Betty", "Boop", "Female", dob, "Betty@Boop.com", "189507724136", "ahvbn", "USA", lastLogOn, lastLogTime, joined, "$50000.93");

	StudentKey bettyKey = StudentKey(betty);

	cout << "Bettys key initialized from betty's data, ID: " << bettyKey.getUser_id() << ", Name: " << bettyKey.getFirst_name() << ", Email: " << bettyKey.getEmail() << endl;



}
