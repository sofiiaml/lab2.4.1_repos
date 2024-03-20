#include "pch.h"
#include "CppUnitTest.h"
#include "../2.4/Matrix.h"
#include "../2.4/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest24
{
	TEST_CLASS(UnitTest24)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Matrix m3(2);

			for (int i = 0; i < m3.getSize(); ++i) {
				for (int j = 0; j < m3.getSize(); ++j) {
					m3[i][j] = i * j; 
				}
			}

			Assert::AreEqual(1, m3.Norma());
		}
	};
}
