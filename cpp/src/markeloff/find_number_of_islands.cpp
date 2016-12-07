#include "markeloff.h"

/**
*	http://www.geeksforgeeks.org/find-number-of-islands/
***/

namespace find_number_of_islands
{
	class Solution 
	{
	public:
		Solution()
		{
			directions.push_back(std::make_pair(-1,-1));
			directions.push_back(std::make_pair(-1,0));
			directions.push_back(std::make_pair(-1,+1));
			directions.push_back(std::make_pair(0,-1));
			directions.push_back(std::make_pair(0,+1));
			directions.push_back(std::make_pair(+1,-1));
			directions.push_back(std::make_pair(+1,0));
			directions.push_back(std::make_pair(+1,1));	
		}

		int countIslands(vector<vector<int> > &islands)
		{
			int Row = islands.size();
			int Col = islands[0].size();
			vector<vector<bool> > isVisited(Row,vector<bool>(Col,false));

			int count = 0;
			for (int i = 0; i < Row; ++i)
			{
				for (int j = 0; j < Col; ++j)
				{
					if (islands[i][j] && !isVisited[i][j])
					{
						DFS(islands, i, j, isVisited);
						++count;
					}
				}
			}
 
			return count;
		}

	private:
		std::vector<std::pair<int, int>> directions;	

		bool isSafe(vector<vector<int> > &islands, int i, int j,vector<vector<bool> > &isVisited)
		{
			int Row = islands.size();
			int Col = islands[0].size();

			if (i < 0 || i >= Row || j < 0 || j >= Col)
				return false;

			if ( isVisited[i][j] )
				return false;

			return islands[i][j];
		}

		void DFS(vector<vector<int> > &islands, int i, int j, vector<vector<bool> > &isVisited)
		{
			isVisited[i][j] = true;
			for (auto it=directions.begin(); it!=directions.end(); ++it)
			{
				if (isSafe(islands, i + it->first, j + it->second, isVisited) )
					DFS(islands, i + it->first, j + it->second, isVisited);
			}
		}
			
	};
}

BOOST_AUTO_TEST_SUITE( find_number_of_islands_test )

	boost::shared_ptr<find_number_of_islands::Solution> solution_(new find_number_of_islands::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{	
		std::cout << "running find_number_of_islands_test case1..." <<std::endl;
		vector<vector<int> > islands;
		islands.push_back(boost::assign::list_of(1)(1)(0)(0)(0));
		islands.push_back(boost::assign::list_of(0)(1)(0)(0)(1));
		islands.push_back(boost::assign::list_of(1)(0)(0)(1)(1));
		islands.push_back(boost::assign::list_of(0)(0)(0)(0)(0));
		islands.push_back(boost::assign::list_of(1)(0)(1)(0)(1));

		BOOST_ASSERT( 5 == solution_->countIslands(islands) );
	}
BOOST_AUTO_TEST_SUITE_END()	