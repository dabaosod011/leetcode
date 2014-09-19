#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/permutations/
 */

namespace permutations
{
	class Solution 
	{
		vector<vector<int> > result; 
	public:
		vector<vector<int> > permute(vector<int> &num)
		{
			generate(num, 0, num.size());  
			return result;			
		}

		void generate(vector<int> &num, int i, int total)
		{  
			if(i == total)
			{
				result.push_back(num);
				return;
			}
          
			for(int j = i; j < total; j++)
			{  
				std::swap(num[i], num[j]);  
				generate(num, i+1, total);  
				std::swap(num[i], num[j]);  
			}  
		}  

	};
};

BOOST_AUTO_TEST_SUITE( permutations_test )
	boost::shared_ptr<permutations::Solution> solution_(new permutations::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running permutations_test case1..." <<std::endl;
		vector<int> numbers = boost::assign::list_of(1)(2)(3)(4)(5);
		vector<vector<int> > result = solution_->permute(numbers);

		for (auto it1 = result.begin(); it1 != result.end(); it1++)
		{
			for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
				std::cout << *it2 << " ";
			std::cout <<std::endl;
		}
	}

BOOST_AUTO_TEST_SUITE_END()		