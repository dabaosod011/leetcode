#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/n-queens/
 */

namespace n_queens
{
	class Solution 
	{
	private:
		vector<vector<string> > result;
	public:
		vector<vector<string> > solveNQueens(int n) 
		{
			vector<string> tmp(n, string(n,'.'));
			NQueens(tmp, 0);
			return result;
		}

		void NQueens(vector<string> &tmp, int row)
		{
			if(row == tmp.size())
			{
				result.push_back(tmp);
				return;
			}

			for(int col = 0; col < tmp.size(); col++)
			{
				if(isValid(tmp, row, col))
				{
					tmp[row][col] = 'Q';
					NQueens(tmp, row+1);
					tmp[row][col] = '.';
				}
			}
		}

		bool isValid(vector<string> &cur, int row, int col)
		{
			for(int i = 0; i < row; i++)
				if(cur[i][col] == 'Q')
					return false;
			
			for(int i = row-1, j=col-1; i >= 0 && j >= 0; i--,j--)
				if(cur[i][j] == 'Q')
					return false;
		
			for(int i = row-1, j=col+1; i >= 0 && j < cur.size(); i--,j++)
				if(cur[i][j] == 'Q')
					return false;

			return true;
		}
	};
}

BOOST_AUTO_TEST_SUITE( n_queens_test )

	boost::shared_ptr<n_queens::Solution> solution_(new n_queens::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running n_queens_test case1..." <<std::endl;
		vector<vector<string> > result = solution_->solveNQueens(8);

		BOOST_ASSERT( 92 == result.size() );
	}

BOOST_AUTO_TEST_SUITE_END()	