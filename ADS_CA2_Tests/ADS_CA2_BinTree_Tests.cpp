#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
#include "../ADS_CA2_Tree/TNode.h"
#include "../ADS_CA2_Tree/Student.h"
#include "../ADS_CA2_Tree/StudentKey.h"
#include "../ADS_CA2_Tree/Date.h"
#include "../ADS_CA2_Tree/Time.h"
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
