#include "pch.h"
#include "CppUnitTest.h"
#include "../LinkedList/DoublyLinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(AppendOneItem) {
			DoublyLinkedList<int> l1;

			l1.append(43);
			int ans{ l1.get(0) };
			Assert::AreEqual(ans, 43);
		}
		TEST_METHOD(ThisOneFails) {
			Assert::IsTrue(false);
		}

		TEST_METHOD(Fail) {
			Assert::Fail();
		}

		TEST_METHOD(Null) {
			int* a = nullptr;
			Assert::IsNull(a);
		}

		TEST_METHOD(AreNotEqual) {
			Assert::AreNotEqual(1, 2);
		}
	};
}
