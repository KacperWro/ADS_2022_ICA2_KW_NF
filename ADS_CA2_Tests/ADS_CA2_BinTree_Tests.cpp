#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
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

		}

		/*
		Test that a node gets rejected since it already exists in the tree
		*/

		TEST_METHOD(TestInsertDuplicateNode)
		{

		}

		/*
		Test that a leaf gets deleted and doesnt impact the rest of the tree
		*/

		TEST_METHOD(TestDeleteLeaf)
		{
			
			BinaryTree<size_t, Student> newTree;

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
				myStudent->printNode();
			}
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
