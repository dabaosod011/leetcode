#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/string-to-integer-atoi/
 */

namespace string2integer
{
	class Solution 
	{
	public:
		int atoi(const char *str) 
		{
			if(str == NULL)
				return 0;

			bool isNegative = false;
			while (*str == ' ')
				str++;

			if(*str == '-')
			{
				isNegative = true;
				str++;
			}
			else if(*str == '+')
			{
				str++;
			}

			int result = 0;
			int cur;
			while (*str != '\0')
			{
				cur = (*str - '0');
				if (cur >=0 && cur <= 9)
				{
					if( INT_MAX/10 < result || (INT_MAX/10 == result && INT_MAX%10 < cur)) 
					{
						return isNegative ? INT_MIN  : INT_MAX;
					}
					else
					{
						result = result*10 + cur;
						str++;
					}
				}
				else 
					break;		
			}

			return isNegative ? 0-result : result;
		}
	};
}

BOOST_AUTO_TEST_SUITE( string2integer_test )

	boost::shared_ptr<string2integer::Solution> solution_(new string2integer::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running string2integer_test case1..." <<std::endl;

		BOOST_ASSERT( 123 == solution_->atoi("123") );
		BOOST_ASSERT( 123 == solution_->atoi("+123") );
		BOOST_ASSERT( -123 == solution_->atoi("-123") );
		BOOST_ASSERT( -12 == solution_->atoi("-0012a42") );
		BOOST_ASSERT( INT_MAX == solution_->atoi("2147483648") );
		BOOST_ASSERT( INT_MIN == solution_->atoi("-2147483648") );
	}

BOOST_AUTO_TEST_SUITE_END()	