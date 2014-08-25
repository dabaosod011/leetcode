#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/two-sum/
*/

namespace two_sum
{
	class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) 
		{
			vector<int> result;
			map<int, int>  hash_numbers; // key: number, value: vector indx
			for (auto first = numbers.begin(); first != numbers.end(); first++)
			{
				hash_numbers.insert(std::make_pair(*first, first - numbers.begin() + 1));
			}

			int expect_second;
			for (auto it = numbers.begin(); it != numbers.end(); it++)
			{
				expect_second = target - *it ;
				map<int, int>::iterator pos = hash_numbers.find(expect_second);
				if ( pos != hash_numbers.end() )
				{
					for (auto it2 = it+1; it2 != numbers.end(); it2++)
					{
						if ( *it + *it2 == target )
						{
							result.push_back( it - numbers.begin() + 1 );
							result.push_back( it2 - numbers.begin() + 1  );
							return result;
						}				
					}
				}
			}
		}
	};

};

BOOST_AUTO_TEST_SUITE( two_sum_test )

	boost::shared_ptr<two_sum::Solution> solution_(new two_sum::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running two_sum case1..." <<std::endl;

		vector<int> numbers = boost::assign::list_of(0)(4)(3)(0);
		int target = 0;

		vector<int> result = solution_->twoSum(numbers,target);
		BOOST_ASSERT( result.at(0) == 1 && result.at(1) == 4);
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running two_sum case2..." <<std::endl;

		vector<int> numbers = boost::assign::list_of(-3)(4)(3)(0);
		int target = 0;

		vector<int> result = solution_->twoSum(numbers,target);
		BOOST_ASSERT( result.at(0) == 1 && result.at(1) == 3);
	}

BOOST_AUTO_TEST_SUITE_END()	