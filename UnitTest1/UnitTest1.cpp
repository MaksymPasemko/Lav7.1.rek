#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.1.rek/pr7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** D = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				D[i] = new int[colCount];
			}

			int testValues[3][3] = {
				{9, 8, 7},
				{6, 5, 4},
				{3, 2, 1}
			};

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					D[i][j] = testValues[i][j];
				}
			}

			Sort(D, rowCount, colCount, 0, 0);

			int expectedValues[3][3] = {
				{3, 2, 1},
				{6, 5, 4},
				{9, 8, 7}
			};

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					Assert::AreEqual(expectedValues[i][j], D[i][j]);
				}
			}

			for (int i = 0; i < rowCount; i++)
				delete[] D[i];
			delete[] D;
		}

		TEST_METHOD(TestCalcFunction)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** D = new int* [rowCount];
			for (int i = 0; i < rowCount; i++) {
				D[i] = new int[colCount];
			}

			int testValues[3][3] = {
				{1, 2, 3},
				{4, 5, 6},
				{7, 8, 9}
			};

			for (int i = 0; i < rowCount; i++) {
				for (int j = 0; j < colCount; j++) {
					D[i][j] = testValues[i][j];
				}
			}

			int S = 0, k = 0;
			Calc(D, rowCount, colCount, S, k, 0, 0);

			int expectedS = 40;
			int expectedk = 8;

			Assert::AreEqual(expectedS, S);
			Assert::AreEqual(expectedk, k);

			for (int i = 0; i < rowCount; i++)
				delete[] D[i];
			delete[] D;
		}
	};
}
