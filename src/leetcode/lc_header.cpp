#include "lc_header.h"

ListNode* createLinkedList(std::vector<int> &nodes)
{
	if (nodes.size() == 0)
		return NULL;

	ListNode *head = new ListNode(nodes[0]);
	ListNode *tmp = head;
	for (int i=1; i< nodes.size(); i++)
	{
		tmp->next = new ListNode(nodes[i]);
		tmp = tmp->next;
	}

	return head;
}

void dispayLinkedList(ListNode* head)
{
	for ( ListNode *idx = head; idx != NULL; idx = idx->next )
		std::cout << idx->val << " " ; 
	std::cout << std::endl;
}

void destoryLinkedlist(ListNode* head)
{
	ListNode *tmp;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		tmp->next = NULL;
		delete tmp;
	}
}

void destoryTree(TreeNode *root)
{
	if (root == NULL)
		return;
	destoryTree(root->left);
	destoryTree(root->right);
	delete root;
}

std::string lc_trim(const std::string &s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && isspace(*it))
		it++;

	std::string::const_reverse_iterator rit = s.rbegin();
	while (rit.base() != it && isspace(*rit))
		rit++;
	
	return std::string(it, rit.base());
}