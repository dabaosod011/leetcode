#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/pascals-triangle-ii/
*/

namespace pascals_triangle2
{
	class Solution 
	{
	public:
		vector<int> getRow(int rowIndex) 
		{
			vector<int> preRow(1,1);
			vector<int> curRow = preRow;

			for(auto i=0; i<rowIndex; i++)
			{
				curRow.clear();		

				curRow.push_back(preRow[0]);
				for (auto j=0; j<preRow.size()-1; j++)
					curRow.push_back(preRow[j] + preRow[j+1]);
				curRow.push_back(preRow[preRow.size()-1]);

				preRow = curRow;
			}

			return curRow;
		}
	};
}

BOOST_AUTO_TEST_SUITE( pascals_triangle2_test )

	boost::shared_ptr<pascals_triangle2::Solution> solution_(new pascals_triangle2::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running pascals_triangle2_test case1..." <<std::endl;
		vector<int> result = solution_->getRow(5);
		for (auto i=result.begin(); i<result.end(); i++)
			std::cout << *i << " ";
		std::cout << std::endl;
	}

BOOST_AUTO_TEST_SUITE_END()	