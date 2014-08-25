#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/max-points-on-a-line/
 */

namespace max_points_on_a_line
{
	class Solution 
	{
	public:
		int maxPoints(vector<Point> &points) 
		{
			int totalNumber = points.size();
			if (totalNumber <= 2)
				return totalNumber;

			int max = 1;
			std::unordered_map<double, int> umap;
			for (int i = 0; i < totalNumber; i++)
			{
				umap.clear();
				int tmpMax = 1;
				int samePoint = 0;
			
				for (int j=i+1; j<totalNumber; j++)
				{
					// calculate  
					double angle; 
					if(points[i].x == points[j].x && points[i].y == points[j].y)
					{
						samePoint++;
						continue;
					}
					else if(points[i].x == points[j].x && points[i].y != points[j].y)
					{
						angle = std::numeric_limits<double>::infinity();
					}
					else
					{
						angle = 1.0*(points[i].y - points[j].y) / (points[i].x - points[j].x);
					}

					if (umap.find(angle) == umap.end())
					{
						umap.insert(std::make_pair(angle, 2));
					}
					else
					{
						umap[angle] = umap[angle] + 1;
					}

					if(tmpMax < umap[angle])
						tmpMax = umap[angle];
				}

				if (max < tmpMax + samePoint)
					max = tmpMax + samePoint;
			}
			return max;
		}
	};
};

BOOST_AUTO_TEST_SUITE( max_points_on_a_line )
	boost::shared_ptr<max_points_on_a_line::Solution> solution_(new max_points_on_a_line::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running max_points_on_a_line case1..." <<std::endl;

		vector<Point> points = boost::assign::list_of(Point(0,0))(Point(1,1))(Point(0,0));
		BOOST_ASSERT( solution_->maxPoints(points) == 3 );
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running max_points_on_a_line case2..." <<std::endl;

		vector<Point> points = boost::assign::list_of(Point(0,0))(Point(1,1))(Point(2,3));
		BOOST_ASSERT( solution_->maxPoints(points) == 2 );
	}

BOOST_AUTO_TEST_SUITE_END()	