#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/copy-list-with-random-pointer/
 */

namespace copy_list_with_random_pointer
{
	class Solution 
	{
	public:
		RandomListNode *copyRandomList(RandomListNode *head) 
		{
			if (head == NULL)
				return NULL;
			
			std::map<RandomListNode*, RandomListNode*> mapping;
			mapping.clear();
			RandomListNode *current = head; 
			RandomListNode *newhead = new RandomListNode(-1);	// new head node
			RandomListNode *copy = newhead;

			while (current != NULL) 
			{
				RandomListNode *tmp = new RandomListNode(current->label);
				copy->next = tmp;
				mapping[current] = tmp;
				current = current->next;
				copy = copy->next;
			}
			
			RandomListNode *tmp = head, *newtmp = newhead->next;
			while (tmp != NULL)
			{
			    if (tmp->random==NULL)
                    newtmp->random==NULL;
                else
                    newtmp->random = mapping[tmp->random];
                    
				tmp = tmp->next;
				newtmp = newtmp->next;
			}

			RandomListNode *newhead2 = newhead->next;
			newhead->next = NULL;
			delete newhead;

			return newhead2;
		}
	};
};


BOOST_AUTO_TEST_SUITE( copy_list_with_random_pointer_test )
	boost::shared_ptr<copy_list_with_random_pointer::Solution> solution_(new copy_list_with_random_pointer::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running copy_list_with_random_pointer_test case1..." <<std::endl;
		
		RandomListNode *head = new RandomListNode(-1), *tmp;
		head->next = new RandomListNode(-1);

		RandomListNode *newHead = solution_->copyRandomList(head);	

		while (head != NULL)
		{
			tmp = head;
			head = head->next;
			tmp->next = NULL;
			tmp->random = NULL;
			delete tmp;
		}

		while (newHead != NULL)
		{
			tmp = newHead;
			newHead = newHead->next;
			tmp->next = NULL;
			tmp->random = NULL;
			delete tmp;
		}
	}
	
BOOST_AUTO_TEST_SUITE_END()	