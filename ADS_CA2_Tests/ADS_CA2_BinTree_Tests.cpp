#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
#include "../ADS_CA2_Tree/TNode.h"
#include "../ADS_CA2_Tree/Utilities.h"
#include <vector>
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

			vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

			BinaryTree<size_t, Student> newTree;

			for (int i = 1; i < 21; i++) {
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
				//newTree.insert(newKey.getHash(), newStudent);
				//cout << newKey.getHash() << endl;
			}

			StudentKey dummyKey(delimitedRows[9][0], delimitedRows[9][2], delimitedRows[9][6]);


			TNode<size_t, Student>* searchedNode = newTree.search(dummyKey.getHash());

			Assert::IsNull(searchedNode);


		}

		/*
		Test the search returns correct pointer if node exists in tree
		*/

		TEST_METHOD(TestSearchGuaranteedInTree)
		{

			vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

			BinaryTree<size_t, Student> newTree;

			for (int i = 1; i < 21; i++) {
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

			string timeDelimiter = ":";
			Date dateOfBirth(delimitedRows[9][5]);
			Date lastLogOnDate(delimitedRows[9][10]);
			string logOnTime = delimitedRows[9][11];
			unsigned short int hours = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
			logOnTime = logOnTime.substr(3);
			unsigned short int minutes = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
			TimeHHMM lastLogOnTime(hours, minutes);
			Date joinedOn(delimitedRows[9][12]);

			Student dummyStudent(delimitedRows[9][0], stoi(delimitedRows[9][1]), delimitedRows[9][2], delimitedRows[9][3], delimitedRows[9][4], dateOfBirth,
				delimitedRows[9][6], delimitedRows[9][7], delimitedRows[9][8], delimitedRows[9][9], lastLogOnDate, lastLogOnTime, joinedOn, delimitedRows[9][13]);



			StudentKey dummyKey(delimitedRows[9][0], delimitedRows[9][2], delimitedRows[9][6]);


			TNode<size_t, Student>* createdNode = new TNode<size_t, Student>(dummyKey.getHash(), dummyStudent);


			TNode<size_t, Student>* searchedNode = newTree.search(dummyKey.getHash());

			Assert::AreEqual(searchedNode->getKey(), createdNode->getKey());

		}

		/*
		Test the search returns nullptr if key provided slightly incorrect compared to stored key in existing node
		*/

		TEST_METHOD(TestSearchErrorInProvidedKey)
		{
			vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

			BinaryTree<size_t, Student> newTree;

			for (int i = 1; i < 10; i++) {
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

			StudentKey dummyKey(delimitedRows[9][0], delimitedRows[9][2], delimitedRows[10][6]);


			TNode<size_t, Student>* searchedNode = newTree.search(dummyKey.getHash());

			Assert::IsNull(searchedNode);
		}

		/*
		Test that a node gets inserted since it does not already exist in the tree
		*/

		TEST_METHOD(TestInsertNovelNode)
		{
			vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

			BinaryTree<size_t, Student> newTree;

			for (int i = 1; i < 2; i++) {
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
				Assert::IsTrue(newTree.insert(newKey.getHash(), newStudent));
				//cout << newKey.getHash() << endl;
			}
		}

		/*
		Test that a node gets rejected since it already exists in the tree
		*/

		TEST_METHOD(TestInsertDuplicateNode)
		{
			vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

			BinaryTree<size_t, Student> newTree;

			for (int i = 1; i < 2; i++) {
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
				
				newTree.insert(newKey.getHash(), newStudent);
				
			}

			for (int i = 1; i < 2; i++) {
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

				Assert::IsFalse(newTree.insert(newKey.getHash(), newStudent));

			}


		}

		/*
		Test that a leaf gets deleted and doesnt impact the rest of the tree
		*/

		TEST_METHOD(TestDeleteLeaf)
		{
			
			/*BinaryTree<size_t, Student> newTree;

				Date dob(1,1,2000);
				TimeHHMM timez(11,11);

				Student student1 = Student("123", 145, "jake", "q", "q", dob, "jake@g.com", "q", "q", "q", dob, timez, dob, "q");
				size_t key1(1);
				newTree.insert(key1, student1);


				Student student2 = Student("1234", 146, "jacque", "q", "q", dob, "jacquee@g.com", "q", "q", "q", dob, timez, dob, "q");
				size_t key2(2);
				newTree.insert(key2, student2);

				Student student3 = Student("12345", 147, "jamal", "q", "q", dob, "jamal@g.com", "q", "q", "q", dob, timez, dob, "q");
				size_t key3(3);
				newTree.insert(key3, student3);


				Student student4 = Student("123456", 147, "jamie", "q", "q", dob, "jamie@g.com", "q", "q", "q", dob, timez, dob, "q");
				size_t key4(4);
				newTree.insert(key4, student4);

				Student student5 = Student("1234567", 148, "john", "q", "q", dob, "john@g.com", "q", "q", "q", dob, timez, dob, "q");
				size_t key5(5);
				newTree.insert(key5, student5);

			


			cout << "\nCount: " << newTree.count() << endl;
			cout << "\nFound and deleted?: " << newTree.removeWithAllChildren(1) << endl;
			cout << "\nCount: " << newTree.count() << endl;


			TNode<size_t, Student>* myStudent = newTree.search(1);

			if (myStudent == nullptr) {
				cout << "Student not found" << endl;
			}
			else
			{
				myStudent->getData().print();
			}*/
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

		/*
		Test Depth
		We insert 8 nodes in the below order, depth is known to us for each node in the tree
		-------------------------------------------------------------------------------------------------------------
		12275897570252230347 : Depth: 0
		16315192520644851543 : Depth: 1
		16174130221309972733 : Depth: 2
		8804579525034649440  : Depth: 1
		2079302527258165070  : Depth: 2
		65178743057616710    : Depth: 3
		9676129817918951533  : Depth: 2
		13089421674834142963 : Depth: 3

		*/
		TEST_METHOD(TestDepthFunctionOnLeaf)
		{
			vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

			BinaryTree<size_t, Student> newTree;

			for (int i = 1; i < 9; i++) {
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

				newTree.insert(newKey.getHash(), newStudent);

			}

			StudentKey dummyKey(delimitedRows[8][0], delimitedRows[8][2], delimitedRows[8][6]);

			size_t depthOfLeafNode = newTree.depth(dummyKey.getHash());

			int integerizedDepth = static_cast<int>(depthOfLeafNode);
			int actualDepth = 3;

			

			try {

				Assert::AreEqual(integerizedDepth, actualDepth);
			}
			catch (const std::out_of_range& e)
			{
				cout << "The node doesnt exist in the tree" << endl;
				int zero = 0;
				int one = 1;
				Assert::AreEqual(one, zero);
			}
		}

		TEST_METHOD(TestDepthFunctionOnMidNode)
		{
			vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

			BinaryTree<size_t, Student> newTree;

			for (int i = 1; i < 9; i++) {
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

				newTree.insert(newKey.getHash(), newStudent);

			}

			StudentKey dummyKey(delimitedRows[2][0], delimitedRows[2][2], delimitedRows[2][6]);

			size_t depthOfLeafNode = newTree.depth(dummyKey.getHash());

			int integerizedDepth = static_cast<int>(depthOfLeafNode);
			int actualDepth = 1;

			


			try {

				Assert::AreEqual(integerizedDepth, actualDepth);
			}
			catch (const std::out_of_range& e)
			{
				cout << "The node doesnt exist in the tree" << endl;
				int zero = 0;
				int one = 1;
				Assert::AreEqual(one, zero);
			}
		}

		TEST_METHOD(TestDepthFunctionOnInexistentNode)
		{
			vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

			BinaryTree<size_t, Student> newTree;

			for (int i = 1; i < 10; i++) {

				
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

				if (i < 9) {
					newTree.insert(newKey.getHash(), newStudent);
				}

			}

			//StudentKey dummyKey(delimitedRows[10][0], delimitedRows[1][2], delimitedRows[1][6]);
			size_t hashForTenth = 4690520465930778477;
			int integerizedHash = static_cast<int>(hashForTenth);
			



			try {
				size_t depthOfLeafNode = newTree.depth(hashForTenth);
				int integerizedDepth = static_cast<int>(depthOfLeafNode);
				int actualDepth = 0;

				Assert::AreEqual(integerizedDepth, actualDepth);
			}
			catch (const std::out_of_range& e)
			{
				cout << "The node doesnt exist in the tree" << endl;
				int zero = 0;
				Assert::AreEqual(integerizedHash, zero);
			}

			
		}

		TEST_METHOD(TestDepthFunctionOnRoot)
		{
			vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//nfeda//source//repos//ADS_2022_ICA2_KW_NF_//ADS_CA2_Tree//data_1000.csv");

			BinaryTree<size_t, Student> newTree;

			for (int i = 1; i < 10; i++) {


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

			
				newTree.insert(newKey.getHash(), newStudent);
				

			}

			// Root hash = 12275897570252230347

			try {
				size_t depthOfLeafNode = newTree.depth(12275897570252230347);
				int integerizedDepth = static_cast<int>(depthOfLeafNode);
				int actualDepth = 0;

				Assert::AreEqual(integerizedDepth, actualDepth);
			}
			catch (const std::out_of_range& e)
			{
				cout << "The node doesnt exist in the tree" << endl;
				int one = 1;
				int zero = 0;
				Assert::AreEqual(one, zero);
			}


		}
	};
}
