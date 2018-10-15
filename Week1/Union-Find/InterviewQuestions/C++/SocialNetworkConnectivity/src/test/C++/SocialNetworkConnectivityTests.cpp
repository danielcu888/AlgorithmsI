// sn
#include "SocialNetworkConnectivity.h"

// testing
#include "globals.h"
#include <gtest/gtest.h>

namespace sn
{
  namespace socialconnectivitytesting
  {
    TEST(SocialNetworkConnectivityTests, Constructor2Parameter)
    {
      boost::filesystem::path p = globals::test_resources_dir;
      p.append("logfile.txt");

      const SocialNetworkConnectivity s(5, p);
      //boost::optional<std::string> t = s.FullyConnectedTime();
      //ASSERT_NE(t, boost::none);
      //const std::string tm = *t;
      //ASSERT_STREQ(tm.c_str(), "12:09 12th December 1978");
    }

  } // ! namespace socialconnectivitytesting
} // ! namespace sn
