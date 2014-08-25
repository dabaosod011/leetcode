#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/word-break-ii/
*/

/**
*	The solution is copied from : http://zhaohongze.com/wordpress/2013/12/10/leetcode-word-break-ii/
*/
namespace word_breakII
{
	class Solution 
	{
	public:
		vector<string> wordBreak(string s, unordered_set<string> &dict) 
		{
			std::vector<std::string> results;
			if ( s.size() == 0 || dict.size() == 0)
				return results;

			unordered_set<string> usedDict;
			
			std::vector<bool> isSegmented(s.size()+1, false);
			isSegmented[0] = true;
			std::string tmp;
			for (auto it = 0; it < s.size(); it++)
			{
				if( isSegmented[it] == true )
				{
					for (auto len = 1; len < s.size()+1-it; len++)
					{
						tmp = s.substr(it, len);
						if (dict.count(tmp) != 0)
						{
							isSegmented[it+len] = true;
							usedDict.insert(tmp);
						}
					}
				}
			}

			if( !isSegmented[s.length()] )
				return results;

			//	build possible branches
			std::vector<int> indexSeg;
			std::vector<std::list<int> > allBranchs;
			for (auto it = isSegmented.begin(); it != isSegmented.end(); it++)
			{	
				if (*it == true)
					indexSeg.push_back( it-isSegmented.begin());
			}
			
			for (int it = indexSeg.size() -1 ; it>=0; it--)
			{
				if ( it == indexSeg.size() -1 )
				{	
					std::list<int> tmp;
					tmp.push_front(indexSeg[it]);
					allBranchs.push_back(tmp);
				}
				else
				{
					std::vector<std::list<int> > tmpBranches;
					for (auto eachBranch = allBranchs.begin(); eachBranch!=allBranchs.end(); eachBranch++ )
					{
						if ( it != 0)
							tmpBranches.push_back(*eachBranch);

						//Very Very Very important to prune here!!!
						std::string tmpword = s.substr(indexSeg[it], eachBranch->front() - indexSeg[it]);
						if (usedDict.count(tmpword))
							eachBranch->push_front(indexSeg[it]);
					}
					for (auto eachBranch = tmpBranches.begin(); eachBranch!=tmpBranches.end(); eachBranch++ )
					{
						if ( std::find(allBranchs.begin(),allBranchs.end(),*eachBranch ) == allBranchs.end() )
							allBranchs.push_back(*eachBranch);
					} 
				}
			}

			//	generate result
			bool isSelected;
			for (auto eachBranch = allBranchs.begin(); eachBranch != allBranchs.end(); eachBranch++)
			{
				if (eachBranch->front() != 0)
					continue;

				isSelected = true;
				std::string aResult;
				int begin = eachBranch->front(), end;
				eachBranch->pop_front();
				while ( !eachBranch->empty() )
				{
					end = eachBranch->front();
					eachBranch->pop_front();
					std::string tmp = s.substr(begin, end - begin);
					if (usedDict.count(tmp) == 0)
					{
						isSelected = false;
						break;
					}
					if (begin == 0 )
						aResult = aResult + tmp;
					else
						aResult = aResult + " " + tmp;
					begin = end;
				}

				if (isSelected)
					results.push_back(aResult);				
			}

			return results;
		}
	};
}

BOOST_AUTO_TEST_SUITE( word_breakII_test )

	boost::shared_ptr<word_breakII::Solution> solution_(new word_breakII::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running word_breakII_test case1..." <<std::endl;
		std::string s = "catsanddog";
		std::unordered_set<std::string> dict;
		dict.insert("cat");
		dict.insert("cats");
		dict.insert("and");
		dict.insert("sand");
		dict.insert("dog");
		std::vector<string> results = solution_->wordBreak(s, dict);

		for (auto it = results.begin(); it != results.end(); it++)
		{
			std::cout << "[" << *it << "]" <<std::endl;
		}

		//BOOST_ASSERT( true == solution_->wordBreak(s, dict) );
	}

BOOST_AUTO_TEST_SUITE_END()	