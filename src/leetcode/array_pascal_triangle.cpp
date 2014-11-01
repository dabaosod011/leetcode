#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/pascals-triangle/
*/

namespace pascals_triangle
{
	class Solution 
	{
	public:
		vector<vector<int> > generate(int numRows) 
		{
			vector<vector<int> > result;

			if(numRows == 0)
				return result;

			vector<int> preRow(1,1);
			vector<int> curRow(1,1);
			result.push_back(curRow);
			for (auto i=1; i<numRows; i++)
			{
				curRow.clear();
				curRow.push_back(preRow[0]);
				for (auto j=0; j<preRow.size()-1; j++)
					curRow.push_back(preRow[j] + preRow[j+1]);
				curRow.push_back(preRow[preRow.size()-1]);

				result.push_back(curRow);
				preRow = curRow;
			}

			return result;
		}
	};
}

BOOST_AUTO_TEST_SUITE( pascals_triangle_test )

	boost::shared_ptr<pascals_triangle::Solution> solution_(new pascals_triangle::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running pascals_triangle_test case1..." <<std::endl;
		vector<vector<int> > result = solution_->generate(5);
		for (auto i=result.begin(); i<result.end(); i++)
		{
			for (auto j=i->begin(); j<i->end(); j++)
				std::cout << *j << " ";
			std::cout << std::endl;
		}
	}

BOOST_AUTO_TEST_SUITE_END()	