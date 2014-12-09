#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/regular-expression-matching/
 */

namespace regular_expression_matching
{
	class Solution 
	{
	public:
		bool isMatch(const char *s, const char *p) 
		{
			if ( s == NULL  || p == NULL)
				return false;

			if (*p == '\0') 
				return *s == '\0';
 
			//	next char is NOT '*'
			if ( *(p+1) != '*' ) 
			{
				if ( *p == '*' )
					return false;

				if ((*p == *s) || (*p == '.' && *s != '\0'))
					return isMatch(s+1, p+1);

				return false;
			}
		  
			// next char is '*'
			while ((*p == *s) || (*p == '.' && *s != '\0')) 
			{
				if (isMatch(s, p+2)) 
					return true;
				s++;
			}
			return isMatch(s, p+2);
		}
	};
}

BOOST_AUTO_TEST_SUITE( regular_expression_matching_test )

	boost::shared_ptr<regular_expression_matching::Solution> solution_(new regular_expression_matching::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running palindrome_number_test case1..." <<std::endl;

		BOOST_ASSERT( false == solution_->isMatch("aa","a") );
		BOOST_ASSERT( true == solution_->isMatch("aa","aa") );
		BOOST_ASSERT( false == solution_->isMatch("aaa","aa") );
		BOOST_ASSERT( true == solution_->isMatch("aa","a*") );
		BOOST_ASSERT( true == solution_->isMatch("aa",".*") );
		BOOST_ASSERT( true == solution_->isMatch("ab",".*") );
		BOOST_ASSERT( true == solution_->isMatch("aab","c*a*b*") );
		BOOST_ASSERT( false == solution_->isMatch("ab",".*c") );
	}

BOOST_AUTO_TEST_SUITE_END()	