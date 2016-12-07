#include "lc_header.h"

/**
 *	 https://oj.leetcode.com/problems/candy/
 */

namespace candy
{
	class Solution 
	{
	public:
		int candy(vector<int> &ratings)
		{
			vector<int> candies(ratings.size(), 1);
		
			for (int i=1; i<ratings.size(); i++)
			{
				if( ratings[i] > ratings[i-1] )
					candies[i] = candies[i-1] + 1;
			}
			
			for(int i = ratings.size()-2; i>=0; i--)
			{
				if(ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
					candies[i] = candies[i+1] + 1;
			}

			return std::accumulate(candies.begin(), candies.end(), 0);
		}
	};
}

BOOST_AUTO_TEST_SUITE( candy_test )

	boost::shared_ptr<candy::Solution> solution_(new candy::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running candy_test case1..." <<std::endl;
		std::vector<int> ratings = boost::assign::list_of(7)(5)(1)(4)(2)(1)(8)(6);

		BOOST_ASSERT( 15 == solution_->candy(ratings) );
	}

BOOST_AUTO_TEST_SUITE_END()	