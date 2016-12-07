#include "lc_header.h"

/**
 *	 https://oj.leetcode.com/problems/gas-station/
 */

namespace gas_station
{
	class Solution 
	{
		public:
		int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
		{
			vector<int> diff(gas.size(), 0);
			for(int i=0; i< gas.size(); i++)
			{
				diff[i] = gas[i] - cost[i];
			}

			int sum_diff = 0;
			for (int i=0; i < diff.size(); i++) 	
				sum_diff += diff[i];
			if (sum_diff < 0)
				return -1;

			int sum = 0;
			int start = 0;
			for(int i=0; i<diff.size(); i++)
			{
				//	find first i, make all sum (index < i) < 0, but i+1 begins to > 0
				sum += diff[i];
				if(sum < 0)
				{	
					start = i+1;
					sum = 0;
				}
			}

			return start;
		}
	};
}

BOOST_AUTO_TEST_SUITE( gas_station_test )

	boost::shared_ptr<gas_station::Solution> solution_(new gas_station::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running gas_station_test case1..." <<std::endl;
		std::vector<int> gas = boost::assign::list_of(2);
		std::vector<int> cost = boost::assign::list_of(2);

		BOOST_ASSERT(0 == solution_->canCompleteCircuit(gas, cost));
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running gas_station_test case2..." <<std::endl;
		std::vector<int> gas = boost::assign::list_of(1)(2)(3)(4)(5);
		std::vector<int> cost = boost::assign::list_of(3)(4)(5)(1)(2);

		BOOST_ASSERT(3 == solution_->canCompleteCircuit(gas, cost));
	}

BOOST_AUTO_TEST_SUITE_END()	