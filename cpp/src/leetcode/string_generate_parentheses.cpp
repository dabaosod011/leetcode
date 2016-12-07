#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/generate-parentheses/
*/

namespace generate_parentheses
{
	class Solution 
	{
	public:
		vector<string> generateParenthesis(int n) 
		{
			vector<string> result;
			
			if (n == 0)
				return result;

			if (n == 1)
			{
				result.push_back("()");
				return result;
			}

			vector<string> result_n1 = generateParenthesis(n-1);
			std::set<string> tmpResult;
			for (auto it=result_n1.begin(); it!=result_n1.end(); it++)
			{
				for (int i=0; i<it->length(); i++)
				{
					tmpResult.insert( it->substr(0, i) + "()" + it->substr(i) );
				}
			}

			std::copy(tmpResult.begin(), tmpResult.end(),  std::back_inserter(result)); 
			return result;
		}
	};
};

BOOST_AUTO_TEST_SUITE( generate_parentheses_test )

	boost::shared_ptr<generate_parentheses::Solution> solution_(new generate_parentheses::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running generate_parentheses_test case1..." <<std::endl;
		vector<string> result = solution_->generateParenthesis(3);
		for(auto it=result.begin(); it!=result.end(); it++)
			std::cout << *it << "\t" ;
		std::cout <<std::endl;
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running generate_parentheses_test case2..." <<std::endl;
		vector<string> result = solution_->generateParenthesis(5);
		for(auto it=result.begin(); it!=result.end(); it++)
			std::cout << *it << "\t" ;
		std::cout <<std::endl;
	}

BOOST_AUTO_TEST_SUITE_END()	