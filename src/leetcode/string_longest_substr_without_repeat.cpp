#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
*/

namespace longest_substr_without_repeat
{
	class Solution1    // not passed because of "Memory Limit Exceeded"
	{
	public:
		int lengthOfLongestSubstring(string s) 
		{
			if (s.size() <= 1)
				return s.size();

			int tmp = lengthOfLongestSubstring(s.substr(1));
			for ( int i=0; i<tmp+1; i++)
			{					
				for (int j=i+1; j<tmp+1; j++)
				{
					if ( s.at(i) == s.at(j) )
						return tmp;
				}
			}
				
			return tmp + 1;
		}
	};

	class Solution 
	{
	public:
		int lengthOfLongestSubstring(string s) 
		{
			if (s.size() <= 1)
				return s.size();

			int lastAppeared[256];
			for (int i=0; i<256; i++)
				lastAppeared[i] = -1;

			int longest = 0;
			int current_longest = 0;

			for ( int i=0; i<s.size(); i++)
			{				
				if( lastAppeared[s[i]] >= 0 )
				{
					//	repeated
					longest = ( current_longest > longest ? current_longest : longest);
					current_longest = 0;
					i = lastAppeared[s[i]]+1;
					for (int j=0; j<256; j++)
						lastAppeared[j] = -1;
				}

				lastAppeared[s[i]] = i;  
				current_longest++;
			}

			return current_longest > longest ? current_longest : longest;
		}
	};
}


BOOST_AUTO_TEST_SUITE( longest_substr_without_repeat_test )

	boost::shared_ptr<longest_substr_without_repeat::Solution> solution_(new longest_substr_without_repeat::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running longest_substr_without_repeat_test case1..." <<std::endl;

		std::string s = "abcabcbb";
		BOOST_ASSERT(solution_->lengthOfLongestSubstring(s) == 3);
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running longest_substr_without_repeat_test case2..." <<std::endl;

		std::string s = "bbbbbbbbb";
		BOOST_ASSERT(solution_->lengthOfLongestSubstring(s) == 1);
	}

BOOST_AUTO_TEST_SUITE_END()	