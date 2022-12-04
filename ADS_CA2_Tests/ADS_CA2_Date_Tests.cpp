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

namespace ADSCA2Tests
{
	TEST_CLASS(ADSCA2Tests)
	{
	public:

		
			TEST_METHOD(TestMethod1)
			{
				Date testDate = Date(11, 10, 2000);
				int dayExtracted = testDate.getDay();
				string actualDay = "11";


				// Stringstreamused to get value represented as a string for comparison in assert statement
				// Got some problems when trying to compare 2 u-short-ints in the assert statement

				stringstream extractedDay;
				extractedDay << dayExtracted;

				string finDay;
				extractedDay >> finDay;

				Assert::AreEqual(actualDay, finDay);
			}
			TEST_METHOD(TestMethod2)
			{
				Date testDate = Date(11, 10, 2000);
				int monthExtracted = testDate.getMonth();
				string actualMonth = "10";

				stringstream extractedMonth;
				extractedMonth << monthExtracted;

				string finMonth;
				extractedMonth >> finMonth;

				Assert::AreEqual(actualMonth, finMonth);
			}
			TEST_METHOD(TestMethod3)
			{
				Date testDate = Date(11, 10, 2000);
				int yearExtracted = testDate.getYear();
				string actualYear = "2000";

				stringstream extractedYear;
				extractedYear << yearExtracted;

				string finYear;
				extractedYear >> finYear;

				Assert::AreEqual(actualYear, finYear);
			}
			TEST_METHOD(TestMethod4)
			{
				Date testDate = Date("07/11/2005");
				int yearExtracted = testDate.getYear();
				string actualYear = "2005";

				stringstream extractedYear;
				extractedYear << yearExtracted;

				string finYear;
				extractedYear >> finYear;

				Assert::AreEqual(actualYear, finYear);
			}
			TEST_METHOD(TestMethod5)
			{
				Date testDate = Date("07/11/2005");
				int monthExtracted = testDate.getMonth();
				string actualMonth = "11";

				stringstream extractedMonth;
				extractedMonth << monthExtracted;

				string finMonth;
				extractedMonth >> finMonth;

				Assert::AreEqual(actualMonth, finMonth);
			}
		
	};
}
