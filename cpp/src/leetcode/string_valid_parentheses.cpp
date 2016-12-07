#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/valid-parentheses/
 */

namespace valid_parentheses
{
	class Solution 
	{
	public:
		bool isValid(string s) 
		{
			std::stack<char> container;

			for (int i=0; i<s.length(); i++)
			{
				char cur = s[i];
				if (cur == '(' || cur == '[' || cur == '{')
					container.push(s[i]);
				else if (cur == ')')
				{
					if ( !container.empty() && '(' == container.top() )
						container.pop();
					else
						return false;
				}
				else if (cur == ']')
				{
					if ( !container.empty() && '[' == container.top() )
						container.pop();
					else
						return false;
				}
				else if (cur == '}')
				{
					if ( !container.empty() && '{' == container.top() )
						container.pop();
					else
						return false;
				}

			}

			if (container.empty())
				return true;
			else 
				return false;
		}
	};
};


BOOST_AUTO_TEST_SUITE( valid_parentheses_test )
	boost::shared_ptr<valid_parentheses::Solution> solution_(new valid_parentheses::Solution());
	
	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running valid_parentheses_test case1..." <<std::endl;
		BOOST_ASSERT( true == solution_->isValid("()[]{}") );
		BOOST_ASSERT( false == solution_->isValid("(]") );
		BOOST_ASSERT( false == solution_->isValid("([)]") );
		BOOST_ASSERT( true == solution_->isValid("()") );
		BOOST_ASSERT( false == solution_->isValid("]") );
	}

BOOST_AUTO_TEST_SUITE_END()	