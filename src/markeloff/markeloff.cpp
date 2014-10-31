#define BOOST_TEST_MODULE markeloff_test

#include "markeloff.h"

BOOST_AUTO_TEST_SUITE( markeloff_test )
	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running markeloff_test case1..." <<std::endl;
		int i = 1;
		BOOST_ASSERT( i == 1 );
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running markeloff_test case2..." <<std::endl;

		//	std::vector<int> const intVec = {1,2,3,4,5,6,7,8,9,10};
		//	not support in VS2012

		std::vector<int> const intVec = boost::assign::list_of(1)(2)(3)(4)(5)(6)(7)(8)(9)(10);
		std::copy(begin(intVec), end(intVec), std::ostream_iterator<int>(std::cout, " "));
		std::cout << std::endl;
	}
BOOST_AUTO_TEST_SUITE_END()	