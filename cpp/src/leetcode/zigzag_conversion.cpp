#include "lc_header.h"

/**
 *	 https://oj.leetcode.com/problems/zigzag-conversion/
 */

namespace zigzag_conversion
{
	//	Not my code, copy from http://codeganker.blogspot.jp/2014/02/zigzag-conversion-leetcode.html
	class Solution 
	{
		public:
		string convert(string s, int nRows) 
		{
			if (s.size() < 1 || nRows <1)
				return "";

			if (nRows == 1)
				return s;

			string  res;
			int size = 2*nRows-2;
			for(int i=0;i<nRows;i++)
			{
				for(int j=i;j<s.length();j+=size)
				{
					res = res + s[j];
					if(i!=0 && i!=nRows-1 && j+size-2*i<s.length())
						res = res + s[j+size-2*i];
				}                
			}
			return res;
		}
	};
}

BOOST_AUTO_TEST_SUITE( zigzag_conversion_test )

	boost::shared_ptr<zigzag_conversion::Solution> solution_(new zigzag_conversion::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running zigzag_conversion_test case1..." <<std::endl;
		BOOST_ASSERT( "PAHNAPLSIIGYIR" == solution_->convert("PAYPALISHIRING", 3) );
	}

BOOST_AUTO_TEST_SUITE_END()	