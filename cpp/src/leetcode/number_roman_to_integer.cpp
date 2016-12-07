#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/roman-to-integer/
 */

namespace roman_to_integer
{
	class Solution 
	{
	public:
		int romanToInt(string s) 
		{
			std::map<char, int> dct;
			dct['I'] = 1;
			dct['i'] = 1;
			dct['V'] = 5;
			dct['v'] = 5;
			dct['X'] = 10;
			dct['x'] = 10;
			dct['L'] = 50;
			dct['l'] = 50;
			dct['C'] = 100;
			dct['c'] = 100;
			dct['D'] = 500;
			dct['d'] = 500;
			dct['M'] = 1000;
			dct['m'] = 1000;

			int sum = 0, j;
			for(int i = 0; i < s.size(); ++i)
			{
				j = i+1;

				if(j < s.size() && dct[s[j]] > dct[s[i]])
				{
					sum += dct[s[j]] - dct[s[i]];
					i = j;
				}
				else
					sum += dct[s[i]];
			}
			return sum;
		}
	};
}

BOOST_AUTO_TEST_SUITE( roman_to_integer_test )

	boost::shared_ptr<roman_to_integer::Solution> solution_(new roman_to_integer::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running roman_to_integer_test case1..." <<std::endl;
		BOOST_ASSERT( 1 == solution_->romanToInt("I") );
		BOOST_ASSERT( 2 == solution_->romanToInt("II") );
		BOOST_ASSERT( 1000 == solution_->romanToInt("M") );
	}

BOOST_AUTO_TEST_SUITE_END()	