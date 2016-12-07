#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/reverse-integer/
 */

namespace reverse_integer
{
	class Solution 
	{
	public:
		int reverse(int x) 
		{
			int result = 0;
			bool isNegative = false;
			if (x < 0)
			{
				isNegative = true;
				x = abs(x);
			}

			std::deque<int> container;
			int last = x % 10;
			int remain = x / 10;			
			container.push_back(last);

			while (remain != 0)
			{				
				last = remain % 10;
				remain = remain / 10;
				container.push_back(last);
			}

			int tmp;
			while( !container.empty() )
			{
				tmp = container.front();
				container.pop_front();
				result = 10*result + tmp;
			}

			return (isNegative ? 0-result : result);
		}
	};
};

BOOST_AUTO_TEST_SUITE( reverse_integer_test )
	boost::shared_ptr<reverse_integer::Solution> solution_(new reverse_integer::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running reverse_integer_test case1..." <<std::endl;

		BOOST_ASSERT( solution_->reverse(321) == 123 );
		BOOST_ASSERT( solution_->reverse(-12345) == -54321 );
	}

BOOST_AUTO_TEST_SUITE_END()		