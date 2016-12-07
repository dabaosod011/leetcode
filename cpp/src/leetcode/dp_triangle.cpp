#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/triangle/
*/

namespace triangle
{
	class Solution 
	{
	public:
		int minimumTotal(vector<vector<int> > &triangle) 
		{
			int height = triangle.size();
			vector<int> state(height, -1);			
			for (auto i=0; i<height; i++)
				state[i] = triangle[height-1][i];

			for(int row=height-2; row >=0; row--)
			{
				for(int col=0; col<=row; col++)
					state[col] = std::min(triangle[row][col] + state[col], triangle[row][col] + state[col+1]);
			}

			return state[0];
		}	
	};
}

BOOST_AUTO_TEST_SUITE( triangle_test )

	boost::shared_ptr<triangle::Solution> solution_(new triangle::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running triangle_test case1..." <<std::endl;
		vector<vector<int> > triangle;
		triangle.push_back(boost::assign::list_of(2));
		triangle.push_back(boost::assign::list_of(3)(4));
		triangle.push_back(boost::assign::list_of(6)(5)(7));
		triangle.push_back(boost::assign::list_of(4)(1)(8)(3));

		BOOST_ASSERT(11 == solution_->minimumTotal(triangle));
	}

BOOST_AUTO_TEST_SUITE_END()	