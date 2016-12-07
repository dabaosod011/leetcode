#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
*/

namespace letter_combinations_of_a_phone_number
{
	class Solution 
	{
		public:
		vector<string> letterCombinations(string digits) 
		{
			vector<string> keyboard;
			keyboard.push_back("");		//	0
			keyboard.push_back(" ");	//	1
			keyboard.push_back("abc");	//	2
			keyboard.push_back("def");	//	3
			keyboard.push_back("ghi");	//	4
			keyboard.push_back("jkl");	//	5
			keyboard.push_back("mno");	//	6
			keyboard.push_back("pqrs");	//	7
			keyboard.push_back("tuv");	//	8
			keyboard.push_back("wxyz");	//	9

			vector<string> result;      
			string candidate;  
			helper(digits, keyboard, result, 0, candidate);  
			return result;  
		}

		void helper(string& digits, vector<string>& keyboard, vector<string>& result, int curIdx, string& candidate)  
		{  
			if(curIdx == digits.size())  
			{  
				result.push_back(candidate);  
				return;  
			}  
			
			int num = digits[curIdx] - 48;  
			for(int i=0; i < keyboard[num].size(); i++)  
			{  
				candidate.push_back(keyboard[num][i]);  
				helper(digits, keyboard, result, curIdx+1, candidate);  
				candidate.resize(candidate.size() -1);  
			}  
		} 
	};

};

BOOST_AUTO_TEST_SUITE( letter_combinations_of_a_phone_number_test )

	boost::shared_ptr<letter_combinations_of_a_phone_number::Solution> solution_(new letter_combinations_of_a_phone_number::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running letter_combinations_of_a_phone_number case1..." <<std::endl;
		vector<string> result =  solution_->letterCombinations("234");
		for (auto it = result.begin(); it != result.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}

BOOST_AUTO_TEST_SUITE_END()	