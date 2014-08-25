#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/reverse-words-in-a-string/
*/

namespace reverse_words_in_a_string
{
	class Solution {
	public:
		void reverseWords(string &s) {
			s = trim(s);
			if(s.empty())
				return;

			string tmp;
			string::size_type pos = s.find_first_of(" ");
			while(pos != string::npos)
			{
				tmp = trim(s.substr(0,pos)) + " " + tmp;
				s = trim(s.substr(pos));
				pos = s.find_first_of(" ");
			}

			if( !s.empty() && !tmp.empty() )
			s = trim(s) + " " + trim(tmp);
		}

		std::string trim(const std::string &s)
		{
			std::string::const_iterator it = s.begin();
			while (it != s.end() && isspace(*it))
				it++;

			std::string::const_reverse_iterator rit = s.rbegin();
			while (rit.base() != it && isspace(*rit))
				rit++;

			return std::string(it, rit.base());
		}
	};
};

BOOST_AUTO_TEST_SUITE( reverse_words_in_a_string_test )

	boost::shared_ptr<reverse_words_in_a_string::Solution> solution_(new reverse_words_in_a_string::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running reverse_words_in_a_string_test case1..." <<std::endl;

		string s = "a";		
		solution_->reverseWords(s);
		BOOST_ASSERT( s == "a" );
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running reverse_words_in_a_string_test case2..." <<std::endl;

		string s = "This is a test ";
		solution_->reverseWords(s);
		BOOST_ASSERT( s == "test a is This" );
	}

	BOOST_AUTO_TEST_CASE( case3 ) 	
	{
		std::cout << "running reverse_words_in_a_string_test case3..." <<std::endl;

		string s = "  This is  a   test   ";
		solution_->reverseWords(s);
		BOOST_ASSERT( s == "test a is This" );
	}

BOOST_AUTO_TEST_SUITE_END()	