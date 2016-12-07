#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/reorder-list/
 */

namespace reorder_list
{
	class Solution {
	public:
		void reorderList(ListNode *head) 
		{
			if (head == NULL || head->next == NULL)
				return;

			ListNode *quick = head->next;
			ListNode *slow = head;
			while( quick != NULL && quick->next != NULL )
			{
				quick = quick->next->next;
				slow = slow->next;
			}
			ListNode* newtail = slow;
			slow = slow->next;
			newtail->next = NULL;

			slow = reverseList(slow);
			ListNode *pos1 = head, *pos2 = slow;
			ListNode *tmp1, *tmp2;
			while( pos1 != NULL && slow != NULL )
			{
				tmp1 = pos1->next;
				tmp2 = slow->next;

				slow->next = pos1->next;
				pos1->next = slow;

				pos1 = tmp1;
				slow = tmp2;				
			}

			return;

		}

		ListNode *reverseList(ListNode *head)
		{
			ListNode* cursor = NULL;
			ListNode* next;
			while (head)
			{
				next = head->next;
				head->next = cursor;
				cursor = head;
				head = next;
			}
			 return cursor;
		}		
	};
};

BOOST_AUTO_TEST_SUITE( reorder_list_test )
	boost::shared_ptr<reorder_list::Solution> solution_(new reorder_list::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running reorder_list_test case1..." <<std::endl;

		std::vector<int> nodes = boost::assign::list_of(1)(2)(3)(4)(5)(6)(7)(8)(9)(10);
		ListNode *head = createLinkedList(nodes);
		dispayLinkedList(head);
		
		solution_->reorderList(head);
		dispayLinkedList(head);

		destoryLinkedlist(head);
	}
	 
BOOST_AUTO_TEST_SUITE_END()	