#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab6.1(2)/lab6.1(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestFillArray)
		{
			int myArray[21];
			fillArray(myArray);
			for (int i = 0; i < 21; ++i) {
				Assert::IsTrue(myArray[i] >= 10 && myArray[1] <= 90);
			}
		}

		TEST_METHOD(TestProcessArray)
		{
			int myArray[21] = { 12, 15, 18, 21,
				24, 27, 30, 33, 36, 39 };
			int count = 0, sum = 0;

			processArrayRecursive(myArray, 0, count, sum);

			Assert::AreEqual(16, count);
			Assert::AreEqual(120, sum);

			for (int i = 0; i < 21; ++i) {
				if (!(myArray[i] % 2 != 0 && myArray[i] % 3 == 0)) {
					Assert::AreEqual(0, myArray[i]);
				}
			};
		}
	};
}