#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/reverse-linked-list-ii/
 */

namespace reverse_linked_list2
{
	class Solution 
	{
	public:
		ListNode *reverseBetween(ListNode *head, int m, int n) 
		{
			if( head == NULL || head->next == NULL || m >=n )
				return head;

			//	need to leverage newhead while m==1
			ListNode* newHead = new ListNode(-1);
			newHead->next = head;

			int curCount = 1;
			ListNode *cursor = newHead;
			while (curCount < m && cursor->next != NULL)
			{
				cursor = cursor->next;
				curCount++;
			}

			//	reach the end, and m is greater the length of list
			if( cursor->next == NULL )
				return head;

			//	now cursor is the node before mth
			ListNode *reservedNode = cursor;
			cursor = cursor->next;
			curCount++;
			ListNode *nextNode = cursor->next;
			while (curCount <= n && nextNode != NULL)
			{
				cursor->next = nextNode->next;
				nextNode->next = reservedNode->next;
				reservedNode->next = nextNode;
				nextNode = cursor->next;
				curCount++;
			}

			head =  newHead->next;
			newHead->next = NULL;
			delete newHead;

			return head;
		} 
	};
};


BOOST_AUTO_TEST_SUITE( reverse_linked_list2_test )
	boost::shared_ptr<reverse_linked_list2::Solution> solution_(new reverse_linked_list2::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running reverse_linked_list2_test case1..." <<std::endl;
		
		std::vector<int> nodes = boost::assign::list_of(1)(2)(3)(4)(5)(6)(7)(8)(9)(10);	
		ListNode *head = createLinkedList(nodes);
		dispayLinkedList(head);

		head = solution_->reverseBetween(head,2,5);
		dispayLinkedList(head);

		destoryLinkedlist(head);
	}

BOOST_AUTO_TEST_SUITE_END()	