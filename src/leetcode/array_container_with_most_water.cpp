#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/container-with-most-water/
 */

namespace container_with_most_water
{
	class Solution 
	{
	public:
		int maxArea(vector<int> &height) 
		{
			int result = 0, tmpSquare = 0;
			if (height.size() < 2)
				return result;

			int left=0, right=height.size()-1;
			while (left < right)
			{
				tmpSquare =  std::abs(std::min(height[left], height[right])*(right-left));
				result = std::max(result, tmpSquare);
       
				if (height[left] < height[right])
					++left;
				else
					--right;
			}

			/*for (auto i=height.begin(); i<height.end(); i++)
			{
				for(auto j=i+1; j<height.end(); j++)
				{
					tmpSquare = std::abs((j-i)*(std::min(*i,*j)));
					result = std::max(result, tmpSquare);
				}
			}*/

			return result;
		}
	};
}

BOOST_AUTO_TEST_SUITE( container_with_most_water_test )
	boost::shared_ptr<container_with_most_water::Solution> solution_(new container_with_most_water::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running container_with_most_water_test case1..." <<std::endl;
		vector<int> container = boost::assign::list_of(1)(1);
		BOOST_ASSERT(1==solution_->maxArea(container));
	}

BOOST_AUTO_TEST_SUITE_END()	