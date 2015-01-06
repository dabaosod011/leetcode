#include "lc_header.h"

/**
*	https://oj.leetcode.com/problems/merge-k-sorted-lists/
*/

namespace merge_k_sorted_lists
{
	class Solution 
	{
	public:
		ListNode *mergeKLists(vector<ListNode *> &lists) 
		{
			if(lists.size() == 0)
				return NULL;

			if(lists.size() == 1)
				return lists[0];

			ListNode *head = lists[0];			
			for (int i=1; i<lists.size(); i++)
			{
				//	merge head and lists[i]
				ListNode *second = lists[i];
				ListNode *newhead = NULL;

				if(head == NULL)
				{
					newhead = second;
					continue;
				}
				if(second == NULL)
				{
					newhead = head;
					continue;
				}

				if(head->val < second->val)  
				{  
					newhead = head;
					head = head->next;  
				}  
				else  
				{  
					newhead = second;
					second = second->next;  
				}  	
				ListNode *newtail = newhead;  

				while(head!=NULL && second!=NULL)  
				{  
					if(head->val < second->val)  
					{  
						newtail->next = head;  
						head = head->next;  
					}  
					else  
					{  
						newtail->next = second;  
						second = second->next;  
					}  	
					newtail = newtail->next;  
				}

				if(head != NULL)   
					newtail->next = head;   

				if(second != NULL)  
					newtail->next = second;  

				head = newhead;
			}

			return head;				
		}
	};
};

BOOST_AUTO_TEST_SUITE( merge_k_sorted_lists_test )
	boost::shared_ptr<merge_k_sorted_lists::Solution> solution_(new merge_k_sorted_lists::Solution());

BOOST_AUTO_TEST_CASE( case1 ) 	
{
	std::cout << "running merge_k_sorted_lists_test case1..." <<std::endl;

	std::vector<int> nodes1 = boost::assign::list_of(1)(4)(7)(10)(12)(16)(17)(18)(19)(20);	
	std::vector<int> nodes2 = boost::assign::list_of(2)(5)(8)(11)(13)(21)(22)(23)(24)(25);		
	std::vector<int> nodes3 = boost::assign::list_of(3)(6)(9)(12)(15)(26)(27)(28)(29)(30);
	ListNode *head1 = createLinkedList(nodes1);
	ListNode *head2 = createLinkedList(nodes2);
	ListNode *head3 = createLinkedList(nodes3);

	vector<ListNode* > lists;
	lists.push_back(head1);
	lists.push_back(head2);
	lists.push_back(head3);

	ListNode *head = solution_->mergeKLists(lists);
	dispayLinkedList(head);
	destoryLinkedlist(head);
}

BOOST_AUTO_TEST_CASE( case2 ) 	
{
	std::cout << "running merge_k_sorted_lists_test case2..." <<std::endl;

	vector<ListNode* > lists;
	for (int i=0; i < 20000; i++)
	{
		std::vector<int> nodes;
		nodes.push_back(std::rand());
		ListNode *head1 = createLinkedList(nodes);
		lists.push_back(head1);
	}

	ListNode *newhead = solution_->mergeKLists(lists);
	/*dispayLinkedList(newhead);*/
	destoryLinkedlist(newhead);
}

BOOST_AUTO_TEST_CASE( case3 ) 	
{
	std::cout << "running merge_k_sorted_lists_test case3..." <<std::endl;

	ListNode *head = NULL;
	vector<ListNode* > lists;
	lists.push_back(head);

	ListNode *newhead = solution_->mergeKLists(lists);
	dispayLinkedList(newhead);
	destoryLinkedlist(newhead);
}

BOOST_AUTO_TEST_SUITE_END()	