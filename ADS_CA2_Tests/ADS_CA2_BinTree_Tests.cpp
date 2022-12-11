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
		vector<vector<string>> delimitedRows = readDelimitedRows("C://Users//Kacper//OneDrive - Dundalk Institute of Technology//Algs + Data//data_1000.csv");

		//FUNCTION FOR CREATING SAMPLE BINARY TREE FROM CSV FILE TO USE FOR TESTING
		BinaryTree<size_t, Student> sampleTree(int size) {
			
			BinaryTree<size_t, Student> sampleTree;

			for (int i = 1; i < size; i++) {
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
				sampleTree.insert(newKey.getHash(), newStudent);
				cout << newKey.getHash() << endl;
			}
			return sampleTree;
		}

		//RETURNS A STUDENT FROM A GIVEN INDEX IN THE 'delimitedRows' VECTOR
		Student getSampleStudent(int index) {
			string timeDelimiter = ":";
			Date dateOfBirth(delimitedRows[index][5]);
			Date lastLogOnDate(delimitedRows[index][10]);
			string logOnTime = delimitedRows[index][11];
			unsigned short int hours = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
			logOnTime = logOnTime.substr(3);
			unsigned short int minutes = stoi(logOnTime.substr(0, logOnTime.find(timeDelimiter)));
			TimeHHMM lastLogOnTime(hours, minutes);
			Date joinedOn(delimitedRows[index][12]);

			Student sampleStudent(delimitedRows[index][0], stoi(delimitedRows[index][1]), delimitedRows[index][2], delimitedRows[index][3], delimitedRows[index][4], dateOfBirth,
				delimitedRows[index][6], delimitedRows[index][7], delimitedRows[index][8], delimitedRows[index][9], lastLogOnDate, lastLogOnTime, joinedOn, delimitedRows[index][13]);

			return sampleStudent;

		}


		/*
		Test that the search returns nullptr if binary tree empty
		*/

		TEST_METHOD(TestSearchEmpty)
		{
			BinaryTree<size_t, Student> newTree = sampleTree(0);
			StudentKey sampleKey(delimitedRows[22][0], delimitedRows[22][2], delimitedRows[22][6]);
			TNode<size_t, Student>* searchedNode = newTree.search(sampleKey.getHash());

			//SEARCHING FOR ANY NODE IN THIS TREE WILL RETURN 'nullptr' AS THE TREE DOES NOT CONTAIN ANY NODES
			Assert::IsNull(searchedNode);
		}

		/*
		Test the search returns the correct node by comparing the key of the returned node, and the key that was passed to the search function
		*/

		TEST_METHOD(TestSearchGuaranteedInTree)
		{
			BinaryTree<size_t, Student> newTree = sampleTree(21);
			StudentKey sampleKey(delimitedRows[9][0], delimitedRows[9][2], delimitedRows[9][6]);
			TNode<size_t, Student>* searchedNode = newTree.search(sampleKey.getHash());

			Assert::AreEqual(searchedNode->getKey(), sampleKey.getHash());
		}

		/*
		Test the search returns nullptr if key provided slightly incorrect compared to stored key in existing node
		*/

		TEST_METHOD(TestSearchErrorInProvidedKey)
		{
			BinaryTree<size_t, Student> newTree = sampleTree(21);

			//USER ID AND FIRST NAME ARE FROM ONE STUDENT OBJECT, WHILE THE EMAIL HAS BEEN TAKEN FROM ANOTHER STUDENT OBJECT, RESULTING IN AN INCORRECT HASH KEY
			StudentKey sampleKey(delimitedRows[9][0], delimitedRows[9][2], delimitedRows[10][6]);
			TNode<size_t, Student>* searchedNode = newTree.search(sampleKey.getHash());

			//SEARCHING USING THIS INCORRECT KEY WILL RETURN 'nullptr' AS THIS KEY IS NOT ASSOCIATED WITH ANY NODE IN THE BINARY TREE
			Assert::IsNull(searchedNode);
		}

		/*
		Test that a node gets inserted since it does not already exist in the tree
		*/

		TEST_METHOD(TestInsertNewNode)
		{
			BinaryTree<size_t, Student> newTree = sampleTree(2);

			Student sampleStudent = getSampleStudent(9);
			StudentKey sampleKey(delimitedRows[9][0], delimitedRows[9][2], delimitedRows[9][6]);

			Assert::IsTrue(newTree.insert(sampleKey.getHash(), sampleStudent));
		}

		/*
		Test that number of nodes in binary tree is only increased by one after inserting one new node
		*/

		TEST_METHOD(TestInsertCountIncreasedBy1)
		{
			BinaryTree<size_t, Student> newTree = sampleTree(2);

			int countBeforeInsert = newTree.count();
			Student sampleStudent = getSampleStudent(9);
			StudentKey sampleKey(delimitedRows[9][0], delimitedRows[9][2], delimitedRows[9][6]);
			newTree.insert(sampleKey.getHash(), sampleStudent);
			int countAfterInsert = newTree.count();

			//SINCE WE ARE ONLY INSERTING ONE NEW NODE, THE COUNT OF NODES IN THE BINARY TREE WILL ONLY BE INCREASED BY 1
			Assert::AreEqual(countBeforeInsert + 1, countAfterInsert);
		}


		/*
		Test that a node gets rejected since it already exists in the tree
		*/

		TEST_METHOD(TestInsertDuplicateNode)
		{
			BinaryTree<size_t, Student> newTree = sampleTree(5);

			int countBeforeInsert = newTree.count();
			Student sampleStudent = getSampleStudent(2);
			StudentKey sampleKey(sampleStudent.getUser_id(), sampleStudent.getFirst_name(), sampleStudent.getEmail());
			int countAfterInsert = newTree.count();

			//COUNT OF NODES BEFORE INSERT AND COUNT OF NODES AFTER INSERT WILL BE THE SAME SINCE WE ARE TRYING TO INSERT A KEY WHICH ALREADY HAS A NODE ASSOCIATED WITH IT IN THE BINARY TREE
			Assert::AreEqual(countBeforeInsert, countAfterInsert);
		}

		/*
	Test that a leaf gets deleted and doesnt impact the rest of the tree
	*/

		TEST_METHOD(TestDeleteLeaf)
		{
			BinaryTree<size_t, Student> newTree = sampleTree(21);
			TNode<size_t, Student>* toBeRemoved = newTree.root->getpLeft()->getpLeft()->getpLeft()->getpRight();

			int countBeforeDelete = newTree.count();
			newTree.remove(toBeRemoved->getKey(), toBeRemoved->getKey());
			int countAfterDelete = newTree.count();

			//Since we are only deleting a leaf (meaning it has no children), we expect the total number of nodes to be decrased by 1
			Assert::AreEqual(countAfterDelete, countBeforeDelete - 1);
		}

		/*
		Test that a node with 1 child gets deleted, and all children also get deleted
		*/

		TEST_METHOD(TestDeleteNodeWith1Child)
		{
			BinaryTree<size_t, Student> newTree = sampleTree(21);
			TNode<size_t, Student>* toBeRemoved = newTree.root->getpLeft()->getpLeft()->getpLeft();

			int countBeforeDelete = newTree.count();
			newTree.remove(toBeRemoved->getKey(), toBeRemoved->getKey());
			int countAfterDelete = newTree.count();

			//Since we are only deleting a node with only 1 child that doesn't have any of its own children, we expect the total number of nodes to be decreased by 2
			Assert::AreEqual(countAfterDelete, countBeforeDelete - 2);
		}

		/*
		Test that a node with 2 children gets deleted, and all children also get deleted
		*/

		TEST_METHOD(TestDeleteNodeWith2Children)
		{
			BinaryTree<size_t, Student> newTree = sampleTree(21);

			//CREATING SUB TREE OUT OF THE NODE THAT WE WANT TO DELETE
			BinaryTree<size_t, Student> subTree = newTree.getSubTree(newTree.root->getpLeft());
			TNode<size_t, Student>* toBeRemoved = newTree.root->getpLeft();

			//VERIFYING THAT THE NODE WE ARE DELETING HAS AT LEAST 2 CHILDREN. IF IT DOESN'T HAVE A LEFT CHILD OR A RIGHT CHILD, AN EXCEPTION SHOULD OCCUR
			cout << subTree.root->getpLeft()->getKey();
			cout << subTree.root->getpRight()->getKey();

			int countBeforeDelete = newTree.root->count();

			//WE ARE GETTING THE COUNT OF NODES IN THE NEW SUB TREE. THIS IS HOW MANY NODES ARE EXPECTED TO BE DELETED IN THE ORIGINAL 'newTree'
			int countSubTree = subTree.root->count();
			newTree.remove(toBeRemoved->getKey(), toBeRemoved->getKey());
			int countAfterDelete = newTree.count();

			//WE PUT THE COUNT OF NODES AFTER DELETION AS THE EXPECTED VALUE
			//WE TAKE AWAY THE COUNT OF NODES IN THE SUBTREE CREATED USING THE NODE WE WANT TO DELETE. WE TOOK THAT VALUE AWAY FROM THE COUNT OF NODES IN THE ORIGINAL TREE BEFORE 'remove()' WAS CALLED
			Assert::AreEqual(countAfterDelete, countBeforeDelete - countSubTree);
		}

		/*
		Test that if the root node gets deleted the entire tree is gone
		*/

		TEST_METHOD(TestDeleteRootNode)
		{
			BinaryTree<size_t, Student> newTree = sampleTree(21);

			int countBeforeDelete = newTree.root->count();
			newTree.remove(newTree.root->getKey(), newTree.root->getKey());
			int countAfterDelete = newTree.count();

			//SINCE WE ARE DELETING THE ROOT NODE, THE EXPECTED VALUE IS '0'
			Assert::AreEqual(0, countAfterDelete);
		}


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
