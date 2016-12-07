#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/longest-palindromic-substring/
*	http://www.ninehackers.com/2014/11/16/Performance_issue_caused_by_vector_operation/
*/

namespace longest_palindromic_substring
{
	class Solution 
	{
		public:
		string longestPalindrome(string s) 
		{
			int len = s.size();
			if (len<=1)
				return s;

			//vector<vector<bool> > matrix(len,vector<bool>(len,false));
			bool **matrix = new bool*[len];       
			for(int i = 0; i < len; i++)
			{
				matrix[i] = new bool[i+1];         
				for(int j = 0; j <= i; j++)
					 matrix[i][j] = false;
			}

			int maxLen = 0, start = 0;
			for (int i=0; i<len; i++)
			{
				matrix[i][i] = true;
				for(int j=0; j<i; j++)
				{
					matrix[i][j] = (s[j]==s[i]) && ( i-j == 1 || matrix[i-1][j+1]);

					if ( (i-j+1)>maxLen && matrix[i][j] )
					{
						maxLen = i-j+1;
						start = j;
					}
				}
			}

	
			for(int i=0;i<len;i++)
				delete [] matrix[i];
			delete [] matrix; 

			return s.substr(start, maxLen);
		}

	};
};

BOOST_AUTO_TEST_SUITE( longest_palindromic_substring_test )

	boost::shared_ptr<longest_palindromic_substring::Solution> solution_(new longest_palindromic_substring::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running longest_palindromic_substring_test case1..." <<std::endl;

		string s = "abb";
		BOOST_ASSERT("bb" == solution_->longestPalindrome(s));

		s = "aabaa";
		BOOST_ASSERT("aabaa" == solution_->longestPalindrome(s));
		
		s = "a";
		BOOST_ASSERT("a" == solution_->longestPalindrome(s));

		s = "zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir";
		BOOST_ASSERT("gykrkyg" == solution_->longestPalindrome(s));

			s = "jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx";
		BOOST_ASSERT("qosoq" == solution_->longestPalindrome(s));
	}

BOOST_AUTO_TEST_SUITE_END()	