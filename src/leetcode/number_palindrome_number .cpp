#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/palindrome-number/
 */

namespace palindrome_number
{
	class Solution 
	{
	public:
		bool isPalindrome(int x) 
		{
			if (x < 0)
				return false;

			//	get pow(10, length)
			int len10 = 1;
			while( x/len10 >=10 )  
				len10 = len10 * 10;

			while (x > 0)
			{
				int high = x / len10;  
				int low = x % 10; 
				if (high != low)
					return false;

				x= x % len10;
				x = x / 10;
				len10 = len10 / 100;
			}

			return true;
		}
	};
}

BOOST_AUTO_TEST_SUITE( palindrome_number_test )

	boost::shared_ptr<palindrome_number::Solution> solution_(new palindrome_number::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running palindrome_number_test case1..." <<std::endl;
		BOOST_ASSERT( true == solution_->isPalindrome(12321) );
		BOOST_ASSERT( false == solution_->isPalindrome(12332) );
	}

BOOST_AUTO_TEST_SUITE_END()	