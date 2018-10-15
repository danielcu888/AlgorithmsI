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
      boost::optional<boost::posix_time::ptime> t = s.FullyConnectedTime();
      ASSERT_NE(t, boost::none);
      boost::posix_time::ptime tm = *t;
      ASSERT_STREQ(boost::posix_time::to_simple_string(tm).c_str(), "1978-Dec-14 12:09:00");
    }

  } // ! namespace socialconnectivitytesting
} // ! namespace sn
