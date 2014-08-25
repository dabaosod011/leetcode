#ifndef _LEETCODE_HEADER_
#define _LEETCODE_HEADER_

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <boost/test/unit_test.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/assign/list_of.hpp>

using namespace std;

struct Point 
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

/**
**	Linked list
***/
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(std::vector<int> &nodes);
void dispayLinkedList(ListNode* head);
void destoryLinkedlist(ListNode* head);

/**
**	Binary Tree 
***/
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void destoryTree(TreeNode *root);

#endif
