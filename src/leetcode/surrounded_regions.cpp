#include "lc_header.h"

/*
*	https://oj.leetcode.com/problems/surrounded-regions/
*/

namespace surrounded_regions
{
	class Solution 
	{
	public:
		void solve(vector<vector<char>> &board) 
		{
			if(board.size() <= 2)
				return;
		}

	};
}


BOOST_AUTO_TEST_SUITE( surrounded_regions_test )

	boost::shared_ptr<surrounded_regions::Solution> solution_(new surrounded_regions::Solution());
	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running surrounded_regions_test case1..." <<std::endl;
	}

BOOST_AUTO_TEST_SUITE_END()	