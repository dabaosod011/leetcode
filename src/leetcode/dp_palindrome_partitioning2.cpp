#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/palindrome-partitioning-ii//
*/

namespace palindrome_partitioning2
{
	class Solution 
	{
	public:
		/*	Time Limit Exceeded
		int minCut(string s) 
		{
			if (isPalindrome(s))
				return 0;

			int min = s.length()-1;
			for (int i=1; i<s.size(); i++)
			{
				if( isPalindrome(s.substr(0,i)) )
				{
					int numCut1 = 1 + minCut(s.substr(i));
					if(numCut1 < min)
						min = numCut1;
				}
			}

			return min;
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
		}*/

		int minCut(string s) 
		{
			vector<int> result(s.size(),0);
			vector<bool> temp(s.size(), false);
			vector<vector<bool> > isPal(s.size(),temp);
         
			for (int i=s.size()-1;i>=0;i--)
			{
				for (int j=i;j<s.size();j++)
				{
					if ((s[i]==s[j]) && (j-i<2 || isPal[i+1][j-1]))
						isPal[i][j]=true;
				}
			}             

			/*
			*	f(i) = minimum of following:
			*	{
			*		 0,   if str[0,i] is palindrome;
			*		 f(j)+1,  j=0..i-1   and str[j:i] is palindrome
			*	}
			*/
			for (int i=0;i<s.size();i++)
			{ 
				if (isPal[0][i])
					result[i]=0;
				else
				{
					result[i] = i;
					for (int j=0;j<i;j++)
					{
						if (isPal[j+1][i]) 
							result[i] = std::min(result[i],result[j]+1);
					}
				}
			}

			return result[s.size()-1];
		}	
	};
};

BOOST_AUTO_TEST_SUITE( palindrome_partitioning2_test )

	boost::shared_ptr<palindrome_partitioning2::Solution> solution_(new palindrome_partitioning2::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running palindrome_partitioning2_test case1..." <<std::endl;

		string s = "aaaba";
		std::cout<< solution_->minCut(s) <<std::endl;
		//BOOST_ASSERT(solution_->minCut(s) == 1);
	}

BOOST_AUTO_TEST_SUITE_END()	