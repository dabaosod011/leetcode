#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/unique-paths/
*/

namespace unique_paths
{
	class Solution2 
	{
		//	reject because of timeout
		public:
			int uniquePaths(int m, int n) 
			{
				if (m == 1 || n == 1)
					return 1;
				else return uniquePaths(m-1, n) + uniquePaths(m, n-1);
			}
	};

	class Solution 
	{
	public:
		int uniquePaths(int m, int n) 
		{
			vector<int> steps(n, 1);  
			for (int i = 1; i < m; i++)  
			{  
				for (int j = 1; j < n; j++)  
				{  
					steps[j] += steps[j-1];  
				}  
			}  
			return steps[n-1];  
		}
	};
};

BOOST_AUTO_TEST_SUITE( unique_paths_test )

	boost::shared_ptr<unique_paths::Solution> solution_(new unique_paths::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running unique_paths_test case1..." <<std::endl;

		std::cout << solution_->uniquePaths(3,7) <<std::endl;
		BOOST_ASSERT( 28 == solution_->uniquePaths(3,7) );
	}

	

BOOST_AUTO_TEST_SUITE_END()	