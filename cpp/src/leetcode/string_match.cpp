#include "lc_header.h"


namespace string_match
{
	class Solution 
	{
	public:
		int ViolentMatch(char* s, char*p)
		{
			int len_s = strlen(s);
			int len_p = strlen(p);

			if (len_p > len_s)
				return -1;

			for (int i = 0; i <= (len_s-len_p); i++)
			{
				int j = 0;
				while (j < len_p)
				{
					if (s[i+j] != p[j])
						break;
					j++;
				}

				if( j == len_p )
					return i;
			}

			return -1;
		}
		
		int ViolentMatch2(char* s, char*p)
		{
			int sLen = strlen(s);  
			int pLen = strlen(p);  
  
			int i = 0;  
			int j = 0;  
			while (i < sLen && j < pLen)  
			{  
				if (s[i] == p[j])  
				{       
					i++;  
					j++;  
				}  
				else  
				{  
					i = i - j + 1;  
					j = 0;  
				}  
			}  

			if (j == pLen)  
				return i - j;  
			else  
				return -1; 
		}

		void GetNext(char* p,int next[])  
		{  
			int pLen = strlen(p);  
			next[0] = -1;  
			int k = -1;  
			int j = 0;  
			while (j < pLen - 1)  
			{  
				if (k == -1 || p[j] == p[k])   
				{  
					++j;  
					++k;  
					next[j] = k;  
				}  
				else   
				{  
					k = next[k];  
				}  
			}  
		} 

		int KmpSearch(char* s, char* p)  
		{  
			int i = 0;  
			int j = 0;  
			int sLen = strlen(s);  
			int pLen = strlen(p); 		

			int *next = new int[pLen];
			GetNext(p,next);

			while (i < sLen && j < pLen)  
			{     
				if (j == -1 || s[i] == p[j])  
				{  
					i++;  
					j++;  
				}  
				else  
				{       
					j = next[j];  
				}  
			}  

			delete next;
			if (j == pLen)  
				return i - j;  
			else  
				return -1;  
		} 
	};
}


BOOST_AUTO_TEST_SUITE( string_match_test )

	boost::shared_ptr<string_match::Solution> solution_(new string_match::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running string_match_test case1..." <<std::endl;

		char *s = "Let Her Go";
		char *target = "Her";
		BOOST_ASSERT( 4 == solution_->ViolentMatch(s,target) );
		BOOST_ASSERT( 4 == solution_->ViolentMatch2(s,target) );
		BOOST_ASSERT( 4 == solution_->KmpSearch(s,target) );
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running string_match_test case2..." <<std::endl;

		char *s = "Let Her Go";
		char *target = "Herr";
		BOOST_ASSERT( -1 == solution_->ViolentMatch(s,target) );
		BOOST_ASSERT( -1 == solution_->ViolentMatch2(s,target) );
		BOOST_ASSERT( -1 == solution_->KmpSearch(s,target) );
	}

	BOOST_AUTO_TEST_CASE( case3 ) 	
	{
		std::cout << "running string_match_test case3..." <<std::endl;

		char *s = "Let Her Go";
		char *target = "o";
		BOOST_ASSERT( 9 == solution_->ViolentMatch(s,target) );
		BOOST_ASSERT( 9 == solution_->ViolentMatch2(s,target) );
		BOOST_ASSERT( 9 == solution_->KmpSearch(s,target) );
	}

	BOOST_AUTO_TEST_CASE( case4 ) 	
	{
		std::cout << "running string_match_test case4..." <<std::endl;

		char *s = "Let Her Go";
		char *target = "e";
		BOOST_ASSERT( 1 == solution_->ViolentMatch(s,target) );
		BOOST_ASSERT( 1 == solution_->ViolentMatch2(s,target) );
		BOOST_ASSERT( 1 == solution_->KmpSearch(s,target) );
	}

	BOOST_AUTO_TEST_CASE( case5 ) 	
	{
		std::cout << "running string_match_test case5..." <<std::endl;

		char *s = "BBC ABCDAB ABCDABCDABDE";
		char *target = "ABCDABD";
		BOOST_ASSERT( 15 == solution_->ViolentMatch(s,target) );
		BOOST_ASSERT( 15 == solution_->ViolentMatch2(s,target) );
		BOOST_ASSERT( 15 == solution_->KmpSearch(s,target) );
	}

BOOST_AUTO_TEST_SUITE_END()	