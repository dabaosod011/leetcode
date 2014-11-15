#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/longest-consecutive-sequence/
*/

namespace longest_consecutive_sequence
{
	class Solution 
	{
	public:
		int longestConsecutive(vector<int> &num) 
		{
			return 0;
		}
	};
};

BOOST_AUTO_TEST_SUITE( longest_consecutive_sequence_test )

	boost::shared_ptr<longest_consecutive_sequence::Solution> solution_(new longest_consecutive_sequence::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running longest_consecutive_sequence_test case1..." <<std::endl;

		vector<int> numbers = boost::assign::list_of(100)(4)(200)(1)(3)(2);
		BOOST_ASSERT( 4==solution_->longestConsecutive(numbers) );
	}

BOOST_AUTO_TEST_SUITE_END()	