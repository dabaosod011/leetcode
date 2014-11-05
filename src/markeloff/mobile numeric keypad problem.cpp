#include "markeloff.h"

/*
*	http://www.geeksforgeeks.org/mobile-numeric-keypad-problem/?utm_source=feedburner&utm_medium=feed&utm_campaign=Feed%3A+Geeksforgeeks+%28GeeksforGeeks%29
*/


namespace mobile_numeric_keypad_problem
{
	class Solution 
	{
		public:
			int getCountInPosition(int N)
			{
				if (N == 1)
					return 10;

				vector<vector<int> > matrix(10, vector<int>(N+1, 0));
				for (int i=0; i<=9;i++)
					matrix[i][1] = 1;

				int phone[4][3] = 
							{
								{1,2,3},
								{4,5,6},
								{7,8,9},
								{-1,0,-1},
							};
	
				for (int step = 2; step <=N; step++)
				{
					for (int i=0; i<4; i++)
					{
						for (int j=0; j<3; j++)
						{
							if(phone[ i][j] != -1)
							{
								int curNum = -1, nextNum = -1;

								//	current
								nextNum = curNum = phone[i][j];
								matrix[curNum][step] += matrix[nextNum][step-1];

								//	up
								if( i-1 >= 0 )
								{
									curNum = phone[i][j];
									nextNum = phone[i-1][j];
									if (nextNum != -1)
										matrix[curNum][step] += matrix[nextNum][step-1];
								}

								//	left
								if( j-1 >= 0 )
								{
									curNum = phone[i][j];
									nextNum = phone[i][j-1];
									if (nextNum != -1)
										matrix[curNum][step] += matrix[nextNum][step-1];
								}

								//	right
								if( j+1 <= 2 )
								{
									curNum = phone[i][j];
									nextNum = phone[i][j+1];
									if (nextNum != -1)
										matrix[curNum][step] += matrix[nextNum][step-1];
								}

								//	down
								if( i+1 <= 3 )
								{
									curNum = phone[i][j];
									nextNum = phone[i+1][j];
									if (nextNum != -1)
										matrix[curNum][step] += matrix[nextNum][step-1];
								}

							}
						}
					}
				}

				int total = 0;
				for (int i = 0; i < 10; i++)
					total += matrix[i][N];

				return total;
			}
	};
}


BOOST_AUTO_TEST_SUITE( mobile_number_Keyboard_test )

	boost::shared_ptr<mobile_numeric_keypad_problem::Solution> solution_(new mobile_numeric_keypad_problem::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{	
		std::cout << "running mobile_number_Keyboard_test case1..." <<std::endl;

		BOOST_ASSERT( solution_->getCountInPosition(1) == 10 );
		BOOST_ASSERT( solution_->getCountInPosition(2) == 36 );
		BOOST_ASSERT( solution_->getCountInPosition(3) == 138 );
		BOOST_ASSERT( solution_->getCountInPosition(4) == 532 );
		BOOST_ASSERT( solution_->getCountInPosition(5) == 2062 );
	}

BOOST_AUTO_TEST_SUITE_END()	