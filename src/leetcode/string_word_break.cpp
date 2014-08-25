#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/word-break/
*/

namespace word_break
{
	class Solution 
	{
	public:
		bool wordBreak(string s, unordered_set<string> &dict) 
		{
			if ( s.size() == 0 || dict.size() == 0)
				return false;
			if ( dict.find(s) != dict.end() )
				return true;
			
			std::vector<bool> isSegmented(s.size()+1, false);
			isSegmented[0] = true;
			std::string tmp;
			for (auto it = 0; it < s.size(); it++)
			{
				if( isSegmented[it] == true )
				{
					for (auto len = 1; len < s.size()+1-it; len++)
					{
						tmp = s.substr(it, len);
						if (dict.find(tmp) != dict.end())
							isSegmented[it+len] = true;
					}
				}
			}
			return isSegmented[s.length()];
		}
	};
}

BOOST_AUTO_TEST_SUITE( word_break_test )

	boost::shared_ptr<word_break::Solution> solution_(new word_break::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running word_break_test case1..." <<std::endl;
		std::string s = "leetcode";
		std::unordered_set<std::string> dict;
		dict.insert("leet");
		dict.insert("code");

		BOOST_ASSERT( true == solution_->wordBreak(s, dict) );
	}

	BOOST_AUTO_TEST_CASE( case12) 	
	{
		std::cout << "running word_break_test case2..." <<std::endl;
		std::string s = "leetcode";
		std::unordered_set<std::string> dict;
		dict.insert("leets");
		dict.insert("code");

		BOOST_ASSERT( false == solution_->wordBreak(s, dict) );
	}

BOOST_AUTO_TEST_SUITE_END()	