#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/3sum/
 */

namespace three_sum
{
	class Solution 
	{
	public:
		vector<vector<int> > threeSum(vector<int> &num) 
		{
			vector<vector<int> > result;

			if (num.size() < 3)
				return result;

			std::sort(num.begin(), num.end());
			for (int first = 0; first < num.size()-2; first++)
			{
				if (first == 0 || num[first] > num[first - 1]) 
				{
					int sum_remain = 0-num[first];
					int second = first + 1;
					int third = num.size() - 1;

					while(second < third)
					{
						if (num[second] + num[third] == sum_remain)
						{
							vector<int> tmp;
							tmp.push_back(num[first]);
							tmp.push_back(num[second]);
							tmp.push_back(num[third]);
							//if(std::find(result.begin(), result.end(), tmp) == result.end())
							result.push_back(tmp);

							second++;
							third--;

							while (second < third && num[third] == num[third+1])
								third--; 
							while (second < third && num[second] == num[second-1])
								second++;
						}
						else if (num[second] + num[third] < sum_remain)
						{
							second++;
						}	
						else if (num[second] + num[third] > sum_remain)
						{
							third--;
						}
					} 
				}
			}

			return result;
		}
	};
}

BOOST_AUTO_TEST_SUITE( three_sum_test )
	boost::shared_ptr<three_sum::Solution> solution_(new three_sum::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running 3sum case1..." <<std::endl;

		vector<int> nums = boost::assign::list_of(-1)(0)(1)(2)(-1)(-4);		
		vector<vector<int> > result = solution_->threeSum(nums);

		for(auto row=result.begin(); row<result.end(); row++)
		{
			for (auto col=row->begin(); col<row->end(); col++)
				std::cout << *col << " ";
			std::cout << std::endl;
		}
	}

BOOST_AUTO_TEST_SUITE_END()	