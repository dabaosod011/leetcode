#include "lc_header.h"

/**
 *	 https://oj.leetcode.com/problems/clone-graph/
 */

namespace clone_graph
{
	class Solution 
	{
	public:
		UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
		{
			if (NULL == node)
				return NULL;

			std::map<UndirectedGraphNode*, UndirectedGraphNode*> mapping;  // <oldgraph_node, newgraph_node>
			std::queue<UndirectedGraphNode*> que;
			mapping.clear();

			/*
			*	use BFS to parse and clone since we can iterate the neighbors, only in ONE iteration
			*/
			que.push(node);
			UndirectedGraphNode *newnode = new UndirectedGraphNode(node->label);
			mapping[node] = newnode;
			while (!que.empty())
			{
				UndirectedGraphNode *cur = que.front();
				que.pop();
				for (auto it = cur->neighbors.begin(); it != cur->neighbors.end(); it++)
				{
					if (mapping.find(*it) == mapping.end())
					{
						UndirectedGraphNode *copynode = new UndirectedGraphNode((*it)->label);
						mapping[cur]->neighbors.push_back(copynode);
						mapping[*it] = copynode;
						que.push(*it);
					}
					else
					{
						mapping[cur]->neighbors.push_back(mapping[*it]);
					}					
				}
			}

			return newnode;

		} // funtion: cloneGraph
	};
}

BOOST_AUTO_TEST_SUITE( clone_graph_test )

	boost::shared_ptr<clone_graph::Solution> solution_(new clone_graph::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running clone_graph_test case1..." <<std::endl;
	}

BOOST_AUTO_TEST_SUITE_END()	