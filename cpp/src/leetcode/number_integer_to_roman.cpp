#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/integer-to-roman/
 */

namespace integer_to_roman
{
	class Solution 
	{
	public:
		string intToRoman(int num) 
		{
			vector<std::pair<int, string> > dct;
			dct.push_back(std::make_pair(1000, "M"));
			dct.push_back(std::make_pair(900,  "CM"));
			dct.push_back(std::make_pair(500,  "D"));
			dct.push_back(std::make_pair(400,  "CD"));
			dct.push_back(std::make_pair(100,  "C"));
			dct.push_back(std::make_pair(90,   "XC"));
			dct.push_back(std::make_pair(50,   "L"));
			dct.push_back(std::make_pair(40,   "XL"));
			dct.push_back(std::make_pair(10,   "X"));
			dct.push_back(std::make_pair(9,	   "IX"));
			dct.push_back(std::make_pair(5,	   "V"));
			dct.push_back(std::make_pair(4,	   "IV"));
			dct.push_back(std::make_pair(1,    "I"));

			string res;
			int i = 0;
			while(num > 0)
			{
				if(num/dct[i].first == 0)
				{
					i += 1;
					continue;
				}
      
				for(int j = 0; j < num/dct[i].first; ++j)
					res.append(dct[i].second);
        
				num%=dct[i].first;
			}
			return res;
		}
	};
}

BOOST_AUTO_TEST_SUITE( integer_to_roman_test )

	boost::shared_ptr<integer_to_roman::Solution> solution_(new integer_to_roman::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running integer_to_roman_test case1..." <<std::endl;
		BOOST_ASSERT( "I" == solution_->intToRoman(1) );
		BOOST_ASSERT( "II" == solution_->intToRoman(2) );
		BOOST_ASSERT( "M" == solution_->intToRoman(1000) );
	}

BOOST_AUTO_TEST_SUITE_END()	