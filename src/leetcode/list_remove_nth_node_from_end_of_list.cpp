#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/remove-nth-node-from-end-of-list/
 */

namespace remove_nth_node_from_end_of_list
{
	class Solution 
	{
	public:
		ListNode *removeNthFromEnd(ListNode *head, int n) 
		{
			ListNode *quick = head, *slow = head;
			int i = 0;
			while(i++ < n)
				quick = quick->next;

			if (quick == NULL) 
			{
				ListNode *newhead = head->next;
				head->next = NULL;
				delete head;

				return newhead;
			}
			
			while (quick->next != NULL) 
			{
				quick = quick->next;
				slow = slow->next;
			}

			ListNode *tmp = slow->next;
			slow->next = slow->next->next;
			tmp->next = NULL;
			delete tmp;

			return head;
		}
	};
};


BOOST_AUTO_TEST_SUITE( remove_nth_node_from_end_of_list_test )
	boost::shared_ptr<remove_nth_node_from_end_of_list::Solution> solution_(new remove_nth_node_from_end_of_list::Solution());
	
	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running remove_nth_node_from_end_of_list_test case1..." <<std::endl;

		std::vector<int> num = boost::assign::list_of(1)(2)(3)(4)(5)(6)(7);
		ListNode *head = createLinkedList(num);
		ListNode *newhead = solution_->removeNthFromEnd(head, 3);
		dispayLinkedList(newhead);
		destoryLinkedlist(newhead);
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running remove_nth_node_from_end_of_list_test case2..." <<std::endl;

		std::vector<int> num = boost::assign::list_of(1)(2);
		ListNode *head = createLinkedList(num);
		ListNode *newhead = solution_->removeNthFromEnd(head, 2);
		dispayLinkedList(newhead);
		destoryLinkedlist(newhead);
	}

	BOOST_AUTO_TEST_CASE( case3 ) 	
	{
		std::cout << "running remove_nth_node_from_end_of_list_test case3..." <<std::endl;

		std::vector<int> num = boost::assign::list_of(1);
		ListNode *head = createLinkedList(num);
		ListNode *newhead = solution_->removeNthFromEnd(head, 1);
		dispayLinkedList(newhead);
		destoryLinkedlist(newhead);
	}

BOOST_AUTO_TEST_SUITE_END()	