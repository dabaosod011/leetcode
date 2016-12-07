#include "lc_header.h"

/**
 *	https://oj.leetcode.com/problems/add-two-numbers/
 */

namespace add_2_numbers
{
	class Solution
	{
	public:
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

		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
		{
			if (l1 == NULL && l2 == NULL)
				return NULL;
			else if (l1 == NULL && l2 != NULL)
				return reverseList(l2);
			else if(l1 != NULL && l2 == NULL)
				return reverseList(l1);

			ListNode *it1 = l1, *it2 = l2, *result = NULL, *cursor = NULL;
			int sum, additional = 0;
			while (it1 != NULL && it2 != NULL)
			{
				sum = it1->val + it2->val + additional;
				additional = sum / 10;
				if(result == NULL)
				{
					result = new ListNode(sum % 10);
					cursor = result;
				}
				else
				{
					cursor->next = new ListNode(sum % 10);
					cursor = cursor->next;
				}
				
				it1 = it1->next;
				it2 = it2->next;
			}

			if (it1 != NULL)
			{
				for (ListNode *idx=it1; idx!=NULL; idx=idx->next)
				{
					cursor->next = new ListNode( (idx->val + additional) %10 );
					additional = (idx->val + additional) /10;
					cursor = cursor->next;
				}
			}
			else if(it2 != NULL)
			{
				for (ListNode *idx=it2; idx!=NULL; idx=idx->next)
				{
					cursor->next = new ListNode((idx->val + additional) %10);
					additional = (idx->val + additional) /10;
					cursor = cursor->next;
				}
			}
			
			if (additional != 0)
			{
				cursor->next = new ListNode(additional);
				cursor = cursor->next;
			}

			return result;
		}

	};
};


BOOST_AUTO_TEST_SUITE( add_2_numbers_test )
	boost::shared_ptr<add_2_numbers::Solution> solution_(new add_2_numbers::Solution());
	
	BOOST_AUTO_TEST_CASE( case1 ) 	
	{
		std::cout << "running add_2_numbers_test case1..." <<std::endl;

		std::vector<int> num1 = boost::assign::list_of(2)(4)(6)(3)(3);
		std::vector<int> num2 = boost::assign::list_of(5)(4)(6);
		ListNode *L1 = createLinkedList(num1);
		ListNode *L2 = createLinkedList(num2);

		ListNode *result = solution_->addTwoNumbers(L1, L2);
		dispayLinkedList(result);

		destoryLinkedlist(L1);
		destoryLinkedlist(L2);
		destoryLinkedlist(result);
	}

	BOOST_AUTO_TEST_CASE( case2 ) 	
	{
		std::cout << "running add_2_numbers_test case2..." <<std::endl;

		std::vector<int> num1 = boost::assign::list_of(1);
		std::vector<int> num2 = boost::assign::list_of(9)(9);
		ListNode *L1 = createLinkedList(num1);
		ListNode *L2 = createLinkedList(num2);

		ListNode *result = solution_->addTwoNumbers(L1, L2);
		dispayLinkedList(result);

		destoryLinkedlist(L1);
		destoryLinkedlist(L2);
		destoryLinkedlist(result);
	}
BOOST_AUTO_TEST_SUITE_END()	