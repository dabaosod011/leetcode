#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/word-ladder/
*/

namespace word_ladder
{
	class Solution 
	{
	public:
		int ladderLength(string start, string end, unordered_set<string> &dict) 
		{
			if (start == end || dict.size() == 0)
				return 0;

			std::queue<std::string> word_queue;
			std::queue<int> depth_queue;
			word_queue.push(start);
			depth_queue.push(1);

			while( !word_queue.empty() )
			{
				std::string cur_word = word_queue.front();
				word_queue.pop();
				int cur_depth = depth_queue.front();
				depth_queue.pop();

				for (int i = 0; i < cur_word.length(); i++)
				{
					char temp = cur_word[i];
					for (char c = 'a'; c <= 'z'; c++)
					{
						cur_word[i] = c;
						if (cur_word == end)
						{
							return cur_depth + 1;
						}
                    
						if (dict.find(cur_word) != dict.end())
						{
							word_queue.push(cur_word);
							depth_queue.push(cur_depth + 1);
							dict.erase(cur_word);
						}
						cur_word[i] = temp;
					}
				}
			}

			return 0;
		}
	};
}

BOOST_AUTO_TEST_SUITE( word_ladder_test )

	boost::shared_ptr<word_ladder::Solution> solution_(new word_ladder::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running word_ladder_test case1..." <<std::endl;
		std::string start = "hit";
		std::string end = "cog";
		unordered_set<string> dict;
		dict.insert("hot");
		dict.insert("dot");
		dict.insert("dog");
		dict.insert("lot");
		dict.insert("log");		

		BOOST_ASSERT( 5 == solution_->ladderLength(start,end, dict) );
	}

BOOST_AUTO_TEST_SUITE_END()	