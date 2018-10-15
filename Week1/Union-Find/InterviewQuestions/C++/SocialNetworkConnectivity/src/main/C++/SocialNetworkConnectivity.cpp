// sn
#include "SocialNetworkConnectivity.h"

// C++
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

namespace sn
{
  SocialNetworkConnectivity::SocialNetworkConnectivity(
    std::size_t N,
    const boost::filesystem::path& logFile
  )
    : m_N(N)
    , m_num_components(N)
    , m_uf(this->m_N)
    , m_t(boost::none)
  {
    if (this->m_N < 2)
    {
	// All members are already connected.
	return;
    }

    // Parse the logfile

    std::ifstream ifs(logFile.string());

    std::string line;
    while (std::getline(ifs, line))
    {
      // Parse current line of logFile.
      std::stringstream ss(line);
      std::string s;
      char delimeter = ' ';
      
      // retrieve id1
      if (!std::getline(ss, s, delimeter))
      {
	SocialNetworkConnectivity::report(line);
      }
      const std::size_t id1 = s[0]-'0';

      // retrieve id2
      if (!std::getline(ss, s, delimeter))
      {
	SocialNetworkConnectivity::report(line);
      }
      const std::size_t id2 = s[0]-'0';

      // retrieve timestamp
      if (!std::getline(ss, s))
      {
	SocialNetworkConnectivity::report(line);
      }
      boost::posix_time::ptime t(boost::posix_time::time_from_string(s));

      // Add connection between id1 and id2
      if (!this->m_uf.connected(id1, id2))
      {
	this->m_uf.join(id1, id2);
	--this->m_num_components;
	
	if (this->m_num_components == 1)
	{
	  this->m_t = t;
	  ifs.close();
	  break;
	}
      }
    }
    
    ifs.close();
  }

  boost::optional<boost::posix_time::ptime> SocialNetworkConnectivity::FullyConnectedTime() const
  {
    return this->m_t;
  }

  void SocialNetworkConnectivity::report(const std::string& s)
  {
    throw std::logic_error("Improperly formatted log entry: " + s);
  }
}
