// ADS_CA2_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "TNode.h"
#include "Date.h"

int main()
{
	try {
		Date x = Date("11/11/2005");
		cout << "Year from main()" << x.getYear();
	}
	catch(int x) {
		cout << "Something went wrong with initialisation. ERROR CODE: " << x << endl;
	}
}
