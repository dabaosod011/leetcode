#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/sort-list/
*/

namespace sort_list_merge
{
	class Solution {
	public:
		ListNode* mergeList(ListNode *head1, ListNode *head2)
		{
			ListNode *newhead;
		
			if(head1 == NULL) 
				return head2; 
			if(head2 == NULL) 
				return head1; 

			if (head1->val < head2->val)
			{
				newhead = head1;
				head1 = head1->next;
			}
			else
			{
				newhead = head2; 
				head2 = head2->next; 
			}

			newhead->next = mergeList(head1, head2);
			return newhead;
		}

		ListNode *sortList(ListNode *head) 
		{
			if (head == NULL)
				return head;
		
			/**	Step 1:	Split the list into 2 parts;
			*	Step 2:	Recurse to sort the 2 parts;
			*	Step 3:	Merge the 2 parts into 1
			****/

			//	Step 1
			ListNode *head1, *head2;
			ListNode *newhead = head;
			ListNode *quick = head;
			ListNode *slow = head;
			while( quick->next != NULL && quick->next->next != NULL )
			{
				quick = quick->next->next;
				slow = slow->next;
			}

			if(slow->next == NULL)
				return head;
			head1 = head;
			head2 = slow->next;
			slow->next = NULL;

			//	Step 2:
			head1 = sortList(head1);
			head2 = sortList(head2);

			//	Step 3:
			newhead = mergeList(head1, head2);
			return newhead;
		}
	};
};

BOOST_AUTO_TEST_SUITE( sort_list_merge_test )
	boost::shared_ptr<sort_list_merge::Solution> solution_(new sort_list_merge::Solution());

	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running sort_list_merge_test case1..." <<std::endl;
		srand( (unsigned)time(NULL));

		std::vector<int> nodes = boost::assign::list_of(1)(2)(3)(4)(5)(6)(7)(8)(9)(10);	
		ListNode *head = createLinkedList(nodes);
		//dispayLinkedList(head);

		head = solution_->sortList(head);
		//dispayLinkedList(head);
		for ( ListNode *idx = head; idx->next != NULL; idx = idx->next )
			BOOST_ASSERT( idx->val <= idx->next->val );

		destoryLinkedlist(head);
	}

BOOST_AUTO_TEST_SUITE_END()	