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
			int dimension_row = board.size();
			if(dimension_row <= 2)
				return;
			int dimension_col = board[0].size();
			if(dimension_col<2)
				return;

			//	row==0
			for (int col=0; col<dimension_col; col++)
			{
				 if(board[0][col] == 'O') 
				 {
					board[0][col] = '#';  
					search(board, 0, col);  
				 }
			}

			//	row=dimension_row-1
			for (int col=0; col<dimension_col; col++)
			{
				 if(board[dimension_row-1][col] == 'O') 
				 {
					board[dimension_row-1][col] = '#';  
					search(board, dimension_row-1, col);  
				 }
			}

			//	col=0
			for (int row=0; row<dimension_row; row++)
			{
				 if(board[row][0] == 'O') 
				 {
					board[row][0] = '#';  
					search(board, row, 0);  
				 }
			}

			//	col=dimension_col-1
			for (int row=0; row<dimension_row; row++)
			{
				 if(board[row][dimension_col-1] == 'O') 
				 {
					board[row][dimension_col-1] = '#';  
					search(board, row, dimension_col-1);  
				 }
			}

			for(int i=0;i<dimension_row;i++)  
			{
				for(int j=0;j<dimension_col;j++)  
				{  
					if(board[i][j] == 'O')  
						board[i][j] = 'X';  
					else if(board[i][j] == '#')  
						board[i][j] = 'O';  
				} 
			}
			
		}

		void search(vector<vector<char>> &board, int row, int col)
		{
			int dimension_row = board.size();
			int dimension_col = board[0].size();

			if(row > 1 && board[row-1][col] == 'O')  
			{  
				board[row-1][col] = '#';  
				search(board, row-1, col);  
			}  

			if(row < dimension_row-1 && board[row+1][col] == 'O')  
			{  
				board[row+1][col] = '#';  
				search(board, row+1, col);  
			} 

			if(col > 1 && board[row][col-1] == 'O')  
			{  
				board[row][col-1] = '#';  
				search(board, row, col-1);  
			} 

			if(col < dimension_col-1 && board[row][col+1] == 'O')  
			{  
				board[row][col+1] = '#';  
				search(board, row, col+1);  
			}  
		}
	};
}


BOOST_AUTO_TEST_SUITE( surrounded_regions_test )

	boost::shared_ptr<surrounded_regions::Solution> solution_(new surrounded_regions::Solution());
	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running surrounded_regions_test case1..." <<std::endl;
		vector<vector<char>> board;
		board.push_back(boost::assign::list_of('X')('O')('X')('O')('X')('O'));
		board.push_back(boost::assign::list_of('O')('X')('O')('X')('O')('X'));
		board.push_back(boost::assign::list_of('X')('O')('X')('O')('X')('O'));
		board.push_back(boost::assign::list_of('O')('X')('O')('X')('O')('X'));

		solution_->solve(board);

		for(int i=0; i<board.size(); i++)
		{
			for(int j=0; j<board[0].size(); j++)
				std::cout << board[i][j] << " ";
			std::cout <<std::endl;
		}
	}

BOOST_AUTO_TEST_SUITE_END()	