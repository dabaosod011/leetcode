#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/longest-common-prefix/
*/

namespace longest_common_prefix
{
	class Solution 
	{
	public:
		string longestCommonPrefix(vector<string> &strs) 
		{
			if(strs.size() == 0)
				return "";
			if(strs.size() == 1)
				return strs[0];

			string result = strs[0];
			for (int i=1; i<strs.size(); i++)
				result = commonPrefix(result, strs[i]);
			
			return result;
		}

		string commonPrefix(string s1, string s2)
		{
			string result="";

			if (s1.size()==0 || s2.size()==0)
				return result;

			int i=0;
			while (i<s1.size() && i<s2.size())
			{
				if (s1[i] == s2[i])
				{
					result = result + s1[i];
					i++;
				}
				else
					break;
			}
			return result;
		}
	};
};

BOOST_AUTO_TEST_SUITE( longest_common_prefix_test )

	boost::shared_ptr<longest_common_prefix::Solution> solution_(new longest_common_prefix::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running longest_common_prefix_test case1..." <<std::endl;
		
		std::vector<string> strs = boost::assign::list_of("abcd")("abce")("abcf");
		BOOST_ASSERT("abc" == solution_->longestCommonPrefix(strs));
	}

BOOST_AUTO_TEST_SUITE_END()	