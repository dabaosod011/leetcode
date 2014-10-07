#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/palindrome-partitioning/
*/

namespace palindrome_partitioning
{
	class Solution 
	{
	public:
		vector<vector<string>> partition(string s) 
		{
			vector<vector<string>> result;
			if (s.length() == 0)
				return result;

			vector<string> candidate;
			palindrome_candidate(s, 0, candidate, result);
			return result;
		}

		void palindrome_candidate(string s, int begin, vector<string> &candidate,vector<vector<string>> &result)
		{
			if(begin == s.length())
			{
				result.push_back(candidate);
				return;
			}
			else
			{
				for (int idx = begin; idx < s.length(); idx++)
				{
					if( isPalindrome(s.substr(begin, idx-begin+1)))
					{
						candidate.push_back(s.substr(begin, idx-begin+1));
						palindrome_candidate(s, idx+1, candidate, result);
						candidate.pop_back();
					}
				}
			}			
		}

		bool isPalindrome(string s)
		{
			int i=0, j =s.length()-1;
			while(i < j)
			{
				if (s[i] != s[j])
					return false;
				i++;
				j--;
			}

			return true;
		}
	};
};

BOOST_AUTO_TEST_SUITE( palindrome_partitioning_test )

	boost::shared_ptr<palindrome_partitioning::Solution> solution_(new palindrome_partitioning::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running palindrome_partitioning_test case1..." <<std::endl;

		string s = "aab";		
		vector<vector<string>> result = solution_->partition(s);
		for (auto it = result.begin(); it != result.end(); it++)
		{
			for (auto it2 = it->begin(); it2 != it->end(); it2++)
				std::cout << *it2 << " ";
			std::cout <<std::endl;
		}
	}

BOOST_AUTO_TEST_SUITE_END()	