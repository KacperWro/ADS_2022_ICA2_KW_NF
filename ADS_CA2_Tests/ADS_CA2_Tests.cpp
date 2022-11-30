#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
#include "../ADS_CA2_Tree/TNode.h"
#include "../ADS_CA2_Tree/Student.h"
#include "../ADS_CA2_Tree/StudentKey.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ADSCA2Tests
{
	TEST_CLASS(ADSCA2Tests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student s();
			TNode<int, int> someNode;
			Assert::AreEqual(1, 1);
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(1, 2);
		}
	};
}
