#ifndef SOCIALNETWORKCONNECTIVITY_H_
#define SOCIALNETWORKCONNECTIVITY_H_

// uf
#include "WeightedQuickUnionWithPathHalving.h"

// Boost
#include <boost/optional.hpp>
#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

// C++
#include <iosfwd>
#include <cstdlib>
#include <stdexcept>
#include <string>

namespace sn
{
  class SocialNetworkConnectivity final
  {
   public:
    SocialNetworkConnectivity( std::size_t N
			     , const boost::filesystem::path& logFile
			     );
    SocialNetworkConnectivity(const SocialNetworkConnectivity&) = delete;
    SocialNetworkConnectivity& operator=(const SocialNetworkConnectivity&) = delete;
    SocialNetworkConnectivity(SocialNetworkConnectivity&&) = delete;
    SocialNetworkConnectivity& operator=(SocialNetworkConnectivity&&) = delete;
    ~SocialNetworkConnectivity() = default;

    boost::optional<boost::posix_time::ptime> FullyConnectedTime() const;

   private:

    static void report(const std::string& s);

    std::size_t m_N;
    std::size_t m_num_components;
    uf::WeightedQuickUnionWithPathHalving m_uf;
    boost::optional<boost::posix_time::ptime> m_t;
  };

} // ! namespace sn

#endif // ! SOCIALNETWORKCONNECTIVITY_H_
