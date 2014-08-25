#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/linked-list-cycle-ii/
 */

namespace linked_list_cycle_II
{
	class Solution 
	{
	public:
		ListNode *detectCycle(ListNode *head) 
		{
        	if (head == NULL || head->next == NULL)
				return false;

			ListNode *quick = head;
			ListNode *slow = head;
			while ( quick != NULL && quick->next != NULL )
			{
				quick = quick->next->next;
				slow = slow->next;

				if (slow == quick)
					break;
			}

			if ( quick == NULL || quick->next == NULL)
				return NULL;

			slow = head;
			while (slow != quick)
			{
				slow = slow->next;
				quick = quick->next;
			}

			return slow;
		}
	};
};


BOOST_AUTO_TEST_SUITE( linked_list_cycle_II_test )
	boost::shared_ptr<linked_list_cycle_II::Solution> solution_(new linked_list_cycle_II::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running linked_list_cycle_II_test case1..." <<std::endl;
		
		ListNode *head, *node1, *node2, *node3;
		head = new ListNode(0);
		node1 = new ListNode(1);
		node2 = new ListNode(2);
		node3 = new ListNode(3);
		head->next = node1;
		node1->next = node2;
		node2->next = node3;
		node3->next = node1;

		ListNode *result = solution_->detectCycle(head);
		BOOST_ASSERT( result != NULL && result->val == 1 );

		delete head;
		delete node1;
		delete node2;
		delete node3;
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running linked_list_cycle_II_test case2..." <<std::endl;

		ListNode *head;
		std::vector<int> nodes = boost::assign::list_of(1)(2)(3)(4)(5)(6)(7)(8)(9)(10);	
		head = createLinkedList(nodes);

		ListNode *result = solution_->detectCycle(head);
		BOOST_ASSERT( result == NULL );

		destoryLinkedlist(head);
	}
	
BOOST_AUTO_TEST_SUITE_END()	