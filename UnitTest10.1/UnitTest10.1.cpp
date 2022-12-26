#include "pch.h"
#include "CppUnitTest.h"
#include "../ChyrunSofialab10.1/ChyrunSofialab10.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101
{
	TEST_CLASS(UnitTest101)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			char str[10] = ".abd.hkv.";
			t = Count(str);
			Assert::AreEqual(t, 3);
		}
	};
}
