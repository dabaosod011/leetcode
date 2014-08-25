#define BOOST_TEST_MODULE leetcode_test
#include "lc_header.h"

BOOST_AUTO_TEST_SUITE( leetcode_test )
	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running leetcode_test case1..." <<std::endl;
		int i = 1;
		BOOST_ASSERT( i == 1 );
	}
BOOST_AUTO_TEST_SUITE_END()	