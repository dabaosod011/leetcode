#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/3sum-closest/
 */

namespace three_sum_closest
{
	class Solution 
	{
	public:
		int threeSumClosest(vector<int> &num, int target) 
		{
			int result=0, sum;
			int gap = std::numeric_limits<int>::max();

			std::sort(num.begin(), num.end());
			for (int first = 0; first < num.size()-2; first++)
			{
				int second = first + 1;
				int third = num.size() - 1;
				while(second < third)
				{
					sum = num[first] + num[second] + num[third];
					if (sum == target)
						return target;

					if( std::abs(sum - target) < gap)
					{
						result = sum;
						gap = std::abs(sum - target);
					}
					
					if(sum <= target)
					{
						second++;
						while (second < third && num[second] == num[second-1])
							second++;
					}
					else
					{
						third--;
						while (second < third && num[third] == num[third+1])
							third--; 
					}
				}
			}

			return result;
		}
	};
}

BOOST_AUTO_TEST_SUITE( three_sum_closest_test )
	boost::shared_ptr<three_sum_closest::Solution> solution_(new three_sum_closest::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running three_sum_closest case1..." <<std::endl;

		vector<int> nums = boost::assign::list_of(-1)(2)(1)(4);		
		BOOST_ASSERT( 2 == solution_->threeSumClosest(nums, 1) );

		nums.clear();
		nums = boost::assign::list_of(0)(1)(2);
		BOOST_ASSERT( 3 == solution_->threeSumClosest(nums, 3) );
	}

BOOST_AUTO_TEST_SUITE_END()	