#ifndef WEIGHTEDQUICKUNIONWITHPATHHALVING_H_
#define WEIGHTEDQUICKUNIONWITHPATHHALVING_H_

// C++
#include <deque>
#include <cstdlib>
#include <string>
#include <iosfwd>

namespace uf
{
	class WeightedQuickUnionWithPathHalving final
	{
	 public:

		using size_type = std::deque<std::size_t>::size_type;

		WeightedQuickUnionWithPathHalving(size_type N);
		WeightedQuickUnionWithPathHalving(const WeightedQuickUnionWithPathHalving&) = delete;
		WeightedQuickUnionWithPathHalving& operator=(const WeightedQuickUnionWithPathHalving&) = delete;
		WeightedQuickUnionWithPathHalving(WeightedQuickUnionWithPathHalving&&) = delete;
		WeightedQuickUnionWithPathHalving& operator=(WeightedQuickUnionWithPathHalving&&) = delete;
		~WeightedQuickUnionWithPathHalving();

		bool connected(size_type i, size_type j);
		void join(size_type i, size_type j);
		size_type find(size_type i);
		std::string toString() const;

	 private:
		size_type m_N;
		std::size_t *m_id;
		std::size_t *m_sz;

	}; // ! class WeightedQuickUnionWithPathHalving

	std::ostream& operator<<(std::ostream& os, const WeightedQuickUnionWithPathHalving& uf);

} // ! namespace uf

#endif // ! WEIGHTEDQUICKUNIONWITHPATHHALVING_H_
