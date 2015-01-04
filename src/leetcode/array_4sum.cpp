#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/4sum/
 */

namespace four_sum
{
	class Solution 
	{
	public:
		vector<vector<int> > fourSum(vector<int> &num, int target) 
		{
			vector<vector<int> > result;
			if (num.size() < 4)
				return result;

			sort(num.begin(), num.end());
			int len = num.size();
			for (int first = 0; first < len-3; first++) 
			{
				if (first == 0 || (num[first] > num[first-1]))
				{
					for (int second = first + 1; second < len-2; second++) 
					{
						//	be careful here.
						//	if (second == 1 || num[second] > num[second-1])
						if (second == first + 1 || num[second] > num[second-1])
						{
							int third = second + 1;
							int four = len - 1;

							while (third < four) 
							{
								int sum = num[first] + num[second] + num[third] + num[four];
								if (sum == target) 
								{
									vector<int> tmp;
									tmp.push_back(num[first]);
									tmp.push_back(num[second]);
									tmp.push_back(num[third]);
									tmp.push_back(num[four]);
									result.push_back(tmp);
										
									third++;
									four--;

									while (third < four && num[four] == num[four+1])
										four--; 
									while (third < four && num[third] == num[third-1])
										third++;
								} 
								else if (sum < target) 
								{
									third++;
								}
								else 
								{
									four--;
								}
							}
						}
					}
				}
			}

			return result;
		}

		vector<vector<int> > fourSum_TLE(vector<int> &num, int target) 
		{
			return kSum(num, 4, target, 0);
		}

		vector< vector<int> > kSum(vector<int> &num, int K, int target, int begin) 
		{
			std::sort(num.begin(), num.end());
			vector< vector<int> > vecResults;
			if (K == 2) 
			{ 	
				vector<int> tmp;
				int i = begin, j = num.size() - 1;
				while (i < j) 
				{
					if (i == begin || num[i] > num[i - 1]) 
					{
						int sum = num[i] + num[j];
						if (sum == target) 
						{
							tmp.push_back(num[i++]);
							tmp.push_back(num[j--]);
							vecResults.push_back(tmp);
						}
						else if (sum > target) 
						{
							j--;
							while (i < j && num[j] == num[j+1])
								j--; 
						}
						else 
						{
							i++;
							while (i < j && num[i] == num[i-1])
								i++;
						}
					}
				}
		
				return vecResults;
			} 
			else
			{
				for (int i = begin; i < num.size(); ++i) 
				{
					if (i == begin || num[i] > num[i - 1]) 
					{
						vector< vector<int> > tmpResult = kSum(num, K - 1, target - num[i], i + 1);
						if (tmpResult.size() == 0)
							continue;
						for (auto it = tmpResult.begin(); it != tmpResult.end(); ++it) 
						{
							vector<int> tmp;
							tmp.push_back(num[i]);
							tmp.insert(tmp.end(), it->begin(), it->end());
							vecResults.push_back(tmp);
						}
					}
				}
	
				return vecResults;
			}
		}
	};
}

BOOST_AUTO_TEST_SUITE( four_sum_test )
	boost::shared_ptr<four_sum::Solution> solution_(new four_sum::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running four_sum case1..." <<std::endl;

		vector<int> nums = boost::assign::list_of(-1)(0)(1)(2)(-1)(-4);		
		vector<vector<int> > result = solution_->fourSum(nums, -1);

		for(auto row=result.begin(); row<result.end(); row++)
		{
			for (auto col=row->begin(); col<row->end(); col++)
				std::cout << *col << " ";
			std::cout << std::endl;
		}
	}

BOOST_AUTO_TEST_SUITE_END()	