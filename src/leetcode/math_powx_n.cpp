#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/powx-n/
 */

namespace powx_n
{
	class Solution 
	{
	public:
		double pow(double x, int n) 
		{
			if (n < 0)
				return 1 / helper(x, 0-n);
			else 
				return helper(x, n);
		}

		double helper(double x, int n) 
		{
			if (n == 0)
				return 1.0;
			if (n == 1)
				return x;

			if (n % 2 == 0) {
				double tmp = helper(x, n / 2);
				return tmp*tmp;
			} else {
				double tmp = helper(x, n / 2);
				return x*tmp*tmp;
			}
		}
	};
};

BOOST_AUTO_TEST_SUITE( powx_n_test )
	boost::shared_ptr<powx_n::Solution> solution_(new powx_n::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running powx_n_test case1..." <<std::endl;
		
		BOOST_ASSERT( 4.0 == pow(2,2) );
		BOOST_ASSERT( 8.0 == pow(2,3) );
	}

BOOST_AUTO_TEST_SUITE_END()		