#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/single-number-ii/
 */

namespace single_number2
{
	class Solution 
	{
	public:
		int singleNumber(int A[], int n) 
		{
			//	http://www.cppblog.com/Uriel/articles/205406.html
			int tp3, tp1 = 0, tp2 = 0;
			for(int i = 0; i < n; ++i) 
			{
				tp2 |= tp1 & A[i];
				tp1 ^= A[i];
				tp3 = ~(tp1 & tp2);
				tp1 &= tp3;
				tp2 &= tp3;
			}

			return tp1;
		}
	};
}

BOOST_AUTO_TEST_SUITE( single_number2_test )

	boost::shared_ptr<single_number2::Solution> solution_(new single_number2::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running single_number2_test case1..." <<std::endl;
		int a[] = {1,2,3,4,5,6,5,4,3,2,1,1,2,3,4,5};

		BOOST_ASSERT( 6 == solution_->singleNumber(a,16) );
	}

BOOST_AUTO_TEST_SUITE_END()	