// uf
#include "UnionfindWithSpecificCanonicalElement.h"

// testing
#include <gtest/gtest.h>

namespace uf
{
  namespace unionfindwithspecificcanonicalelementtesting
  {
    TEST(UnionfindWithSpecificCanonicalElementTests, Constructor1Parameter)
    {
      UnionFindWithSpecificCanonicalElement uf(5);

      const std::string expected_str =
	"0: 0 1 0, 1: 1 1 1, 2: 2 1 2, 3: 3 1 3, 4: 4 1 4";
      
      ASSERT_STREQ(uf.to_string().c_str(), expected_str.c_str());
    }

    TEST(UnionfindWithSpecificCanonicalElementTests, Join)
    {
      UnionFindWithSpecificCanonicalElement uf(5);

      std::string expected_str =
	"0: 0 1 0, 1: 1 1 1, 2: 2 1 2, 3: 3 1 3, 4: 4 1 4";
      
      uf.join(0, 4);

      expected_str = "0: 0 2 4, 1: 1 1 1, 2: 2 1 2, 3: 3 1 3, 4: 0 1 4";

      ASSERT_STREQ(uf.to_string().c_str(), expected_str.c_str());
    }

    TEST(UnionfindWithSpecificCanonicalElementTests, Find)
    {
      UnionFindWithSpecificCanonicalElement uf(5);

      std::string expected_str =
	"0: 0 1 0, 1: 1 1 1, 2: 2 1 2, 3: 3 1 3, 4: 4 1 4";
      
      uf.join(0, 4);

      expected_str = "0: 0 2 4, 1: 1 1 1, 2: 2 1 2, 3: 3 1 3, 4: 0 1 4";

      ASSERT_STREQ(uf.to_string().c_str(), expected_str.c_str());

      ASSERT_EQ(uf.find(0), 4);
    }

    TEST(UnionfindWithSpecificCanonicalElementTests, BugFix)
    {
      UnionFindWithSpecificCanonicalElement uf(5);
      uf.join(2, 3);
      uf.join(4, 3);
      ASSERT_EQ(uf.find(0), 0);
      ASSERT_EQ(uf.find(1), 1);
      ASSERT_EQ(uf.find(2), 4);
      ASSERT_EQ(uf.find(3), 4);
      ASSERT_EQ(uf.find(4), 4);
    }

  } // ! namespace unionfindwithspecificcanonicalelementtesting
} // ! namespace uf
