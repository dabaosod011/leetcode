#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/search-in-rotated-sorted-array/
*/

namespace search_in_rotated_sorted_array
{
	class Solution 
	{
	public:
		int search_violent(int A[], int n, int target) 
		{
			int i = 0;
			while (i < n)
			{
				if(A[i] == target)
					break;
				i++;
			}

			if (i < n)
				return i;
			else 
				return -1;
		}

		int search(int A[], int n, int target) 
		{
			int left = 0, right = n-1;    
			while(left <= right)    
			{    
				int m = (left+right)/2;    
				if(A[m] == target) 
					return m;  

				if(A[m]>= A[left])    
				{    
					if(A[left]<=target && target< A[m])    
						right=m-1;    
					else    
						left = m+1;      
				}    
				else    
				{    
					if(A[m]< target && target<=A[right])    
						left = m+1;    
					else    
						right = m-1;   
				}    
			}    

			return -1;
		}
	};
};

BOOST_AUTO_TEST_SUITE( search_in_rotated_sorted_array_test )

	boost::shared_ptr<search_in_rotated_sorted_array::Solution> solution_(new search_in_rotated_sorted_array::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running array_search_in_rotated_sorted_array case1..." <<std::endl;
		int array[] = {4, 5, 6, 7, 0, 1, 2};
		BOOST_ASSERT(2 == solution_->search(array, 7, 6));
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running array_search_in_rotated_sorted_array case2..." <<std::endl;
		int array[] = {3, 1};
		BOOST_ASSERT(1 == solution_->search(array, 2, 1));
	}

BOOST_AUTO_TEST_SUITE_END()	