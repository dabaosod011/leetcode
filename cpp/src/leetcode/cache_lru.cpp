#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/lru-cache/
 */

namespace lru_cache
{
	class LRUCache
	{
	public:
		LRUCache(int capacity) 
		{
			m_Capacity = capacity;
		}
    
		int get(int key) 
		{
			int result;
			if(m_Cache.find(key) == m_Cache.end())
			{
				return -1;
			}
			else
			{
				result = m_Cache[key].first;   
				m_Keylist.erase(m_Cache[key].second);
				m_Keylist.push_front(key);
				m_Cache[key].second = m_Keylist.begin();
				return result;
			}
		}
    
		void set(int key, int value) 
		{
			if(m_Cache.find(key) != m_Cache.end())
			{
				m_Cache[key].first = value;
				m_Keylist.erase(m_Cache[key].second);
				m_Keylist.push_front(key);
				m_Cache[key].second = m_Keylist.begin();

				return;
			}
			else
			{
				if (m_Keylist.size() >= m_Capacity)
				{
					//	remove the Least Recently Used (LRU) cache
					int lru_key = m_Keylist.back();
					m_Keylist.pop_back();
					m_Cache.erase(lru_key);
				}

				m_Keylist.push_front(key);
				m_Cache[key] =  std::make_pair(value,m_Keylist.begin());
				return;
			}			
		}
	public:
		std::list<int> m_Keylist;
		std::unordered_map<int, std::pair<int,std::list<int>::iterator> > m_Cache;
		int m_Capacity;
	};
};

BOOST_AUTO_TEST_SUITE( lru_cache_test )
	boost::shared_ptr<lru_cache::LRUCache> solution_(new lru_cache::LRUCache(3));

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running lru_cache_test case1..." <<std::endl;
		solution_->set(1,1);
		solution_->set(2,2);
		solution_->set(3,3);
		solution_->set(1,4);
		solution_->set(5,5);

		BOOST_ASSERT( solution_->m_Cache[1].first == 4
					&& solution_->m_Cache[3].first == 3
					&& solution_->m_Cache[5].first == 5 );
	}

BOOST_AUTO_TEST_SUITE_END()	