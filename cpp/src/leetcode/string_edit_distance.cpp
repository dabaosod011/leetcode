#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/edit-distance/
*/

namespace edit_distance
{
	class Solution 
	{
	public:
		int minDistance(string word1, string word2) 
		{
			int len1 = word1.size();
			int len2 = word2.size();
         
			vector<vector<int> > matrix(len1+1,vector<int>(len2+1, 0));
         
			for (int i=1;i<=len1;i++)
				matrix[i][0]=i;
	
			for (int i=1;i<=len2;i++)
				matrix[0][i]=i;
         
			for(int i=0;i<len1;i++)
			{
				for (int j=0;j<len2;j++)
				{                         
					matrix[i+1][j+1] = std::min(matrix[i+1][j], matrix[i][j+1]) + 1;					
					matrix[i+1][j+1] = std::min(matrix[i+1][j+1], matrix[i][j] + (word1[i]!=word2[j] ? 1 : 0) );
				}
			}
         
			return matrix[len1][len2];
		}


		/*int minDistance(string word1, string word2) 
		{
			return helper(word1, word2, word1.length(), word2.length());
		}

		int helper(string word1, string word2, int m, int n)
		{
			if( m == 0 && n == 0 )
				return 0;
 
			if( m == 0 )
				return n;
 
			if( n == 0 )
				return m;
 
			int left = helper(word1, word2, m-1, n) + 1;
			int right = helper(word1, word2, m, n-1) + 1;
			int corner = helper(word1, word2, m-1, n-1) + (word1[m-1] != word2[n-1]);
 
			return std::min(std::min(left, right), corner);
		}*/
	};
};

BOOST_AUTO_TEST_SUITE( edit_distance_test )

	boost::shared_ptr<edit_distance::Solution> solution_(new edit_distance::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running edit_distance_test case1..." <<std::endl;
		std::cout << solution_->minDistance("word1","word2") <<std::endl;
		std::cout << solution_->minDistance("a","ab") <<std::endl;
		//BOOST_ASSERT( 1 == solution_->minDistance("word1","word2") );
	}

BOOST_AUTO_TEST_SUITE_END()	