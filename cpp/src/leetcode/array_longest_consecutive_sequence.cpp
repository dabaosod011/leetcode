#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/longest-consecutive-sequence/
*/

namespace longest_consecutive_sequence
{
	class Solution 
	{
	public:
		int longestConsecutive(vector<int> &num) 
		{
			int result = 0;
			int max=1;    
			std:: unordered_map<int,bool> mapping;
			for (auto it=num.begin(); it!=num.end(); it++)
				mapping[*it]=true;

			for (auto it=num.begin(); it!=num.end(); it++)
			{
				max=1;  
				int current = *it;
             
				mapping.erase(current);
				while (mapping.count(current+1) > 0)
				{
					max++;
					mapping.erase(current+1);
					current++;
				}
             
				current = *it;
				while (mapping.count(current-1) > 0)
				{
					max++;
					mapping.erase(current-1);
					current--;
				}
             
				result = std::max(result,max);
			}

			return result;
		}
	};
};

BOOST_AUTO_TEST_SUITE( longest_consecutive_sequence_test )

	boost::shared_ptr<longest_consecutive_sequence::Solution> solution_(new longest_consecutive_sequence::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running longest_consecutive_sequence_test case1..." <<std::endl;

		vector<int> numbers = boost::assign::list_of(100)(4)(200)(1)(3)(2);
		BOOST_ASSERT( 4==solution_->longestConsecutive(numbers) );
	}

BOOST_AUTO_TEST_SUITE_END()	