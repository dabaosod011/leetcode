#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/reverse-integer/
 */

namespace multiply_strings
{
	class Solution 
	{
	public:
		string multiply(string num1, string num2) 
		{
			if(num1.size() ==0 || num2.size() ==0) 
				return 0;  

			int n1 = num1.size(), n2 = num2.size();
			int maxLen = n1-1 + n2-1;
			vector<int> tmp(n1+n2, 0);
			for(int i = 0; i < n1; i++)
				for(int j = 0; j < n2; j++)
					tmp[maxLen-i-j] += (num1[i]-'0')*(num2[j]-'0');
			
			int carry = 0;
			for(int i=0; i <n1+n2; i++)
			{
				tmp[i] += carry;
				carry = tmp[i] / 10;
				tmp[i] %= 10;
			}
			
			while(tmp.back() == 0)
				tmp.pop_back();
			
			stringstream ss;
			for (auto it = tmp.rbegin(); it != tmp.rend(); it++)
				ss << *it;

			if (ss.str() == "")
				return "0";
			else
				return ss.str();
		}
	};
};

BOOST_AUTO_TEST_SUITE( multiply_strings_test )
	boost::shared_ptr<multiply_strings::Solution> solution_(new multiply_strings::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running multiply_strings_test case1..." <<std::endl;
		std::string num1 = "123";
		std::string num2 = "4567";
		std::cout <<  solution_->multiply(num1,num2) <<std::endl;
	}

BOOST_AUTO_TEST_SUITE_END()		