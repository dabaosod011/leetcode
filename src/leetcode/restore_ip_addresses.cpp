#include "lc_header.h"

/**
 *	 https://oj.leetcode.com/problems/restore-ip-addresses/
 */

namespace restore_ip_addresses
{
	class Solution 
	{
	public:
		vector<string> restoreIpAddresses(string s) 
		{			
			if ( s.length() > 12 || s.length() < 4)
				return result;

			resolve(s, "", 1);
			return result;
		}
	private:
		vector<string> result;
		void resolve(string s, string ip, int cur_index) 
		{
			if(cur_index == 4) 
			{
				if( valid(s) ) 
				{
					ip += s;
					result.push_back(ip);
				}
				return;
			}

			string ip_bkp = ip;
			for(int i=1; i<= std::min(3,(int)s.length()); i++) 
			{
				string cur_section = s.substr(0,i);
				string remain_string = s.substr(i);
				if( valid(cur_section) && remain_string.length() <= ((4-cur_index)*3) && remain_string.length() >= (4-cur_index) ) 
				{
					ip += (s.substr(0,i) + ".");
					resolve(s.substr(i), ip, cur_index+1);
					ip = ip_bkp;
				}
			}
		}
        

		bool valid(string s) 
		{
			if( s.length() > 1 && s[0] == '0' ) 
				return false;			
			else if(atoi(s.c_str()) > 255) 
				return false;

			return true;
		}
	};
}

BOOST_AUTO_TEST_SUITE( restore_ip_addresses_test )

	boost::shared_ptr<restore_ip_addresses::Solution> solution_(new restore_ip_addresses::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running restore_ip_addresses_test case1..." <<std::endl;
		std::string ss = "25525511135";
		vector<string> result = solution_->restoreIpAddresses(ss);

		for (auto it = result.begin(); it != result.end(); it++)
			std::cout << *it <<std::endl;

		//BOOST_ASSET(result.size() == 2);
	}

BOOST_AUTO_TEST_SUITE_END()	