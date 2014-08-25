#include "lc_header.h"

/**
 *	 https://oj.leetcode.com/problems/single-number/
 */

namespace single_number
{
	class Solution 
	{
	public:
		int singleNumber(int A[], int n) 
		{
			int result = 0;
			for(int i = 0; i < n; i++)
				result ^= A[i];

			return result;
		}
	};
}

BOOST_AUTO_TEST_SUITE( single_number_test )

	boost::shared_ptr<single_number::Solution> solution_(new single_number::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running single_number_test case1..." <<std::endl;
		int a[] = {1,2,3,4,5,6,5,4,3,2,1};

		BOOST_ASSERT( 6 == solution_->singleNumber(a,11) );
	}

BOOST_AUTO_TEST_SUITE_END()	