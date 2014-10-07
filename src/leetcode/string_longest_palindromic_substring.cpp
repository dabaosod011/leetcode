#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/longest-palindromic-substring/
*/

namespace longest_palindromic_substring
{
	class Solution 
	{
		public:
		string longestPalindrome(string s) 
		{
			std::set<std::string> known_palindrome;
			if (s.size()<=1)
				return s;

			int longest_len = 1;
			string longest_str = s.substr(0,1);
			string tmp;
			for (int i=1; i<s.size(); i++)
			{
				for (int j = 0; j < i-longest_len; j++)
				{
					tmp = s.substr(j, i-j+1);
					if (known_palindrome.find(tmp)!=known_palindrome.end())
					{
						longest_len++;
						longest_str = tmp;
					}
					else if (isPalindrome(tmp))
					{
						known_palindrome.insert(tmp);
						longest_len++;
						longest_str = tmp;
					}
				}
			}

			return longest_str;
		}

		bool isPalindrome(string s)
		{
			int i=0, j =s.length()-1;
			while(i < j)
			{
				if (s[i] != s[j])
					return false;
				i++;
				j--;
			}

			return true;
		}
	};
};

BOOST_AUTO_TEST_SUITE( longest_palindromic_substring_test )

	boost::shared_ptr<longest_palindromic_substring::Solution> solution_(new longest_palindromic_substring::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running longest_palindromic_substring_test case1..." <<std::endl;

		string s = "abb";
		BOOST_ASSERT(solution_->longestPalindrome(s) == "a");

		s = "aabaa";
		BOOST_ASSERT(solution_->longestPalindrome(s) == "aabaa");
		
		s = "a";
		BOOST_ASSERT(solution_->longestPalindrome(s) == "a");

		s = "zudfweormatjycujjirzjpyrmaxurectxrtqedmmgergwdvjmjtstdhcihacqnothgttgqfywcpgnuvwglvfiuxteopoyizgehkwuvvkqxbnufkcbodlhdmbqyghkojrgokpwdhtdrwmvdegwycecrgjvuexlguayzcammupgeskrvpthrmwqaqsdcgycdupykppiyhwzwcplivjnnvwhqkkxildtyjltklcokcrgqnnwzzeuqioyahqpuskkpbxhvzvqyhlegmoviogzwuiqahiouhnecjwysmtarjjdjqdrkljawzasriouuiqkcwwqsxifbndjmyprdozhwaoibpqrthpcjphgsfbeqrqqoqiqqdicvybzxhklehzzapbvcyleljawowluqgxxwlrymzojshlwkmzwpixgfjljkmwdtjeabgyrpbqyyykmoaqdambpkyyvukalbrzoyoufjqeftniddsfqnilxlplselqatdgjziphvrbokofvuerpsvqmzakbyzxtxvyanvjpfyvyiivqusfrsufjanmfibgrkwtiuoykiavpbqeyfsuteuxxjiyxvlvgmehycdvxdorpepmsinvmyzeqeiikajopqedyopirmhymozernxzaueljjrhcsofwyddkpnvcvzixdjknikyhzmstvbducjcoyoeoaqruuewclzqqqxzpgykrkygxnmlsrjudoaejxkipkgmcoqtxhelvsizgdwdyjwuumazxfstoaxeqqxoqezakdqjwpkrbldpcbbxexquqrznavcrprnydufsidakvrpuzgfisdxreldbqfizngtrilnbqboxwmwienlkmmiuifrvytukcqcpeqdwwucymgvyrektsnfijdcdoawbcwkkjkqwzffnuqituihjaklvthulmcjrhqcyzvekzqlxgddjoir";
		std::cout << solution_->longestPalindrome(s) <<std::endl;

		s = "jrjnbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfytdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx";
		std::cout << solution_->longestPalindrome(s) <<std::endl;
	}

BOOST_AUTO_TEST_SUITE_END()	