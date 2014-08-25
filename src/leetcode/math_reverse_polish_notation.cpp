#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/evaluate-reverse-polish-notation/
 */

namespace reverse_polish_notation
{
	class Solution {
	public:
		int evalRPN(vector<string> &tokens) 
		{
			int result;
			std::stack<std::string> con;
			string value_1, value_2, tmp_value;
			int i_value_1,i_value_2, i_tmp_value;

			for (auto it = tokens.begin(); it != tokens.end(); ++it)
			{
				if (*it == "+")
				{
					value_1 = con.top(); con.pop();
					value_2 = con.top(); con.pop();

					i_value_1 = atoi(value_1.c_str());
					i_value_2 = atoi(value_2.c_str());

					i_tmp_value = i_value_2 + i_value_1;
					tmp_value = ConvertToString(i_tmp_value);
					con.push(tmp_value);				
				}
				else if (*it == "-")
				{
					value_1 = con.top(); con.pop();
					value_2 = con.top(); con.pop();

					i_value_1 = atoi(value_1.c_str());
					i_value_2 = atoi(value_2.c_str());

					i_tmp_value = i_value_2 - i_value_1;
					tmp_value = ConvertToString(i_tmp_value);
					con.push(tmp_value);		
				}
				else if (*it == "*")
				{
					value_1 = con.top(); con.pop();
					value_2 = con.top(); con.pop();

					i_value_1 = atoi(value_1.c_str());
					i_value_2 = atoi(value_2.c_str());

					i_tmp_value = i_value_2 * i_value_1;
					tmp_value = ConvertToString(i_tmp_value);
					con.push(tmp_value);		
				}
				else if (*it == "/")
				{
					value_1 = con.top(); con.pop();
					value_2 = con.top(); con.pop();

					i_value_1 = atoi(value_1.c_str());
					i_value_2 = atoi(value_2.c_str());

					i_tmp_value = i_value_2 / i_value_1;
					tmp_value = ConvertToString(i_tmp_value);
					con.push(tmp_value);		
				}
				else
				{
					con.push(*it);
				}
			}

			if (!con.empty())
			{
				result = atoi( con.top().c_str() );
			}

			return result;
		}

		template <class T> std::string ConvertToString(T value) 
		{
			std::stringstream ss;
			ss << value;
			return ss.str();
		}
	};
};

BOOST_AUTO_TEST_SUITE( reverse_polish_notation )
	boost::shared_ptr<reverse_polish_notation::Solution> solution_(new reverse_polish_notation::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running reverse_polish_notation case1..." <<std::endl;

		std::vector<string> expression = boost::assign::list_of("0")("3")("/");
		BOOST_ASSERT( solution_->evalRPN(expression) == 0 );
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running reverse_polish_notation case2..." <<std::endl;

		std::vector<string> expression = boost::assign::list_of("2")("1")("+")("3")("*");
		BOOST_ASSERT( solution_->evalRPN(expression) == 9 );
	}

	BOOST_AUTO_TEST_CASE( case3 ) 	
	{
		std::cout << "running reverse_polish_notation case3..." <<std::endl;

		std::vector<string> expression = boost::assign::list_of("4")("13")("5")("*")("+");
		BOOST_ASSERT( solution_->evalRPN(expression) == 69 );
	}

BOOST_AUTO_TEST_SUITE_END()		