#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
#include "../ADS_CA2_Tree/TNode.h"
#include "../ADS_CA2_Tree/Student.h"
#include "../ADS_CA2_Tree/StudentKey.h"
#include "../ADS_CA2_Tree/Date.h"
#include "../ADS_CA2_Tree/Time.h"
#include "../ADS_CA2_Tree/Utilities.h"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ADSCA2BinTreeTests
{
	TEST_CLASS(ADSCA2BinTreeTests)
	{
	public:

		/*
		Test that the search returns nullptr if binary tree empty
		*/

		TEST_METHOD(TestSearchEmpty)
		{

		}

		/*
		Test the search returns correct pointer if node exists in tree
		*/

		TEST_METHOD(TestSearchGuaranteedInTree)
		{

		}

		/*
		Test the search returns nullptr pointer if key provided slightly incorrect compared to stored key in existing node
		*/

		TEST_METHOD(TestSearchErrorInProvidedKey)
		{

		}

		/*
		Test that a node gets inserted since it does not already exist in the tree
		*/

		TEST_METHOD(TestInsertNovelNode)
		{
			/*vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF//ADS_CA2_Tree//data_1000.csv");

			string timeDelimiter = ":";


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
			TNode<StudentKey, Student> newNode(newerKey, newerStudent);
			bool truth = newNode.insert(newerKey, newerStudent);
			cout << truth;

			cout << "\n" << newNode.getData().getEmail() << endl;
			TNode<StudentKey, Student>* newestNode = newNode.getpRight();
			cout << "\n" << newestNode->getData().getEmail() << endl;*/



			
		}

		/*
			Test that a node gets rejected since it already exists in the tree
			*/
		TEST_METHOD(TestInsertDuplicateNode)
		{
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
					TNode<StudentKey, Student>* newestNode = newNode.getpRight();
					cout << "\n" << newestNode->getData().getEmail() << endl;

					break;
				}

			}
		}

		/*
		Test that a leaf gets deleted and doesnt impact the rest of the tree
		*/

		TEST_METHOD(TestDeleteLeaf)
		{

		}

		/*
		Test that a node with 1 child gets deleted, and all children also get deleted
		*/

		TEST_METHOD(TestDeleteNodeWith1Child)
		{

		}

		/*
		Test that a node with 2 children gets deleted, and all children also get deleted
		*/

		TEST_METHOD(TestDeleteNodeWith2Children)
		{

		}

		/*
		Test that if the root node gets deleted the entire tree is gone
		*/

		TEST_METHOD(TestDeleteRootNode)
		{

		}

		/*
		Test that the print function works
		*/

		TEST_METHOD(TestPrint)
		{

		}

	};
}
