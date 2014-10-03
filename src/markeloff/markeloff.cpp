#define BOOST_TEST_MODULE markeloff_test

#include <iostream>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( markeloff_test )
	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running markeloff_test case1..." <<std::endl;
		int i = 1;
		BOOST_ASSERT( i == 1 );
	}
BOOST_AUTO_TEST_SUITE_END()	