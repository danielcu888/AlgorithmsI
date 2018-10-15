// Testing
#include "globals.h"
#include "gtest/gtest.h"

int main(int argc, char *argv[])
{
  globals::test_resources_dir = boost::filesystem::path(argv[1]);

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
