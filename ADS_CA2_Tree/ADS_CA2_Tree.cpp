// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TNode.h"
#include "Date.h"
#include "Utilities.h"

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

	

	for (int i = 0; i < 3; i++) {
		for (
			auto it = delimitedRows[i].begin();
			it != delimitedRows[i].end(); it++)
			cout << *it << " " << endl;
		cout << endl;
	}



}
