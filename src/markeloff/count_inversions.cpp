#include "markeloff.h"

/*
*	http://www.geeksforgeeks.org/counting-inversions/
*	https://class.coursera.org/algo-006/lecture
*/

namespace count_inversions
{
	class Solution 
	{
		public:
			int countInversions(vector<int> &array)
			{
				int len = array.size();

				if (len <= 1)
					return 0;

				vector<int> firsthalf(array.begin(), array.begin() + len/2);
				vector<int> secondhalf(array.begin() + len/2, array.end());

				return countInversions(firsthalf) + countInversions(secondhalf) + merge_and_count(firsthalf, secondhalf, array);
			}

			int merge_and_count(vector<int> &firsthalf, vector<int> &secondhalf, vector<int> &output)
			{
				int i=0, j=0, inversion_count = 0;
				int next;
				output.clear();
				while ( i<firsthalf.size() && j<secondhalf.size() )
				{
					next = std::min(firsthalf[i], secondhalf[j]);
					output.push_back(next);

					if(next == secondhalf[j])
					{
						j++;
						inversion_count = inversion_count + firsthalf.size() - i;
					}
					else
					{
						i++;
					}
				}

				if ( i != firsthalf.size() )
					for (int idx=i; idx <firsthalf.size(); idx++ )
						output.push_back(firsthalf[idx]);

				if ( j != secondhalf.size() )
					for (int idx=j; idx <secondhalf.size(); idx++ )
						output.push_back(secondhalf[idx]);

				return inversion_count;
			}
	};
}

BOOST_AUTO_TEST_SUITE( count_inversions_test )

	boost::shared_ptr<count_inversions::Solution> solution_(new count_inversions::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{	
		std::cout << "running count_inversions_test case1..." <<std::endl;
		vector<int> array = boost::assign::list_of(5)(4)(3)(2)(1);

		BOOST_ASSERT( 10 == solution_->countInversions(array) );
		std::copy(array.begin(), array.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}
BOOST_AUTO_TEST_SUITE_END()	