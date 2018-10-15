// uf
#include "WeightedQuickUnionWithPathHalving.h"

// testing
#include <gtest/gtest.h>

namespace uf
{
	namespace weightedquickunionwithpathhalvinftesting
	{
		TEST(WeightedQuickUnionWithPathHalving, ConstructorOneParameter)
		{
			WeightedQuickUnionWithPathHalving uf(5);
			const std::string expected_str =
					"0: 0 1, 1: 1 1, 2: 2 1, 3: 3 1, 4: 4 1";
			ASSERT_STREQ(uf.toString().c_str(), expected_str.c_str());
		}

		TEST(WeightedQuickUnionWithPathHalving, Union)
		{
			WeightedQuickUnionWithPathHalving uf(5);
			uf.join(1, 2);
			ASSERT_STREQ(uf.toString().c_str(), "0: 0 1, 1: 1 2, 2: 1 1, 3: 3 1, 4: 4 1");
			uf.join(3, 4);
			ASSERT_STREQ(uf.toString().c_str(), "0: 0 1, 1: 1 2, 2: 1 1, 3: 3 2, 4: 3 1");
			uf.join(3, 1);
			ASSERT_STREQ(uf.toString().c_str(), "0: 0 1, 1: 3 2, 2: 1 1, 3: 3 4, 4: 3 1");
			uf.join(0, 3);
			ASSERT_STREQ(uf.toString().c_str(), "0: 3 1, 1: 3 2, 2: 1 1, 3: 3 5, 4: 3 1");
		}

	} // ! weightedquickunionwithpathhalvinftesting
} // ! namespace uf
