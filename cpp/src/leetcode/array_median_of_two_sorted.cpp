#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/max-points-on-a-line/
 */

namespace median_of_2_sorted_arrays
{
	class Solution 
	{
	public:
		double findMedianSortedArrays(int A[], int m, int B[], int n) 
		{
			if( (m+n)%2 == 0 )
				return (getMedian(A,m,B,n, (m+n)/2) + getMedian(A,m,B,n, (m+n)/2+1)) /2.0  ;
			else
				return getMedian(A,m,B,n, (m+n)/2+1);
		}

		double getMedian(int a[], int m, int b[], int n, int median_)
		{
			if (m > n)
				return getMedian(b, n, a, m, median_);
			if (m == 0)
				return b[median_ - 1];
			if (median_ == 1)
				return std::min(a[0], b [0]);

			int pa = std::min(median_/2, m), pb = median_ - pa;
			if (a[pa - 1] < b[pb - 1])
				return getMedian(a + pa, m - pa, b, n, median_ - pa);
			else if (a[pa - 1] > b[pb - 1])
				return getMedian(a, m, b + pb, n - pb, median_ - pb);
			else
				return a[pa - 1];
		}
	};
}

BOOST_AUTO_TEST_SUITE( median_of_2_sorted_arrays_test )
	boost::shared_ptr<median_of_2_sorted_arrays::Solution> solution_(new median_of_2_sorted_arrays::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running median_of_2_sorted_arrays_test case1..." <<std::endl;

		int a[] = {1,2,3,4};
		int b[] = {2,3,4,5,6,7,8,9,10,11};
		double median = solution_->findMedianSortedArrays(a,4,b,10);

		BOOST_ASSERT(median == 4.5);
	}

BOOST_AUTO_TEST_SUITE_END()	