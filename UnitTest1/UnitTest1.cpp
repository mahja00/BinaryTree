#include "pch.h"
#include "CppUnitTest.h"
#include "../Drzewo_/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		Tree tree;

		TEST_METHOD(Test_Constructor)
		{
			Assert::IsNull(tree.root);
			Assert::AreEqual(tree.size, 0);
			
		}
		TEST_METHOD(Test_Insert_Node)
		{
			tree.insert(3);
			int val = tree.root->val;
			Assert::AreEqual(val, 3);
		}

		TEST_METHOD(Test_SumUp)
		{

			tree.insert(3);
			tree.insert(4);
			tree.insert(7);
			tree.insert(8);
			
			Assert::AreEqual(tree.sumUp(), 22);
		}

		TEST_METHOD(Test_Insert_Size)
		{

			tree.insert(3);
			tree.insert(4);
			tree.insert(7);
			tree.insert(8);

			Assert::AreEqual(tree.size, 4);
		}

		TEST_METHOD(Test_Find_Median_Odd) {

			tree.insert(3);
			tree.insert(4);
			tree.insert(5);
			tree.insert(8);
			
			Assert::AreEqual(tree.findMedian(), 4.5);
			
		}

		TEST_METHOD(Test_Find_Median_Even) {

			
			tree.insert(1);
			tree.insert(4);
			tree.insert(3);
			tree.insert(4);
			tree.insert(12);
		

			//for even case
			Assert::AreEqual(tree.findMedian(), 4.0);
		
		}

	};
}
