#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/n-queens-ii/
 */

namespace n_queens2
{
	class Solution 
	{
	private:
		vector<vector<string> > result;
		int res;
	public:
		int totalNQueens(int n) 
		{
			vector<string> tmp(n, string(n,'.'));
			res = 0;
			NQueens(tmp, 0);
			return res;
		}

		void NQueens(vector<string> &tmp, int row)
		{
			if(row == tmp.size())
			{
				result.push_back(tmp);
				res++;
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

BOOST_AUTO_TEST_SUITE( n_queens2_test )

	boost::shared_ptr<n_queens2::Solution> solution_(new n_queens2::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running n_queens2_test case1..." <<std::endl;
		std::cout << solution_->totalNQueens(8) <<std::endl;

	}

BOOST_AUTO_TEST_SUITE_END()	