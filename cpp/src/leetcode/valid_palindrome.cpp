#include "lc_header.h"

/*
*	https://oj.leetcode.com/problems/valid-palindrome/
*/

namespace valid_palindrome
{
	class Solution 
	{
		public:
		bool isPalindrome(string s) 
		{
			std::transform(s.begin(), s.end(), s.begin(), ::tolower);
			int i=0, j =s.length()-1;
			while(i < j)
			{
				if (!(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= '0' && s[i] <= '9'))
				{
					i++;
				}
				else if (!(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= '0' && s[j] <= '9'))
				{
					j--;
				}
				else
				{
					if (s[i] != s[j])
						return false;
					i++;
					j--;
				}
			}

			return true;
		}
	};
}


BOOST_AUTO_TEST_SUITE( valid_palindrome_test )

	boost::shared_ptr<valid_palindrome::Solution> solution_(new valid_palindrome::Solution());
	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running valid_palindrome_test case1..." <<std::endl;
		BOOST_ASSERT(true == solution_->isPalindrome("A man, a plan, a canal: Panama"));
		BOOST_ASSERT(false == solution_->isPalindrome("race a car"));
		BOOST_ASSERT(false == solution_->isPalindrome("1a2"));
	}

BOOST_AUTO_TEST_SUITE_END()	