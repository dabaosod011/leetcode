#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/insertion-sort-list/
 */

namespace insertion_sort_list
{
	class Solution {
	public:
		ListNode *insertionSortList(ListNode *head) 
		{
			if (head == NULL || head->next ==NULL)
				return head;

			ListNode *newhead, *tmp , *newPos;
			newhead = head;
			head = head->next;
			newhead->next = NULL;			

			while (head != NULL)
			{
				tmp = head;
				head = head->next;
				
				if (tmp->val <= newhead->val)
				{
					tmp->next = newhead;
					newhead = tmp;
				}
				else
				{
					newPos = newhead;
					while(newPos->next != NULL && newPos->next->val < tmp->val)
						newPos = newPos->next;

					tmp->next = newPos->next;
					newPos->next = tmp;
				}				
			}

			return newhead;
		}
	};
};

BOOST_AUTO_TEST_SUITE( insertion_sort_list_test )
	boost::shared_ptr<insertion_sort_list::Solution> solution_(new insertion_sort_list::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running insertion_sort_list_test case1..." <<std::endl;
		srand( (unsigned)time(NULL));
		ListNode *head;

		std::vector<int> nodes;
		for (int i=0; i<10; i++)
			nodes.push_back(rand()%100);	
		head = createLinkedList(nodes);
		//dispayLinkedList(head);

		head = solution_->insertionSortList(head);
		//dispayLinkedList(head);
		for ( ListNode *idx = head; idx->next != NULL; idx = idx->next )
			BOOST_ASSERT( idx->val <= idx->next->val );

		destoryLinkedlist(head);
	}

BOOST_AUTO_TEST_SUITE_END()	